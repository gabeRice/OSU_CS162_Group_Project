/*******************************************************************************
 * File: Doodlebug.hpp
 * Author:
 * Date:
 * Description: definition file for the critter class
*******************************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter
{
	protected:

	public:
		Doodlebug();
		~Doodlebug();
		char printCritter() const override;

};



#endif



