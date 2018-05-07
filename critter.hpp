
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <string>

class Critter
{
	protected:
		Critter ***grid; //triple pointer to the grid the critter dances around on
		std::string critterType; //will hold the type of criteer (ant or doodlebug)
		int stepCounter; //counts the number of steps the critter makes
		int breedSteps; //number of steps a critter needs to take before it can breed
		int breedCounter; //will count the number of steps since the last breeding
		int currentRow; //critters row placement on grid
		int currentColumn; //critters column placement on grid
		int gridSize; //holds the size of the matrix
	
	public:
		Critter(); //default constructor
		Critter(Critter ***gridPtr, int gridSize, int startRow, int startColumn, int startStep = 0); //constructor that will create a critter and place it on board
		~Critter(); //destructor 
		std::string getType(); //getter function for critter type
		bool step(int currentStep); //function that will return true or false if critter able to take step
		virtual bool move() = 0; //virtual move function that will be defined in ant and doodlebug classes for their specific move rules
		virtual bool breed() = 0; //virtual breed function that will be defined in ant and doodlebug classes for their specific breeding rules
};
#endif // !CRITTER_HPP
