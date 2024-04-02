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
#include "headerMethods.h"









int main() //main function
{

	//declerations	
	int inputDay = 0, inputYear = 0, inputMonth = 0; //input variables
	int input; //input for menu

	 
	std::cout << "Date creation Algorithm \n\n"; //welcome program message with margin


	Date newDate = Date(inputDay, inputYear, inputMonth); //intialize the constructor

	std::string inputString; //declaring input string

	char yesNo; //declaring a chare value




	
	
	
	yesNo = 'n'; //declearation of sentinel


	


	while (yesNo == 'n')
	{
		//ouput date
		std::cout << "Date is: ";
		newDate.toString();
		std::cout << "\n";


		//validate information to user
		std::cout << "Is this information correct? {Y]es (Exit) or [N]o (Make Changes): ";
		std::cin >> inputString;
		yesNo = validYesNo(inputString);


		if (yesNo == 'n') //if the user wishes to change something
		{
			//prompt the user for what they wish to change
			std::cout << "What would you like to change?" << std::endl;
			std::cout << "1. Year-Month-Day\n";
			std::cout << "2. Month-Day \n";
			std::cout << "3. Day \n";
			std::cin >> input;
			input = inputValidMenuChoice(input, 1, 3);

			switch (input) //switch the input to the coressponding values they wish to change.
			{
			case 1:
				newDate = Date(inputDay, inputYear, inputMonth);
				break;
			case 2:
				newDate.setValidInputBools();
				newDate.checkSetMonth(inputMonth);
				newDate.checkMonthSetBool();
				newDate.checkSetDay(inputDay);
				break;
			case 3:
				newDate.setValidInputBools();
				newDate.checkSetDay(inputDay);
				break;
			}

		}


	}


	return 0;

}