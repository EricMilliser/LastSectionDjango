/*
Author:  Eric Milliser
Date written: 04/1/24
Assignment:   Module2 exercise1 part1
Short Desc:  Prompt user to enter a year, month and day, validate it with try-catch statements
			Then output it and prompt the user to change the values.
*/



#include <iostream>
#include <iomanip>
#include <string>



//ENUM to store the values of the months.
enum MONTHS {
	JAN, //Each value name is the respective abbreviation
	FEB,
	MAR,
	APR,
	MAY,
	JUN,
	JUL,
	AUG,
	SEP,
	OCT,
	NOV,
	DEC
};


//function to return a month value from an integer
MONTHS intToMonth(int input)
{
	switch (input) //each value is the respecive number of the month in this switch-case
	{
	case 1:
		return JAN;
		break;
	case 2:
		return FEB;
		break;
	case 3:
		return MAR;
		break;
	case 4:
		return APR;
		break;
	case 5:
		return MAY;
		break;
	case 6:
		return JUN;
		break;
	case 7:
		return JUL;
		break;
	case 8:
		return AUG;
		break;
	case 9:
		return SEP;
		break;
	case 10:
		return OCT;
		break;
	case 11:
		return NOV;
		break;
	case 12:
		return DEC;
		break;
	}
}



std::string enumToString(MONTHS input) //This is a print/return statement that returns the full month based on the Enum

{
	switch (input)
	{
	case JAN:
		return "January";
		break;
	case FEB:
		return "February";
		break;
	case MAR:
		return "March";
		break;
	case APR:
		return "April";
		break;
	case MAY:
		return "May";
		break;
	case JUN:
		return "June";
		break;
	case JUL:
		return "July";
		break;
	case AUG:
		return "August";
		break;
	case SEP:
		return "September";
		break;
	case OCT:
		return "October";
		break;
	case NOV:
		return "November";
		break;
	case DEC:
		return "December";
		break;
	}
}



int inputValid(int input) //input validation that checks to see if the inputted value caused a input failure
{
	bool failed = std::cin.fail(); //setting the value to input failure

	while (failed == true) //while the input has failed
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Value entered needs to be a number. Please try again." << std::endl;
		std::cin >> input;
		failed = std::cin.fail();
	}

	return input;
}


//this is the same as my previous inputValidation, only it is entirely meant for menu options in my programs.
int inputValidMenuChoice(int input, int param1, int param2) //includes 2 formal parameters, param1 for lowest value and param2 for highest value
{
	bool failed = std::cin.fail();

	while (failed == true || (input < param1 || input > param2))
	{

		if (failed == true)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Value entered needs to be a number. Please try again." << std::endl;
			std::cin >> input;
			failed = std::cin.fail();
		}

		if (input < param1 || input > param2)
		{
			std::cout << "Please choose a number (1-3): ";
			std::cin >> input;
			failed = std::cin.fail();
		}
	}

	return input;
}


//this is a function that takes a string input and validates to see if the user entered yes or no
char validYesNo(std::string input)
{
	char yesNo = tolower(input[0]);

	while (yesNo != 'y' && yesNo != 'n')
	{
		std::cout << "Please enter [Y]es (to exit) or [N]o (to make changes): ";
		std::cin >> input;
		char yesNo = tolower(input[0]);
	}


	return yesNo;
}






class Date //The class Date for the date values
{
	//private declarations
private:
	MONTHS month = JAN; //month enumn for the mont
	int day = 1; //int for day
	int year = 1900; //int for year
 	bool leapYear = false; //bool to validate leap yaer
	bool valid1, valid2, valid3 = false; //bool for validatating inputs
	bool oddMonth, evenMonth, February = false; //bools for displaying the days of the month that one can enter


	//public functions and declarations
public:
	
	void setYear(int inputYear) //set function for year
	{
		year = inputYear;
	}


	
	
	
	void setMonth(MONTHS input) //set function for month
	{
		month = input;
	}



	void setDay(int inputDay) //set function for day
	{
		day = inputDay;
	}


	void setLeap(int year) //set fucntion to determine if inputted year is a leap year
	{
		
		if (((year % 4) <= 0 && ((year % 100) != 0)) || (((year % 400) == 0) && ((year % 100) == 0)))
		{
			leapYear = true;
		}
	}


	void checkMonthSetBool() //function that checks the month and sets the corrospoding bool value to what kind of month it is for the amount of days
	{
		
		if (((((month+1) % 2) != 0)) && month < AUG)
		{
			oddMonth = true;

		}
		
		if ((month >= AUG) && ((month + 1) % 2) == 0)
		{
			oddMonth = true;
		}



		
		if ((((month+1) % 2 == 0) && month != FEB) && month < AUG)
		{
			evenMonth = true;
		}

		if ((month >= AUG) && ((month + 1) % 2) != 0)
		{
			evenMonth = true;
		}




		if (month == FEB)
		{
			February = true;
		}

		
	}

	void setValidInputBools() // function to set the bools to invalid for resetting everything easily
	{
		valid1 = false;
		valid2 = false;
		valid3 = false;
	}






	void checkSetYear(int inputYear) //set function for year that takes an input, and validates it
	{

		std::cout << "Enter the year (1900-2020): ";
		std::cin >> inputYear;
		inputYear = inputValid(inputYear);


		try //try input year within the range required of 1900-2020
		{
			if (inputYear < 1900 || inputYear > 2020)
			{
				throw(inputYear);
			}
			else
			{
				setYear(inputYear);
				valid1 = true;
			}
		}
		catch (int num1) //if the function had thrown an error, catch it here and set valid to false
		{
			std::cout << "Year must be in between (1900-2020)" << std::endl;
			std::cout << "Your input was: " << num1 << std::endl;
			valid1 = false;
		}
	}



	void checkSetMonth(int inputMonth) //set function for month that takes an input, and checks for validation
	{
		
		MONTHS monthPlaceholder;
		
		std::cout << "Enter the month (1-12): ";
		std::cin >> inputMonth;
		inputMonth = inputValid(inputMonth);

		try
		{
			
			if (inputMonth < 1 || inputMonth > 12) //try function to see if the month is within the range of 1-12
			{
				throw(inputMonth);
			}
			else
			{
				monthPlaceholder = intToMonth(inputMonth);
				setMonth(monthPlaceholder);
				valid2 = true;
			}
		}
		catch (int num2) //if the function had thrown an error, catch it here and set valid to false
		{
			std::cout << "Month must be (1-12)" << std::endl;
			std::cout << "Your input was: " << num2 << std::endl;
			valid2 = false;
		}
	}

	void checkSetDay(int inputDay) //set funtion for day that checks that first outputs the amount of days one can inter from the bool that is true and then ouputs that, takes in an input, and checks based on the parameters
	{

		//each of these separate parts has a try catch block corrospoinding to the month and amount of days
		if (leapYear == true && February == true) //if statement for validating a leap year day input on february
		{
			std::cout << "Enter the day (1-29): ";
			std::cin >> inputDay;
			inputDay = inputValid(inputDay);

			try
			{
				if (inputDay < 1 || inputDay > 29)
				{
					throw(inputDay);
				}
				else
				{
					setDay(inputDay);
					valid3 = true;
				}
			}
			catch (int num3)
			{
				std::cout << "Invalid Value - there are only 29 days in " << enumToString(month) << " when it is leap year" << std::endl;
				std::cout << "Your input was: " << num3 << std::endl;
				valid3 = false;
			}
		}

		if (leapYear == false && February == true) //if for february on a standard year
		{

			std::cout << "Enter the day (1-28): ";
			std::cin >> inputDay;
			inputDay = inputValid(inputDay);


			try
			{
				if (inputDay < 1 || inputDay > 28)
				{
					throw(inputDay);
				}
				else
				{
					setDay(inputDay);
					valid3 = true;
				}
			}
			catch (int num3)
			{
				std::cout << "Invalid Value - there are only 28 days in " << enumToString(month) << " when it is not leap year" << std::endl;
				std::cout << "Your input was: " << num3 << std::endl;
				valid3 = false;
			}
		}


		if (oddMonth == true) // if statement for a odd year
		{
			std::cout << "Enter the day (1-31): ";
			std::cin >> inputDay;
			inputDay = inputValid(inputDay);

		


			try
			{
				if (inputDay < 1 || inputDay > 31)
				{
					throw(inputDay);
				}
				else
				{
					setDay(inputDay);
					valid3 = true;
				}
			}
			catch (int num3)
			{
				std::cout << "Invalid Value - there are only 31 days in" << enumToString(month) << std::endl;
				std::cout << "Your input was: " << num3 << std::endl;
				valid3 = false;
			}
		}


		if (evenMonth == true) //if statement for a even year
		{

			std::cout << "Enter the day (1-30): ";
			std::cin >> inputDay;
			inputDay = inputValid(inputDay);


			try
			{
				if (inputDay < 1 || inputDay > 30)
				{
					throw(inputDay);
				}
				else
				{
					setDay(inputDay);
					valid3 = true;
				}
			}
			catch (int num3)
			{
				std::cout << "Invalid Value - there are only 30 days in " << enumToString(month) << std::endl;
				std::cout << "Your input was: " << num3 << std::endl;
				valid3 = false;
			}
		}

	}


	int getYear() //output get function for year
	{
		return year;
	}


	std::string getMonth() //output get function for a month from the enum to string
	{
		return enumToString(month);
	}

	int getDay() //output get function for a day
	{
		return day;
	}





	Date(int inputDay, int inputYear, int inputMonth) // constructor of the class
	{
		//declarations of variables to intiate each loop at least once
		setValidInputBools();
		leapYear = false;




		while (valid1 == false) //valid1 for year
		{
			checkSetYear(inputYear);
		}

		setLeap(year); //setting leap year check

		while (valid2 == false) //valid2 for month
		{
			checkSetMonth(inputMonth);
		}
		

		checkMonthSetBool(); //setting the month bool

		
		while (valid3 == false) //valid3 for day
		{
			checkSetDay(inputDay);
		}

	}


	void toString() //function that prints out the month
	{
		std::cout << getMonth() << " " << getDay() << ", " << getYear();
	}



};