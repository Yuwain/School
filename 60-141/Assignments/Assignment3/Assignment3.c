//Jeremy High - 103306452
//Assignment 3 - 60-141-51
//March 15th, 2012

//Inclusions
#include <stdio.h>
#include <string.h>

//Global variable used in multiple functions
int contact_num = 0;

//Where we hold all our contact info
struct Contact
{
	char phone[15];
	char address[100];
	char lastname[40];
	char firstname[40];
	char postalcode[10];
}contact[10], temp;

//Function Prototypes
void Sort();
void FileSave();
void FileLoad();
void AddContact();
void DeleteContact();
void WordCap(char []);
void SearchContacts();
void DisplayContacts();
void SortHelp(int, int);
void Format(char[], int);
int isValid(char [], int);


//Entry point
void main()
{
	//Save and junk used to get a yes/no answer and a junk variable
	//Choice used to choose option, loop used for looping
	char save, junk;
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
		scanf("%d", &choice);
	
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
					 scanf("%c%c", &junk, &save);
				 	 if (save == 'y' || save == 'Y')
						 FileSave();
					
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
	//i used in for loop to print each contact
	//file used for working with AddressBook.dat
	int i;
	FILE *file;

	if ((file = fopen("AddressBook.dat", "w")) == NULL)
		printf("Error opening AddressBook.dat for writing");
	else
		for (i = 0; i < contact_num; i++)
			fprintf(file, "%s"
						  "%s"
						  "%s"
						  "%s"
						  "%s", contact[i].firstname, contact[i].lastname, contact[i].address, contact[i].postalcode, contact[i].phone);
}

//Input: Nothing
//Output: Adds contacts to our struct
//Purpose: Adding contacts to our list
void AddContact()
{
	//Loop used to determine when to stop getting new contacts
	//char arrays used to temporarily hold new contact info for validating
	int i;
	char temp[5], loop = 'y';
	char fname[40], lname[40], phone[15], add[25], post[10];

	while (loop == 'y' || loop == 'Y')
	{
		printf("Please type in contact's first name: ");
		fgets(temp, 5, stdin);
		sscanf(temp, "%c", &loop);
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

			strcpy(contact[contact_num].firstname, fname);
			strcpy(contact[contact_num].lastname, lname);
			strcpy(contact[contact_num].phone, phone);
			strcpy(contact[contact_num].address, add);
			strcpy(contact[contact_num].postalcode, post);
			
			contact_num++;

			Sort();

			printf("Add another contact (y/n)? ");
			scanf("%c", &loop);
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

	if (contact_num == 0)
		printf("No contacts to display\n");
	else
		for (i = 0; i < contact_num; i++)
		{
			printf("First name	: %s"
				   "Last name	: %s"
			   	   "Address		: %s", contact[i].firstname, contact[i].lastname, contact[i].address);

			Format(contact[i].postalcode, 2);
			Format(contact[i].phone, 1);
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

	if (contact_num == 0)
		printf("No contacts to search through\n");
	else
	{
		printf("Please enter last name of person you are searching for: ");
		scanf("%*c");
		fgets(name, 15, stdin);
		WordCap(name);

		//Finds amount of contacts with same last name
		for (i = 0; i < contact_num; i++)
		{
			if (strcmp(name,contact[i].lastname) == 0)
			{
				j++;
				check = 1;
			}
		}

		//Prints out each contact found
		for (i = 0; i < contact_num; i++)
		{
			if (strcmp(name,contact[i].lastname) == 0)
			{
				if (check)
				{
					printf("Found %d contacts\n"
						   "First name	: %s"
						   "Last name	: %s"
						   "Address		: %s", j, contact[i].firstname, contact[i].lastname, contact[i].address);
					Format(contact[i].postalcode, 2);
					Format(contact[i].phone, 1);

					check = 0;
				}
				else
				{
					printf("First name	: %s"
						   "Last name	: %s"
						   "Address		: %s", contact[i].firstname, contact[i].lastname, contact[i].address);
					Format(contact[i].postalcode, 2);
					Format(contact[i].phone, 1);
				}
			}
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
	char temp[25];
	FILE *file;

	contact_num = 0;

	if ((file = fopen("AddressBook.dat", "r")) == NULL)
		printf("Error opening AddressBook.dat for reading");
	else
	{
		while (contact_num < 10 && (fgets(temp, 25, file) != NULL))
		{
			WordCap(temp);
			strcpy(contact[contact_num].firstname, temp);
			fgets(temp, 25, file);
			WordCap(temp);
			strcpy(contact[contact_num].lastname, temp);
			fgets(temp, 25, file);
			strcpy(contact[contact_num].address, temp);
			fgets(temp, 25, file);
			strcpy(contact[contact_num].postalcode, temp);
			fgets(temp, 25, file);
			strcpy(contact[contact_num].phone, temp);

			contact_num++;

			Sort();
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
	char del[5], name[15], temp;

	if (contact_num == 0)
		printf("Nothing to delete\n");
	else
	{
		printf("What which contact do you want to delete (last name)? ");
		scanf("%*c");
		fgets(name, 15, stdin);
		WordCap(name);

		//Finds contacts with same name and asks for deletion confirmation
		for (n = 0; n < contact_num; n++)
		{
			if (strcmp(name, contact[n].lastname) == 0)
			{
				printf("First name	: %s"
					   "Last name	: %s"
					   "Address		: %s", contact[n].firstname, contact[n].lastname, contact[n].address);
				Format(contact[n].postalcode, 2);
				Format(contact[n].phone, 1);

				printf("\nDelete this contact (y/n)? ");
				fgets(del, 5, stdin);
				sscanf(del, "%c", &temp);
		
				if (temp == 'y' || temp == 'Y')
				{
					for (m = n; m < contact_num; m++)
					{
						strcpy(contact[m].firstname, contact[m+1].firstname);
						strcpy(contact[m].lastname, contact[m+1].lastname);
						strcpy(contact[m].address, contact[m+1].address);
						strcpy(contact[m].postalcode, contact[m+1].postalcode);
						strcpy(contact[m].phone, contact[m+1].phone);
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
//Output: Contact list stored alphabetically by last name
//Purpose: To know when and how to sort our contact list
void Sort()
{
	//n used to find location to insert contact
	//m used to send to SortHelp, i used as indexes to check against other names
	int n = contact_num-1;
	int m, i = contact_num - 2;

	temp = contact[contact_num-1];

	//If we have two or more contacts in list
	if (contact_num > 1)
	{
		for (i; i >= 0; i--)
		{
			//Checks if each previous name starts with a letter after newest
			if (strcmp(contact[i].lastname, contact[contact_num-1].lastname) > 0)
				n--;

			//If we find a last name that starts with a smaller letter, we send to SortHelp to insert it
			if (strcmp(contact[i].lastname, contact[contact_num-1].lastname) < 0)
			{
				SortHelp(m, n);
				break;
			}

			//If two last names are the same, we do the same with first names
			else if (strcmp(contact[i].lastname, contact[contact_num-1].lastname) == 0)
			{
				//Checks if each previous name starts with a letter bigger than newest
				if(strcmp(contact[i].firstname, contact[contact_num-1].firstname) > 0)
					n--;
						
				//If we find a first name that starts with a smaller letter, insert after it
				if (strcmp(contact[i].firstname, contact[contact_num-1].firstname) < 0)
				{
					SortHelp(m, n);
					break;
				}

				//If first names are also the same, insert after first occurance
				else if (strcmp(contact[i].firstname, contact[contact_num-1].firstname) == 0)
				{
					SortHelp(m, n);
					break;
				}

				//If we hit the start of the array, insert
				else if (strcmp(contact[0].firstname, contact[i].firstname) == 0 && n == 0)
				{
					SortHelp(m, n);
					break;
				}
			}

			//If we hit the start of the array, insert
			else if (strcmp(contact[0].lastname, contact[i].lastname) == 0 && n == 0)
			{
				SortHelp(m, n);
				break;
			}
		}
	}
}

//Input: ints m and n, positions to insert new contact
//Output: Contact list with new contact in correct position
//Purpose: To not have to write the same thing over and over again in Sort
void SortHelp(int m, int n)
{
	for (m = contact_num - 1; m > n; m--)
		contact[m] = contact[m-1];

	contact[m] = temp;
}
