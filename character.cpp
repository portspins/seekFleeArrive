// File : character.cpp
// Purpose : Implementation file for the Character class
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)

#include "character.h"
#include "stop.h"
#include <cmath>

/*
 * Parametrized constructor
 * @param id - an integer to set the character's id
 */
Character::Character(int id)
{
	this->id = id;
	steering = new Stop(); // Set the initial steering behavior to STOP
	position.x = 0;
	position.z = 0;
	velocity.x = 0;
	velocity.z = 0;
	acceleration.x = 0;
	acceleration.z = 0;
	orientation = 0;
	rotation = 0;
	angular = 0;
	maxSpeed = 0;
	stopSpeed = 0.01;
	maxAcceleration = 0;
	target = NULL;
	targetRadius = 4.0;
	slowRadius = 25.0;
	timeToTarget = 1.0;
}

Character::~Character()
{
	delete steering;
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
 * @param steer - a steering behavior
 */
void Character::setSteer(Steering *steer)
{
	this->steering = steer;
}

/*
 * Gets the steering behavior code for a character
 * @return - a steering behavior code
 */
unsigned int Character::getSteer()
{
	return steering->getCode();
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
void Character::setTarget(Character* targ)
{
	target = targ;
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

/*
 * Updates the character's attributes according to Newton-Euler-1
 * @param deltaTime - the time between updates of the character's data
 */
void Character::update(double deltaTime)
{
	steering->calcSteering(this, target);
	position = position.add(velocity.multiply(deltaTime)); // Update the character's position
	orientation += (rotation * deltaTime);	// Update the character's orientation

	velocity = velocity.add(steering->getLinear().multiply(deltaTime)); // Update the character's linear velocity
	rotation += (steering->getAngular() * deltaTime); // Update the character's angular velocity

	if (velocity.length() > maxSpeed) {
		velocity.normalize();
		velocity = velocity.multiply(maxSpeed);
	}

	if (velocity.length() < stopSpeed) {
		velocity = velocity.multiply(0);
	}

	acceleration = steering->getLinear(); // Update the character's linear acceleration
	angular = steering->getAngular(); // Update the character's angular acceleration

}

/*
 * Normalizes the 2D vector
 */
void Coords::normalize()
{
	double length = this->length();
	this->x = x / length;
	this->z = z / length;
}

/*
 * Computes the length of the 2D vector
 */
double Coords::length()
{
	return sqrt(pow(this->x, 2) + pow(this->z, 2));
}

/*
 * Multiplies the 2D vector by a scalar
 * @return - the scaled 2D vector
 */
Coords Coords::multiply(double n)
{
	Coords product;
	product.x = this->x * n; // Multiply the x coordinate by the scalar
	product.z = this->z * n; // Multiply the z coordinate by the scalar
	return product;
}

/*
 * Adds two 2D vectors with two elements each
 * @param - the vector to add
 * @return - the sum of the two vectors
 */
Coords Coords::add(Coords addend)
{
	Coords sum;
	sum.x = this->x + addend.x; // Add the x coordinates
	sum.z = this->z + addend.z; // Add the z coordinates
	return sum;
}

/*
 * Subtracts two 2D vectors with two elements each
 * @param - the vector to subtract
 * @return - the difference of the two vectors
 */
Coords Coords::sub(Coords subtra)
{
	Coords diff;
	diff.x = this->x - subtra.x; // Subtract the x coordinates
	diff.z = this->z - subtra.z; // Subtract the z coordinates
	return diff;
}