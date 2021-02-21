// File : stop.h
// Purpose : Header file for a Steering subclass that will implement the stop behavior
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#pragma once

#include "steering.h"

class Stop : public Steering {
public:
	Stop();
	~Stop();
	virtual void calcSteering(Character* ch, Character* targ);
};