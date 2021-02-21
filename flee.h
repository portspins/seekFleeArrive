// File : flee.h
// Purpose : Header file for a Steering subclass that will implement the flee behavior
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#pragma once

#include "steering.h"

class Flee : public Steering {
public:
	Flee();
	~Flee();
	virtual void calcSteering(Character* ch, Character* targ);
};

