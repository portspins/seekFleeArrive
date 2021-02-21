// Project:  CS 330 Programming Assignment 1
// Program : Dynamic movement
// Purpose : Implement the dynamic movement algorithms seek, flee, arrive, and stop.
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)
// Created:  2021 - 2 - 19
// Modified : 2021 - 2 - 21

#include <stdio.h>
#include <iostream>
#include <fstream>

#include "character.h"
#include "stop.h"
#include "seek.h"
#include "flee.h"
#include "arrive.h"

#define M_PI 3.14159265358979323846

using namespace std;

int main(void) {
	ofstream newFile;
	double deltaTime = 0.5; // The increment between update times in seconds
	double time = 0;		// The current simulation time in seconds
	double stopTime = 50;	// The length of the simulation in seconds
	Character* chars[4];
	Character* currentChar = NULL;

	newFile.open("TextPlotCoordinates.csv");

	if (!newFile)
	{
		cout << "Error! Could not open file." << endl;
		return 1;
	}

	// Initialize the STOP character
	chars[0] = new Character(161);

	// Initialize the FLEE character
	chars[1] = new Character(162);
	currentChar = chars[1];
	currentChar->setSteer(new Flee());
	currentChar->setPosition(-25, 50);
	currentChar->setVelocity(0, -8);
	currentChar->setOrientation(M_PI / 4);
	currentChar->setMaxSpeed(10);
	currentChar->setMaxAcceleration(2);
	currentChar->setTarget(chars[0]);

	// Initialize the SEEK character
	chars[2] = new Character(163);
	currentChar = chars[2];
	currentChar->setSteer(new Seek());
	currentChar->setPosition(50, -25);
	currentChar->setVelocity(0, -8);
	currentChar->setOrientation(3 * M_PI / 2);
	currentChar->setMaxSpeed(8);
	currentChar->setMaxAcceleration(2);
	currentChar->setTarget(chars[0]);

	// Initialize the ARRIVE character
	chars[3] = new Character(164);
	currentChar = chars[3];
	currentChar->setSteer(new Arrive());
	currentChar->setPosition(-50, -75);
	currentChar->setVelocity(-6, 4);
	currentChar->setOrientation(M_PI);
	currentChar->setMaxSpeed(8);
	currentChar->setMaxAcceleration(2);
	currentChar->setTarget(chars[0]);
	
	// Write the initial states of the characters to the file
	for (int i = 0; i < 4; i++) {
		newFile << time << "," << chars[i]->getId() << "," << chars[i]->getPosition().x << "," << chars[i]->getPosition().z
			<< "," << chars[i]->getVelocity().x << "," << chars[i]->getVelocity().z
			<< "," << chars[i]->getAcceleration().x << "," << chars[i]->getAcceleration().z << ","
			<< chars[i]->getOrientation() << "," << chars[i]->getSteer() << endl;
	}

	// Begin the simulation
	while (time < stopTime) {
		time += deltaTime;	// Increment the simulation time

		// Update each character's data
		for (int i = 0; i < 4; i++) {
			currentChar = chars[i];
			currentChar->update(deltaTime);
		}

		// Write the updated states of the characters to the file
		for (int i = 0; i < 4; i++) {
			newFile << time << "," << chars[i]->getId() << "," << chars[i]->getPosition().x << "," << chars[i]->getPosition().z
				<< "," << chars[i]->getVelocity().x << "," << chars[i]->getVelocity().z
				<< "," << chars[i]->getAcceleration().x << "," << chars[i]->getAcceleration().z << ","
				<< chars[i]->getOrientation() << "," << chars[i]->getSteer() << endl;
		}
	}

	// Deallocate the memory for the characters
	for (int i = 0; i < 4; i++) {
		delete chars[i];
	}

	newFile.close();
	system("pause");
	return 0;
}