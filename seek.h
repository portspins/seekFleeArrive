// File : seek.h
// Purpose : Header file for a Steering subclass that will implement the seek behavior
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#pragma once

#include "steering.h"

class Seek : public Steering {
public:
	Seek();
	~Seek();
	virtual void calcSteering(Character* ch, Character* targ);
};