// File : steering.h
// Purpose : Header file for the Steering class whose subclasses will implement the dynamic movement algorithms
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#pragma once

#include "character.h"

class Steering {
protected:
	Steering();
	Coords linear;
	double angular;
	unsigned int steerCode;
public:
	virtual void calcSteering(Character* ch, Character* targ);
	Coords getLinear();
	double getAngular();
	unsigned int getCode();
	~Steering();
};