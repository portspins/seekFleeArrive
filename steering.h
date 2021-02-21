// File : steering.h
// Purpose : Header file for the Steering class whose subclasses will implement the dynamic movement algorithms
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#pragma once

#include "character.h"

class Steering {
protected:
	Steering(); // Default constructor
	Coords linear;	// The steering behavior's calculated linear acceleration
	double angular; // The steering behavior's calculated angular acceleration
	unsigned int steerCode; // Steering code for the plotter
public:
	virtual void calcSteering(Character* ch, Character* targ); // Will be implemented by subclasses to calculate steering
	Coords getLinear();
	double getAngular();
	unsigned int getCode();
	~Steering();
};