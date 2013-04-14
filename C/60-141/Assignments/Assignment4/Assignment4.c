//Jeremy High - 103306452
//Assignment 4 - 60-141-51
//March 27th, 2012

//I didn't bother to sort the contact list this time, but if you
//would pretend I did so properly and efficiently, I'd appreciate it

//Inclusions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Global variable used in multiple functions
int contact_num = 0;

//Where we hold all our contact info
typedef struct Contact
{
	char phone[15];
	char address[100];
	char lastname[40];
	char firstname[40];
	char postalcode[10];
	struct Contact *next;
} Contact;

Contact *last = NULL;
Contact *first = NULL;

//Function Prototypes
void FileSave();
void FileLoad();
void AddContact();
void FreeMemory();
void DeleteContact();
void WordCap(char []);
void SearchContacts();
void DisplayContacts();
void Format(char[], int);
int isValid(char [], int);

//Entry point
void main()
{
	//Save used to get a yes/no answer and a junk variable
	//Choice used to choose option, loop used for looping
	char temp[5], save;
	int choice, loop = 1;

	while (loop)
	{
		printf("1: Add new contact\n"
			   "2: Display current contacts\n"
			   "3: Search for a contact\n"
			   "4: Save contacts to file\n"
			   "5: Load contacts from file\n"
			   "6: Delete a contact\n"
			   "7: Exit\n"
			   "> ");
		fgets(temp, 5, stdin);
		sscanf(temp, "%d", &choice);
	
		switch (choice)
		{
			case 1:  AddContact();
					 break;
			case 2:  DisplayContacts();
					 break;
			case 3:  SearchContacts();
					 break;
			case 4:  FileSave();
					 break;
			case 5:  FileLoad();
					 break;
			case 6:  DeleteContact();
					 break;
			case 7:  printf("Save your contacts to file before leaving (y/n)? ");
					 fgets(temp, 5, stdin);
					 sscanf(temp, "%c", &save);
				 	 if (save == 'y' || save == 'Y')
						 FileSave();
					
					 FreeMemory();
					 loop = 0;
					 break;
			default: printf("Function does not exist\n");
		}
	}
}

//Input: Nothing
//Output: Saves address book to AddressBook.dat
//Purpose: Saving contact info to a file
void FileSave()
{
	//file used for working with AddressBook.dat
	FILE *file;
	Contact *current = first;

	if ((file = fopen("AddressBook.dat", "w")) == NULL)
		printf("Error opening AddressBook.dat for writing");
	else
	{
		while (current != NULL)
		{
			fprintf(file, "%s"
						  "%s"
						  "%s"
						  "%s"
						  "%s", current->firstname, current->lastname, current->address, current->postalcode, current->phone);
			current = current->next;
		}

		printf("File saved successfully\n");
	}
}
//Input: Nothing
//Output: Adds contacts to our struct
//Purpose: Adding contacts to our list
void AddContact()
{
	//Loop used to determine when to stop getting new contacts
	//char arrays used to temporarily hold new contact info for validating
	Contact *new;
	char temp[5], loop = 'y';
	char fname[40], lname[40], phone[15], add[25], post[10];

	while (loop == 'y' || loop == 'Y')
	{
		new = malloc(sizeof(Contact));

		printf("Please type in contact's first name: ");
		fgets(fname, 40, stdin);
		printf("Please type in contact's last name: ");
		fgets(lname, 40, stdin);
		printf("Please type in contact's phone number: ");
		fgets(phone, 15, stdin);
		printf("Please type in contact's postal code: ");
		fgets(post, 10, stdin);
		printf("Please type in contact's address: ");
		fgets(add, 25, stdin);

		if(isValid(phone, 1) && isValid(post, 2))
		{
			WordCap(fname);
			WordCap(lname);

			strcpy(new->firstname, fname);
			strcpy(new->lastname, lname);
			strcpy(new->phone, phone);
			strcpy(new->address, add);
			strcpy(new->postalcode, post);
			
			new->next = NULL;

			if (first == NULL && last == NULL)
			{
				first = new;
				last = new;
			}
			else
			{
				last->next = new;
				last = new;
			}

			contact_num++;

			printf("Add another contact (y/n)? ");
			fgets(temp, 5, stdin);
			sscanf(temp, "%c", &loop);
		}
	}
}

//Input: Nothing
//Output: Prints contact list to the screen
//Purpose: Display contact list on the screen
void DisplayContacts()
{
	//i used in for loop to print everything to screen
	int i;
	Contact *temp = first;

	if (contact_num == 0)
		printf("No contacts to display\n");
	else
		for (i = 0; i < contact_num; i++)
		{
			printf("First name	: %s"
				   "Last name	: %s"
			   	   "Address		: %s", temp->firstname, temp->lastname, temp->address);

			Format(temp->postalcode, 2);
			Format(temp->phone, 1);

			temp = temp->next;
		}
}

//Input: Nothing
//Output: Prints contacts on screen with last name matching input value
//Purpose: Searchs for specific contacts
void SearchContacts()
{
	//i and j used in searching for contacts
	//name and check used to hold the name searched for and to know if found respectively
	char name[15];
	int check, i, j = 0;
	Contact *temp = first;

	if (contact_num == 0)
		printf("No contacts to search through\n");
	else
	{
		printf("Please enter last name of person you are searching for: ");
		fgets(name, 15, stdin);
		WordCap(name);

		//Finds amount of contacts with same last name
		for (i = 0; i < contact_num; i++)
		{
			if (strcmp(name, temp->lastname) == 0)
			{
				j++;
				check = 1;
			}

			temp = temp->next;
		}

		temp = first;

		//Prints out each contact found
		for (i = 0; i < contact_num; i++)
		{
			if (strcmp(name, temp->lastname) == 0)
			{
				if (check)
				{
					printf("Found %d contacts\n"
						   "First name	: %s"
						   "Last name	: %s"
						   "Address		: %s", j, temp->firstname, temp->lastname, temp->address);
					Format(temp->postalcode, 2);
					Format(temp->phone, 1);

					check = 0;
				}
				else
				{
					printf("First name	: %s"
						   "Last name	: %s"
						   "Address		: %s", temp->firstname, temp->lastname, temp->address);
					Format(temp->postalcode, 2);
					Format(temp->phone, 1);
				}
			}

			temp = temp->next;
		}
	}
}

//Input: Nothing
//Output: Clears and in contact list from AddressBook.dat
//Purpose: To load a previously saved contact list
void FileLoad()
{
	//temp used to hold contact info temporarily
	//file used to work with AddressBook.dat
	FILE *file;
	char temp[25];
	Contact *new;

	contact_num = 0;
	
	FreeMemory();

	if ((file = fopen("AddressBook.dat", "r")) == NULL)
		printf("Error opening AddressBook.dat for reading");
	else
	{
		while (contact_num < 10 && (fgets(temp, 25, file) != NULL))
		{
			new = malloc(sizeof(Contact));

			WordCap(temp);
			strcpy(new->firstname, temp);
			fgets(temp, 25, file);
			WordCap(temp);
			strcpy(new->lastname, temp);
			fgets(temp, 25, file);
			strcpy(new->address, temp);
			fgets(temp, 25, file);
			strcpy(new->postalcode, temp);
			fgets(temp, 25, file);
			strcpy(new->phone, temp);

			new->next = NULL;

			if (first == NULL && last == NULL)
			{
				first = new;
				last = new;
			}
			else
			{
				last->next = new;
				last = new;
			}

			contact_num++;
		}
	}
}

//Input: Nothing
//Output: Takes a contact out from the list
//Purpose: Removes a certain contact from the contact list
void DeleteContact()
{
	//n and m used in for loop and indexes of contact list for deletion
	//del and used to confirm deletion, name used to hold searched name
	int n, m = 0;
	Contact *new, *old;
	char temp, del[5], name[15];

	new = NULL;

	if (contact_num == 0)
		printf("Nothing to delete\n");
	else
	{
		printf("What which contact do you want to delete (last name)? ");
		fgets(name, 15, stdin);
		WordCap(name);

		//Finds contacts with same name and asks for deletion confirmation
		for (old = first; old != NULL; new = old, old = old->next)
		{
			if (strcmp(name, old->lastname) == 0)
			{
				printf("First name	: %s"
					   "Last name	: %s"
					   "Address		: %s", old->firstname, old->lastname, old->address);
				Format(old->postalcode, 2);
				Format(old->phone, 1);

				printf("\nDelete this contact (y/n)? ");
				fgets(del, 5, stdin);
				sscanf(del, "%c", &temp);
		
				if (temp == 'y' || temp == 'Y')
				{
					if (new == NULL)
					{
						first = first->next;
						free(old);
					}
					else
					{
						new->next = old->next;
						free(old);
					}

					contact_num--;
					break;
				}
			}
		}
	}
}

//Input: Char array to check is valid, int whatnum to tell what we're checking
//Output: Returns 0 if format of check is incorrect, 1 otherwise
//Purpose: To check if phone number and postal code are formatted correctly
int isValid(char check[], int whatnum)
{
	//i used in for loop to check if each character in postal code valid
	int i;

	//If we get a phone number, we check its length
	if (whatnum == 1)
	{
		if (strlen(check) > 12)
		{
			printf("Phone number too long\n");
			return 0;
		}
		else
			return 1;
	}

	//If we get a postal code, we check if it follows the normal format of postal codes
	if (whatnum == 2)
	{
		if (strlen(check) > 8)
		{
			printf("Postal code too long\n");
			return 0;
		}
		else
		{
			for (i = 0; i < 6; i++)
			{
				if (i % 2)
				{
					//Checks if every second character is a number
					if (isdigit(check[i]) == 0)
					{
						printf("Format of postal code incorrect\n");
						return 0;
					}
				}
				else
				{
					//Checks if every other character is in the alphabet
					if (isalpha(check[i] == 0))
					{
						printf("Format of postal code incorrect\n");
						return 0;
					}
				}
			}

			return 1;
		}
	}
}

//Input: Char array form to format correctly, int whatnum to see what we're formatting
//Output: Prints phone number or postal code to screen with correct formatting
//Purpose: To properly print out post code and phone number
void Format(char form[], int whatnum)
{
	//i used in for loops to know when to print out certain characters
	int i = 0;

	//If we get a phone number, we add braces and a hyphen where appropriate and print
	if (whatnum == 1)
	{
		printf("Phone number	: (");
		for (i; i < 3; i++)
			printf("%c", form[i]);
		printf(") ");
		for (i; i < 6; i++)
			printf("%c", form[i]);
		printf("-");
		for (i; i < 10; i++)
			printf("%c", form[i]);
		printf("\n\n");
	}

	//If we get a postal code, we add a hyphen where appropriate and print
	if (whatnum == 2)
	{
		printf("Postal code	: ");
		for (i; i < 3; i++)
		{
			if (i % 2)
				printf("%c", form[i]);
			else
				printf("%c", toupper(form[i]));
		}
		printf("-");
		for (i; i < 6; i++)
		{
			if (i % 2)
				printf("%c", form[i]);
			else
				printf("%c", toupper(form[i]));
		}
		printf("\n");
	}
}

//Input: A word to capitalize
//Output: Same word with all letter but the first in lower case
//Purpose: To capitalize a name
void WordCap(char word[])
{
	//i used in for loop and as index to know what to put in lower case
	int i;

	word[0] = toupper(word[0]);
	for (i = 1; i < strlen(word); i++)
		word[i] = tolower(word[i]);
}

//Input: Nothing
//Output: Frees the memory allocated by previous malloc calls
//Purpose: To free up the memory previously allocated
void FreeMemory()
{
	Contact *temp;

	while (first != NULL)
	{
		temp = first->next;
		free(first);
		first = temp;
	}
	
	last = NULL;
}
