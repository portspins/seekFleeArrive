// File : steering.cpp
// Purpose : Implementation file for the Steering class containing the dynamic movement steering behaviors
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#include "steering.h"

/*
 * Class constructor
 */
Steering::Steering()
{
	linear.x = 0;
	linear.z = 0;
	angular = 0;
	steerCode = 0;
}

Steering::~Steering()
{
}

void Steering::calcSteering(Character* ch, Character* targ)
{
	// This method will be implemented by subclasses
}

Coords Steering::getLinear()
{
	return linear;
}

double Steering::getAngular()
{
	return angular;
}

unsigned int Steering::getCode()
{
	return steerCode; // return the steering code
}