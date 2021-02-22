// File : character.h
// Purpose : Header file for the Character class
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#pragma once

class Steering;

struct Coords {
	double x;
	double z;
	void normalize();
	double length();
	Coords multiply(double n);
	Coords add(Coords addend);
	Coords sub(Coords subtra);
};

class Character {
private:
	int id;			// The character's id
	Steering *steering; // The character's steering behavior
	Coords position; // The character's current position
	Coords velocity; // The character's current linear velocity
	Coords acceleration; // The character's current linear acceleration
	double orientation;	 // The character's current orientation
	double rotation;	 // The character's current angular velocity
	double angular;		 // The character's current angular acceleration
	double maxSpeed;	 // The character's maximum speed
	double stopSpeed;	// The character's minimum speed
	double maxAcceleration; // The character's maximum acceleration
	Character *target;		// The character's current target
	double targetRadius;	// The character's desired proximity to target
	double slowRadius;		// The character's distance from target to begin slowing down
	double timeToTarget;	// The character's desired time until it reaches desired speed

public:
	Character(int id); // Parametrized class constructor
	~Character();	   // Destructor
	void setId(int id);
	int getId();
	void setSteer(Steering* steer);
	unsigned int getSteer();
	void setPosition(double x, double z);
	Coords getPosition();
	void setVelocity(double x, double z);
	Coords getVelocity();
	void setAcceleration(double x, double z);
	Coords getAcceleration();
	void setOrientation(double r);
	double getOrientation();
	void setRotation(double r);
	double getRotation();
	void setAngular(double r);
	double getAngular();
	void setMaxSpeed(double m);
	double getMaxSpeed();
	void setMaxAcceleration(double m);
	double getMaxAcceleration();
	void setTarget(Character *targ);
	void setTargetRadius(double r);
	double getTargetRadius();
	void setSlowRadius(double r);
	double getSlowRadius();
	void setTimeToTarget(double t);
	double getTimeToTarget();
	void update(double deltaTime); // Update the character at each timestep
};