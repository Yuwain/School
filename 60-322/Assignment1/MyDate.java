/************************************************************************
	Written by: 	Jeremy High
	Student ID:		103306452
	Written on:		September 19th, 2013
	
	Simple class used in conjunction with MyDateTest for junit testing 
************************************************************************/

import java.lang.String;

public class MyDate {
	private int month_;
	private int day_;
	private int year_;
	
	private String date_;
		
	public MyDate(String date) throws Exception{
		this.date_ = date;
		
		String[] parts = date.split("/");

		this.day_ = Integer.parseInt(parts[0]);
		this.month_ = Integer.parseInt(parts[1]);
		this.year_ = Integer.parseInt(parts[2]);
		
		if (month_ > 12 || month_ < 1) {
			throw new Exception();
		}
	}
	
	/********************************************************************
	 	Compares this object's date to another to find if current
	 	is an earlier date
	 	
	 	test	- The date we are comparing our current against
	 	
	 	Returns true if this object's date is earlier than the
	 	test object's date
	********************************************************************/
	public boolean lessThan(MyDate test) {
		if (this.year_ < test.year_) {
			return true;
		} else if (this.year_ > test.year_) {
			return false;
		} else {
			if (this.month_ < test.month_) {
				return true;
			} else if (this.month_ > test.month_) {
				return false;
			} else {
				if (this.day_ < test.day_) {
					return true;
				} else {
					return false;
				}
			}
		}
	}
	
	/********************************************************************
	 	Used to represent the MyDate object in string form
		
		Returns a string in the form Month DD, 'YY 
	********************************************************************/
	public String toString() {
        String monthString;
        
        switch (month_) {
            case 1:  monthString = "January";
                     break;
            case 2:  monthString = "February";
                     break;
            case 3:  monthString = "March";
                     break;
            case 4:  monthString = "April";
                     break;
            case 5:  monthString = "May";
                     break;
            case 6:  monthString = "June";
                     break;
            case 7:  monthString = "July";
                     break;
            case 8:  monthString = "August";
                     break;
            case 9:  monthString = "September";
                     break;
            case 10: monthString = "October";
                     break;
            case 11: monthString = "November";
                     break;
            case 12: monthString = "December";
                     break;
            default: monthString = "Invalid month";
            		 break;
        }
        
        return monthString + " " + day_ + ", '" + String.format("%02d", (year_ % 100));
	}
	
	/* Accessors */
	public int getDay() {
		return day_;
	}
	
	public int getMonth() {
		return month_;
	}
	
	public int getYear() {
		return year_;
	}
	
	public String getDate() {
		return date_;
	}
	
	/* Mutators */
	public void setDay(int day) {
		day_ = day;
	}
	
	public void setMonth(int month) {
		month_ = month;
	}
	
	public void setYear(int year) {
		year_ = year;
	}
	
	public void setDate(String date) {
		date_ = date;
	}
}