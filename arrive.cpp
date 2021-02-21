// File : arrive.cpp
// Purpose : Implementation file for the Steering subclass that will implement the arrive behavior
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#include "arrive.h"

Arrive::Arrive()
{
	steerCode = 5;
}

Arrive::~Arrive()
{
}

/*
 * Seeks the target, then slows when within a certain radius, ultimately stopping when arrived within the desired range
 * @param ch - pointer to the character
 * @param targ - pointer to the target to seek
 */
void Arrive::calcSteering(Character* ch, Character* targ)
{
	linear = targ->getPosition().sub(ch->getPosition()); // Compute direction to target
	double distance = linear.length(); // Calculate the length of that vector
	double desiredSpeed = 0; // Initialize desired speed
	double maxAccel = ch->getMaxAcceleration(); // Get the character's max acceleration

	if (distance < ch->getTargetRadius()) { // If within the target radius
		desiredSpeed = 0;			// Stop
	}
	else if (distance > ch->getSlowRadius()) { // If outside the slow radius
		desiredSpeed = ch->getMaxSpeed(); // Go full speed
	}
	else { // Otherwise, within the slowing zone
		desiredSpeed = ch->getMaxSpeed() * (distance / ch->getSlowRadius()); // Interpolate the speed based on distance from the target
	}

	linear.normalize(); // Convert direction to a unit vector
	Coords desiredVelocity = linear.multiply(desiredSpeed); // Scale to the desired speed
	linear = desiredVelocity.sub(ch->getVelocity());		// Compute the velocity difference
	linear = linear.multiply(1.0 / ch->getTimeToTarget());	// Calculate the needed acceleration

	if (linear.length() > maxAccel) { // If the needed acceleration is beyond the character's capability
		linear.normalize();
		linear = linear.multiply(maxAccel); // Set the acceleration to the character's max acceleration
	}

	angular = 0; // Reset angular acceleration
}