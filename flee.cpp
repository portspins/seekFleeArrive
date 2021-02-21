// File : flee.cpp
// Purpose : Implementation file for the Steering subclass that will implement the flee behavior
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#include "flee.h"

Flee::Flee()
{
	steerCode = 4;
}

Flee::~Flee()
{
}

/*
 * Flees the target
 * @param ch - pointer to the character
 * @param targ - pointer to the target to flee from
 */
void Flee::calcSteering(Character* ch, Character* targ)
{
	linear = ch->getPosition().sub(targ->getPosition()); // Compute direction from target
	linear.normalize(); // Convert to a unit vector
	linear = linear.multiply(ch->getMaxAcceleration()); // Scale the acceleration to the character's max acceleration
	angular = 0; // Reset angular acceleration
}
