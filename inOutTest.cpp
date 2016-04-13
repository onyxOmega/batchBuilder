#include <iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip> 

using namespace std;

int main( int argc , char* argv[])
{
	string answer;
	bool customVars;
	
	cout << "Welcome to the Islet of Langerhans simulator, optimized for the UC Boulder Janus Research Computer." << endl;
	cout << "  Written by Matt Westacott, Aleena Notary, and William Fischer" << endl << endl;
	
	cout << "Would you like to run simulations using custom parameters? (y/n) ";
	bool validAnswer = false;
	while(!validAnswer)
	{
		cin >> answer;
		if(answer == "Y" || answer == "y")
		{
			cout << "Great! Let's get started. I'll ask some questions. Type 'd' to select the default option, or type 'help' for more information. "<< endl << endl;
			customVars = true;
			validAnswer = true;
		}
		else if(answer == "N" || answer == "n")
		{
			cout << "Ok, we'll run a simulation using default values." << endl << endl;
			validAnswer = true;
		}
		else
		{
			cout << "Your answer is invalid, please try again. (y/n) ";
		}
	}
	
	int simTime;
	//string answer;
	double stepTime = 0.18;
	string simName;
	
	cout << "How long do you want the simulation to be (in seconds)? ";
	cin >> simTime;
	cout << "How long of a step time would you like to use in ms? ('d' for default, help for details) ";
	validAnswer = false;
	while(!validAnswer)
	{
		cin >> answer;
		
		if(answer == "help")
		{
			cout << "Display help information here..." << endl;
			cout << "Please enter a step time value.";
		}
		if(answer == "d")
		{
			stepTime = .18;
			validAnswer = true;
		}
		else
		{
			stringstream answerSS(answer);
			answerSS >> stepTime;
			if(!answerSS.fail())
			{
				if(stepTime < 0.3 && stepTime > 0)
				{
					validAnswer = true;
				}
				else
				{	
					cout << "Not a valid value. Please try again, or enter 'help'.";
				}
			}
			else
			{
				cout << "Not a valid input. Please try again, or enter 'help'. ";
			}
		}
	}
	
	int outputInterval;
	cout << "At what interval (in milliseconds) would you like to output data? ";
	validAnswer = false;
	while(!validAnswer)
	{
		cin >> answer;
		
		if(answer == "help")
		{
			cout << "Please select an interval of 50 ms. " << endl;
		}
		if(answer == "d")
		{
			outputInterval = 100;
			validAnswer = true;
		}
		else
		{
			stringstream answerSS(answer);
			answerSS >> outputInterval;
			if(!answerSS.fail())
			{
				if(outputInterval % 50 == 0)
				{
					validAnswer = true;
				}
				else
				{	
					cout << "Not a valid value. Please try again, or enter 'help'.";
				}
			}
			else
			{
				cout << "Not a valid input. Please try again, or enter 'help'. ";
			}
		}
	}
	
	cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
	cout << "Running the following: " << endl;
	cout << " Simulation time: " << simTime << " seconds. \n";
	cout << " Step time: " << stepTime << " milliseconds \n";
	cout << "Total simulation timepoints: " << floor((simTime*1000)/stepTime) << endl; 
	
	return 0;
}