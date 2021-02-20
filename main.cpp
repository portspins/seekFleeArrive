// Project:  CS 330 Programming Assignment 1
// Program : Dynamic movement
// Purpose : Implement the dynamic movement algorithms seek, flee, arrive, and stop.
// Authors : Matthew Hise (mrh0036@uah.edu) and Gray Cummings (gdc0013@uah.edu)
// Created:  2021 - 2 - 19
// Modified : 2021 - 2 - 20

#include <stdio>
#include <iostream>
#include <fstream>

using namespace std;



int main(void) {
	fstream newFile;
	double deltaTime = 0.5; //The increment between update times.
	double time;

	newFile.open("TextPlotCoordinates.csv");

	if (!newFile)
	{
		cout << "Error!"
			return 0;
	}

	newFile.close;

}