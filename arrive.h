// File : arrive.h
// Purpose : Header file for a Steering subclass that will implement the arrive behavior
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#pragma once

#include "steering.h"

class Arrive : public Steering {
public:
	Arrive();
	~Arrive();
	virtual void calcSteering(Character* ch, Character* targ);
};

