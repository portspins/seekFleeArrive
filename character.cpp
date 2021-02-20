// File : character.cpp
// Purpose : Implementation file for the Character class
// Author : Matthew Hise (mrh0036@uah.edu)

#include "character.h"

/*
 * Default constructor
 */
Character::Character()
{
	this->steer = 1; // Set the initial steering to STOP
}

/*
 * Parametrized constructor
 * @param id - an integer to set the character's id
 */
Character::Character(int id)
{
	Charater();
	this->id = id;
}

Character::~Character()
{
}

/*
 * Sets the id for a character
 * @param id - an integer to set the character's id
 */
void Character::setId(int id)
{
	this->id = id;
}

/*
 * Gets the id for a character
 * @return - the character's id
 */
int Character::getId()
{
	return id;
}

/*
 * Sets the steering behavior for a character
 * @param steer - an integer to set the character's steering behavior
 */
void Character::setSteer(int steer)
{
	this->steer = steer;
}

/*
 * Gets the steering behavior for a character
 * @return - the character's steering behavior as an integer
 */
int Character::getSteer()
{
	return steer;
}

/*
 * Sets the character's position
 * @param x - a double to set the character's x coordinate
 * @param z - a double to set the character's z coordinate
 */
void Character::setPosition(double x, double z)
{
	position.x = x;
	position.z = z;
}

/*
 * Gets the character's position
 * @return - the character's position as a Coords struct
 */
Coords Character::getPosition()
{
	return position;
}

/*
 * Sets the character's linear velocity
 * @param x - a double to set the character's linear velocity x coordinate
 * @param z - a double to set the character's linear velocity z coordinate
 */
void Character::setVelocity(double x, double z)
{
	velocity.x = x;
	velocity.z = z;
}

/*
 * Gets the character's linear velocity
 * @return - the character's linear velocity as a Coords struct
 */
Coords Character::getVelocity()
{
	return velocity;
}

/*
 * Sets the character's linear acceleration
 * @param x - a double to set the character's linear acceleration x coordinate
 * @param z - a double to set the character's linear acceleration z coordinate
 */
void Character::setAcceleration(double x, double z)
{
	acceleration.x = x;
	acceleration.z = z;
}

/*
 * Gets the character's linear acceleration
 * @return - the character's linear acceleration as a Coords struct
 */
Coords Character::getAcceleration()
{
	return acceleration;
}

/*
 * Sets the character's orientation
 * @param r - the character's orientation as a double
 */
void Character::setOrientation(double r)
{
	orientation = r;
}

/*
 * Gets the character's orientation
 * @return - the character's orientation
 */
double Character::getOrientation()
{
	return orientation;
}

/*
 * Sets the character's rotation
 * @param r - the character's rotation
 */
void Character::setRotation(double r)
{
	rotation = r;
}

/*
 * Gets the character's rotation
 * @return - the character's rotation
 */
double Character::getRotation()
{
	return rotation;
}

/*
 * Sets the character's angular acceleration
 * @param r - the character's angular acceleration
 */
void Character::setAngular(double r)
{
	angular = r;
}

/*
 * Gets the character's angular acceleration
 * @return - the character's angular acceleration
 */
double Character::getAngular()
{
	return angular;
}

/*
 * Sets the character's maximum speed
 * @param r - the character's max speed
 */
void Character::setMaxSpeed(double m)
{
	maxSpeed = m;
}

/*
 * Gets the character's maximum speed
 * @return - the character's max speed
 */
double Character::getMaxSpeed()
{
	return maxSpeed;
}

/*
 * Sets the character's maximum acceleration
 * @param r - the character's max acceleration
 */
void Character::setMaxAcceleration(double m)
{
	maxAcceleration = m;
}

/*
 * Gets the character's maximum acceleration
 * @return - the character's max acceleration
 */
double Character::getMaxAcceleration()
{
	return maxAcceleration;
}

/*
 * Sets the character's target
 * @param t - the character's target
 */
void Character::setTarget(int t)
{
	target = t;
}

/*
 * Gets the character's target
 * @return - the character's target
 */
int Character::getTarget()
{
	return target;
}

/*
 * Sets the character's target radius
 * @param r - the character's target radius
 */
void Character::setTargetRadius(double r)
{
	targetRadius = r;
}

/*
 * Gets the character's target radius
 * @return - the character's target radius
 */
double Character::getTargetRadius()
{
	return targetRadius;
}

/*
 * Sets the character's slow radius
 * @param r - the character's slow radius
 */
void Character::setSlowRadius(double r)
{
	slowRadius = r;
}

/*
 * Gets the character's slow radius
 * @return - the character's slow radius
 */
double Character::getSlowRadius()
{
	return slowRadius;
}

/*
 * Sets the character's desired time to target speed
 * @param t - the character's desired time to target speed
 */
void Character::setTimeToTarget(double t)
{
	timeToTarget = t;
}

/*
 * Gets the character's desired time to target speed
 * @return - the character's desired time to target speed
 */
double Character::getTimeToTarget()
{
	return timeToTarget;
}
