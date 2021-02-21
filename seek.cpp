// File : seek.cpp
// Purpose : Implementation file for the Steering subclass that will implement the seek behavior
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#include "seek.h"

Seek::Seek()
{
	steerCode = 3;
}

Seek::~Seek()
{
}

/*
 * Seeks the target
 * @param ch - pointer to the character
 * @param targ - pointer to the target to seek
 */
void Seek::calcSteering(Character* ch, Character* targ)
{
	linear = targ->getPosition().sub(ch->getPosition()); // Compute direction to target
	linear.normalize(); // Convert to a unit vector
	linear = linear.multiply(ch->getMaxAcceleration()); // Scale the acceleration to the character's max acceleration
	angular = 0; // Reset angular acceleration
}