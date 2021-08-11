/*
Michael Durst
8/10/2020
This is the skynet HK Aerial assignment for csc 215. Sorry for doing it late
*/

// Declare needs libraries 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	// Declare varibables for the search algorithim, random number generator, number of tries and predictions.
	int searchGridLowNumber = 1;
	int searchGridHighNumber = 64;
	srand(static_cast<unsigned int>(time(0))); // seeding the random number generator
	int secretNumber = rand() % 64 + 1;
	// This search algorithim looks at the number between the high and low guess possibilities
	int targetLocationPrediction =
		((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
	int tries = 0;
	//Begin program text
	cout << "Generate Random enemy location on 8x8 grid .... \n";
	cout << "The enemy is located at location #" << secretNumber << " on 8x8 grid with 1-64 sectors. \n";
	cout << "Skynet Hk-Aerial Initializing software .... \n";
	// Do while loop running the search algorithim and game text.
	do
	{
		// Increment tries here so we can see "Ping1"
		++tries;
		cout << "---------------------------------- \n";
		cout << "HK-Aerial Radar Sending out ping #" << tries << "\n";
		// intialize search algorithm for this cycle
		targetLocationPrediction =
			((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		// Begin conditional to see if guess is too high or too low
		if (targetLocationPrediction > secretNumber) // If too high 
		{
			cout << "The target location of " << targetLocationPrediction << " was higher than the enemy location "  << secretNumber << "." << endl;
			searchGridHighNumber = targetLocationPrediction; // Assin the high number to this location
			cout << "The new searchGridHighNumber = " << searchGridHighNumber << "\n"; // let the user know
		}
		else if(targetLocationPrediction < secretNumber) // if too low
		{
			// Same as before but searchGridLowNumber
			cout << "The target location prediction of " << targetLocationPrediction << "was lower than the enemy location " << secretNumber << "." << endl;
			searchGridLowNumber = targetLocationPrediction;
			cout << "The new searchGridLowNumber  = " << searchGridLowNumber << "\n";
		}
		else // set win condition 
		{
			cout << "Enemy was hiding at location #" << secretNumber << "\n";
				cout << "Target was found at location #" << targetLocationPrediction << "\n";
				cout << "Skynet Hk-Aerial Software took" << tries <<  "predictions to find the enemy location on the grid size of 8x8. \n";
		}
	} while (targetLocationPrediction != secretNumber); // Set loop condition 
	// main() return statement
	return 0;
}