/*******************************************************************************
 * File: Grid.hpp
 * Author:
 * Date: May 4, 2018
 * Description: definition file for the critter class
*******************************************************************************/

#ifndef GRID_HPP 
#define GRID_HPP 

#include "Ant.hpp"
#include "Doodlebug.hpp"

class Grid
{
	private:
		Critter*** Field;
		int numberCyclesToRun;
		int cyclesAlreadyRan;
		int numAnts;
		int numDoodlebugs;
		//numRows and numCols are static so the values may be acquired from
		//user and initialized before a Grid object is instantiated.
		//The static getRowsandCols() function does this.
		int numRows;
		int numCols;

	public:
		//constructors and destructor
		Grid();
		Grid(int,int,int,int);
		~Grid();
		
		//getters & setters
/*		int getNumberCyclesToRun() const;
		int getCyclesAlreadyRan() const;
		int getNumAnts() const;
		int getNumDoodlebugs() const;
		static int getNumRows();
		static int getNumCols();
		void setNumberCyclesToRun();
		void setCyclesAlreadyRan();
		void setNumAnts();
		void setNumDoodlebugs();
		static void setNumRows;
		static void setNumCols;

		//other functions
		void resolveDoodlebugs();
		void resolveAnts();
*/

};



#endif
