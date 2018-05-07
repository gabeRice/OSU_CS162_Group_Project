/*******************************************************************************
 * File: main.cpp
 * Author:
 * Date:
 * Description:
*******************************************************************************/

#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "Grid.hpp"
#include "helperFunctions.hpp"

#include <cstddef>


//additional function headers
void getSetupFromUser(int&,int&,int&,int&);
//void displayWelcome();

int main()
{
	clearTheScreen();
	//displayWelcome();
	//initialize variables for size of array, number of bugs
	int numRows, numCols, numAnts, numDoodlebugs;

	//get input from user
	getSetupFromUser(numRows,numCols,numAnts,numDoodlebugs);
	Grid hereWeGoAgain(numRows,numCols,numAnts,numDoodlebugs);
	hereWeGoAgain.printGrid();
	return 0;
}

/*******************************************************************************
 *				void getSetupFromUser(int&,int&,int&,int&)
 * Description: Takes 4 references to ints as variables. Gets input from the
 * for how many rows and columns they would like to make the Field. Then
 * gets how many ants and how many doodlebugs they would like to place on the
 * Field at start. Sets argument variables to the input values.
*******************************************************************************/
void getSetupFromUser(int &numRows, int &numCols, int &numAnts, 
				int &numDoodlebugs)
{
	std::string inputString = "";
	bool gotAGoodInt = false;		//flag variable to use for validation
	int convertedString = 0;
	//maxAnts and maxDoodlebugs must be determined at runtime. It depends on
	//size of the grid.
	int maxAnts = 0;
	int maxDoodlebugs = 0;

	int minAnts = 1;
	int minDoodlebugs = 1;

	const int MAX_ROWS = 100,
			MAX_COLS = 140,
			MIN_ROWS = 2,
			MIN_COLS = 2;


	//get number of rows
	do
	{

		clearTheScreen();
		std::cout << "How many rows will there be on this simulation\n";
		std::cout << "of the Predator-Prey game?" << std::endl;
		std::cout << "Enter an integer between " << MIN_ROWS;  
		std::cout << " and " << MAX_ROWS << "." << std::endl;

		getline(std::cin,inputString);

		if(convertStringToInt(inputString,convertedString,MIN_ROWS,MAX_ROWS))
		{
			numRows = convertedString;
			gotAGoodInt = true;
		}
		else
		{
			gotAGoodInt = false;
			std::cout << "Invalid input." << std::endl;
			pause();
		}
	} while(!gotAGoodInt);

	//get number of columns
	do
	{

		clearTheScreen();
		std::cout << "How many columns will there be on this simulation\n";
		std::cout << "of the Predator-Prey game?" << std::endl;
		std::cout << "Enter an integer between " << MIN_COLS;  
		std::cout << " and " << MAX_COLS << "." << std::endl;

		getline(std::cin,inputString);

		if(convertStringToInt(inputString,convertedString,MIN_COLS,MAX_COLS))
		{
			numCols = convertedString;
			gotAGoodInt = true;
		}
		else
		{
			gotAGoodInt = false;
			std::cout << "Invalid input." << std::endl;
			pause();
		}
	} while(!gotAGoodInt);
	
	//get number of Ants. Note number of ants may not exceed number of
	//total spaces.
	maxAnts = numCols * numRows - 1;
	
	do
	{
		clearTheScreen();
		std::cout << "How many ants will there be in this simulation\n";
		std::cout << "of the Predator-Prey game?" << std::endl;
		std::cout << "Enter an integer between " << minAnts;  
		std::cout << " and " << maxAnts << "." << std::endl;

		getline(std::cin,inputString);

		if(convertStringToInt(inputString,convertedString,minAnts,maxAnts))
		{
			numAnts = convertedString;
			gotAGoodInt = true;
		}
		else
		{
			gotAGoodInt = false;
			std::cout << "Invalid input." << std::endl;
			pause();
		}
	} while(!gotAGoodInt);

	//get number of Ants. Note number of ants may not exceed number of
	//total spaces minus the number of Ants.
	maxDoodlebugs = numCols * numRows - numAnts;
	
	do
	{

		clearTheScreen();
		std::cout << "How many doodlebugs will there be in this simulation\n";
		std::cout << "of the Predator-Prey game?" << std::endl;
		std::cout << "Enter an integer between " << minDoodlebugs;  
		std::cout << " and " << maxDoodlebugs << "." << std::endl;

		getline(std::cin,inputString);

		if(convertStringToInt(inputString,convertedString,minDoodlebugs,maxDoodlebugs))
		{
			numDoodlebugs = convertedString;
			gotAGoodInt = true;
		}
		else
		{
			gotAGoodInt = false;
			std::cout << "Invalid input." << std::endl;
			pause();
		}
	} while(!gotAGoodInt);



}
