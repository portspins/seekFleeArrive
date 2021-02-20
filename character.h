// File : character.h
// Purpose : Header file for the Character class
// Author : Matthew Hise (mrh0036@uah.edu)

#pragma once

struct Coords {
	double x;
	double z;
	void normalize();
	double length();
};

class Character {
private:
	int id;			// The character's id
	int steer;		// The character's steering behavior
	Coords position; // The character's current position
	Coords velocity; // The character's current linear velocity
	Coords acceleration; // The character's current linear acceleration
	double orientation;	 // The character's current orientation
	double rotation;	 // The character's current angular velocity
	double angular;		 // The character's current angular acceleration
	double maxSpeed;	 // The character's maximum speed
	double maxAcceleration; // The character's maximum acceleration
	int target;			 // The character's current target
	double targetRadius;	// The character's desired proximity to target
	double slowRadius;		// The character's distance from target to begin slowing down
	double timeToTarget;	// The character's desired time until it reaches desired speed

public:
	Character();			// Class constructor
	Character(int id);		// Parametrized class constructor
	~Character();			// Destructor
	void setId(int id);
	int getId();
	void setSteer(int steer);
	int getSteer();
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
	void setTarget(int t);
	int getTarget();
	void setTargetRadius(double r);
	double getTargetRadius();
	void setSlowRadius(double r);
	double getSlowRadius();
	void setTimeToTarget(double t);
	double getTimeToTarget();

};