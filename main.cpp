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


using namespace std;

int main( int argc , char* argv[] )
{
	ifstream inputFile;
	vector<string> inputStringArray;

	if (argc < 2) 
		{
			std::cerr << "Usage: " << argv[0] << " <INPUT FILE>. Use 'default' for all default values" << std::endl;
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
				char buffer[30];
				inputFile.getline(buffer, 30);
				
				string lineString(buffer);
				lineString.erase( std::remove(lineString.begin(), lineString.end(), ' '), lineString.end());

				inputStringArray.push_back(lineString);
			}
			inputStringArray.push_back("END");		// Seg fault protection
		}
	}
	
	ifstream batchIndex;
	batchIndex.open("results/batchIndex.txt");
	
	while (!batchIndex.eof())
	{	
		stringstream inputStream;
		char buffer[30];
		batchIndex.getline(buffer, 30);
		string lineString(buffer);
		lineString.erase( std::remove(lineString.begin(), lineString.end(), ' '), lineString.end());
	
	}
	
	if (remove("root_shell.sh")) perror("Error removing root_shell.sh");
	
	ofstream rootShell;
	rootShell.open("root_shell.sh", ios::app);
	rootShell << "#!/bin/bash" << endl << endl;
	
	time_t now = time(0);
	tm* ltm = localtime(&now);	

	rootShell << "mkdir " << "results/SimBatch00001_" << ltm->tm_mon << "-" << ltm->tm_mday  << "-" << ltm->tm_year + 1900 << endl; 
	
	for(int i = 0; inputStringArray[i] != "END"; i++)
	{
		cout << inputStringArray[i];
	}
}

