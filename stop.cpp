// File : stop.cpp
// Purpose : Implementation file for the Steering subclass that will implement the stop behavior
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#include "stop.h"

Stop::Stop()
{
	steerCode = 1;
}

Stop::~Stop()
{
}

/*
 * Stops the character
 * @param ch - pointer to the character
 * @param targ - will be NULL for this behavior
 */
void Stop::calcSteering(Character* ch, Character* targ)
{
	ch->setVelocity(0.0, 0.0);	// set the character's linear velocity to 0
	ch->setRotation(0.0);		// set the character's angular velocity to 0
}
