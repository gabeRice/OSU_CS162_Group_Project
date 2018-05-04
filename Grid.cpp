/*******************************************************************************
 * File: Grid.cpp
 * Author:
 * Date:
 * Description: implementation file for the Grid class
*******************************************************************************/

#include "Grid.hpp"
#include "helperFunctions.hpp"

#include <cstddef>

/*******************************************************************************
 *					Grid::Grid()
 * Description: default constructor for a grid object.
*******************************************************************************/
Grid::Grid()
{
	//set numAnts and numDoodlebugs to default values specified in assignment
	//instructions.
	this->numAnts = 100;
	this->numDoodlebugs = 5;
	this->cyclesAlreadyRan = 0;
	this->numRows = 20;
	this->numCols = 20;
	
	//allocate all the memory needed for the theField
	//do not actually instantiate any objects. Just set all pointers to 
	//null
	this->Field = new Critter**[numRows];
	for (int i = 0 ; i < this->numRows ; i ++)
	{
		this->Field[i] = new Critter*[numCols];
		for (int j = 0; j < this->numCols; j++)
		{
			this->Field[i][j] = NULL;
		}
	}

	//randomly place 100 Ants in the array.
	int numAntsPlacedInField = 0;
	while(numAntsPlacedInField < numAnts)
	{
		//generate a random row and column to attempt to place an Ant at
		int row = randomIntGenerator(0,this->numRows-1);
		int column = randomIntGenerator(0,this->numCols-1);
		
		//if randomly chosen spot is empty, place an Ant object there
		if(Field[row][column] == NULL)
		{
			Field[row][column] = new Ant;
			numAntsPlacedInField++;
		}
	}

	//randomly place 5 Doodlebugs in the array.
	int numDoodlebugsPlacedInField = 0;
	while(numDoodlebugsPlacedInField < numDoodlebugs)
	{
		//generate a random row and column to attempt to place a Doodlebug in
		int row = randomIntGenerator(0,this->numRows-1);
		int column = randomIntGenerator(0,this->numCols-1);
		
		//if randomly chosen spot is empty, place an Doodlebug object there
		if(Field[row][column] == NULL)
		{
			Field[row][column] = new Doodlebug;
			numDoodlebugsPlacedInField++;
		}
	}
}
/*******************************************************************************
 *					Grid::Grid(int,int,int,int)
 * Description: A constructor that takes four ints as arguments. Sets the
 * number of rows, number of columns, number of ants, and number of doodlebugs
 * that will make up the Field at beginning.
*******************************************************************************/
Grid::Grid(int numRows, int numCols, int numAnts, int numDoodlebugs)
{
	//set numAnts and numDoodlebugs to input values from user
	this->numAnts = numAnts;
	this->numDoodlebugs = numDoodlebugs;
	this->cyclesAlreadyRan = 0;
	this->numRows = numRows;
	this->numCols = numCols;

	
	
	//allocate all the memory needed for the theField
	//do not actually instantiate any objects. Just set all pointers to NULL
	this->Field = new Critter**[this->numRows];
	for (int i = 0 ; i < this->numRows ; i ++)
	{
		this->Field[i] = new Critter*[this->numCols];
		for (int j = 0; j < this->numCols; j++)
		{
			this->Field[i][j] = NULL;
		}
	}
	
	//if more Critters have been requested than there are available spots,
	//implicit return to end function
	if( (this->numRows * this->numCols) < 
		(this->numAnts + this->numDoodlebugs))
	{
		return;
	}
	else
	{

		//randomly place 100 Ants in the array.
		int numAntsPlacedInField = 0;
		while(numAntsPlacedInField < this->numAnts)
		{
			//generate a random row and column to attempt to place an Ant at
			int row = randomIntGenerator(0,this->numRows-1);
			int column = randomIntGenerator(0,this->numCols-1);
			
			//if randomly chosen spot is empty, place an Ant object there
			if(Field[row][column] == NULL)
			{
				Field[row][column] = new Ant;
				numAntsPlacedInField++;
			}
		}

		//randomly place 5 Doodlebugs in the array.
		int numDoodlebugsPlacedInField = 0;
		while(numDoodlebugsPlacedInField < this->numDoodlebugs)
		{
			//generate a random row and column to attempt to place a
			//Doodlebug into
			int row = randomIntGenerator(0,this->numRows-1);
			int column = randomIntGenerator(0,this->numCols-1);
			
			//if randomly chosen spot is empty, place an Doodlebug object
			//there
			if(Field[row][column] == NULL)
			{
				Field[row][column] = new Doodlebug;
				numDoodlebugsPlacedInField++;
			}
		}
	}
}
	

/*******************************************************************************
 *					Grid::~Grid()
 * Description: destructor for a grid object. Deallocates any dynamic memory
 * that is still allocated for Critter objects
*******************************************************************************/
Grid::~Grid()
{
	//cycle through each critter in the field. if the pointer doesn't already
	//point to NULL, the critter must be deallocated.
	for(int i = 0; i < numRows; i ++)
	{
		for (int j = 0; j < numCols; j++)
		{
			delete this->Field[i][j];
			this->Field[i][j] = NULL;
		}
		delete [] this->Field[i];
		this->Field[i] = NULL; 
	}
	delete [] this->Field;
	this->Field = NULL;
}
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/
/*******************************************************************************
 *
 * Description:
*******************************************************************************/

