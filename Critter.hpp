/*******************************************************************************
 * File: Critter.hpp
 * Author:
 * Date:
 * Description: definition file for the critter class
*******************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter
{
	protected:
		int cyclesAlive;

	public:
		virtual ~Critter();
		virtual char printCritter() const;
};



#endif


