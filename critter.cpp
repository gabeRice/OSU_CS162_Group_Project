#include "critter.hpp"

#include <string>
#include <cstdlib>
#include <ctime>

/************************************************************************
** Function:	Critter()
** Description:	Default constructor for the Critter class that will set
**				all of the member variables to null
*************************************************************************/

Critter::Critter()
{

}

/************************************************************************
** Function:	Critter(Critter ***gridPtr, int gridSize, int startRow, 
**						int startColumn, int startStep = 0)
**
** Description:	Constructor for the Critter class that will create a
**				type of critter, and place it on the grid that is passed
**				via the ***gridPtr and gridSize parameters along with
**				the parameters for the starting coordinates 
*************************************************************************/

Critter::Critter(Critter ***gridPtr, int gridSize, int startRow, int startColumn, int startStep = 0)
{
	grid = gridPtr; //iniatilizes the internal grid triple pointer to the one that was passed
	this->gridSize = gridSize; //uses the this pointer to set the internal variable to the passed parameter 
	currentRow = startRow; //sets the current row to the passed starting row parameter 
	currentColumn = startColumn; //sets the current column to the passed starting column parameter
	breedCounter = 0; //since no steps have been made yet, sets current steps for breedcounter to 0
	stepCounter = startStep; //sets the step counter to 0

}

/************************************************************************
** Function:	~Critter()
** Description:	Destructor for the Critter class 
*************************************************************************/

Critter::~Critter()
{
	grid = NULL;
}

/************************************************************************
** Function:	string getType()
** Description:	Returns the type of critter object (Ant or Doodlebug)
*************************************************************************/

std::string Critter::getType()
{
	return critterType;
}

/***************************************************************************
** Function:	bool step(int currentStep)
** Description:	Function runs one time steps for the type of critter object
****************************************************************************/

bool Critter::step(int currentStep)
{
	bool moved=true; //internal variable that will be returned to calling function

	if (stepCounter == currentStep)
	{
		stepCounter++; //incremeant the number of steps
		moved = move(); //use the virtual move function to set the moved to true or false
		
		breedCounter++; //increamenat the number of steps since the last breeding
		//check to see if able to breed yet
		if (breedCounter == breedSteps)
		{
			breed();
			breedCounter = 0;
		}
	}

	return moved;
}
