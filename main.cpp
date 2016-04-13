/*	Program creates a series of shell scripts to run different parameter combinations
	for Islet of Langerhans model
		
	Author: William Fischer
*/


#include <iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip> 


using namespace std;

int main( int argc , char* argv[] )
{
	ifstream inputFile;
	vector<string> inputStringArray;
	int runIndexInt = 0;

	if (argc < 2) 
		{
			cerr << "Usage: " << argv[0] << " <INPUT FILE>. Use 'default' for all default values" << endl;
			return 1;
		}
	else
	{
		string inputFileName =  argv[1];
		if (inputFileName == "default")
		{
			cout << "Default" << endl;
		}
		else
		{
			cout << "Data input from: " << inputFileName << endl;
			inputFile.open(inputFileName);
			while (!inputFile.eof())
			{	
				string lineString;
				getline(inputFile, lineString);
				lineString.erase(remove(lineString.begin(), lineString.end(), ' '), lineString.end());

				inputStringArray.push_back(lineString);
			}
			inputStringArray.push_back("END");		// Seg fault protection
		}
	}
	
	ifstream batchIndex;
	batchIndex.open("results/batchIndex.txt");
	
	if(batchIndex){
		while(!batchIndex.eof())
		{	
			string wordString;
			batchIndex >> wordString;
			if(wordString == "Run:")
			{
				string runIndexString;
				batchIndex >> runIndexString;
				string::size_type sz; 
				runIndexInt = stoi (runIndexString,&sz);
				cout << runIndexInt << endl;
			}
		}
	}
	else
	{
		cout << "Error, 'batchIndex.txt' is missing." << endl;
		return 1;
	}
	
	if (remove("root_shell.sh")) perror("Error removing root_shell.sh");
	
	ofstream rootShell;
	rootShell.open("root_shell.sh", ios::app);
	rootShell << "#!/bin/bash" << endl << endl;
	
	time_t now = time(0);
	tm* ltm = localtime(&now);	

	
	// cout << setfill('0') << setw(5) << 25;  // Example of padding leading zeroes for later
	rootShell << "mkdir " << "results/SimBatch"<< setfill('0') << setw(5) << (runIndexInt + 1) << "_" << ltm->tm_mon << "-" << ltm->tm_mday  << "-" << ltm->tm_year + 1900 << endl; 
	
	for(int i = 0; inputStringArray[i] != "END"; i++)
	{
		cout << inputStringArray[i];
	}
}

