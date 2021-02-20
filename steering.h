// File : steering.h
// Purpose : Header file for the Steering class containing the dynamic movement steering behaviors
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#pragma once

class Steering {
public:
	Stop();
	~Stop();
	static void immediateStop(Character* ch);
	static void seek(Character* ch, Character* targ);
	static void flee(Character* ch, Character* targ);
	static void arrive(Character* ch, Character* targ);
};