/*******************************************************************************
 * File: Ant.hpp
 * Author:
 * Date:
 * Description: definition file for the critter class
*******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant : public Critter
{
	protected:

	public:
		~Ant() override;
		char printCritter() const override;

};



#endif

