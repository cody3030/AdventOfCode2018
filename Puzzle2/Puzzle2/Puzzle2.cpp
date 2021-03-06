// Puzzle2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Puzzle2.h"

bool containsDoubles(std::string str)
{
	int count;
	for (char &c : str) {
		count = 1;
		auto loc = str.find(c);
		while (loc != std::string::npos)
		{
			loc = str.find(c, loc + 1);
			if (loc != std::string::npos)
			{
				count++;
			}
		}
		if (count == 2) return true;
	}
	return false;
}

bool containsTriples(std::string str)
{
	int count;
	for (char &c : str) {
		count = 1;
		auto loc = str.find(c);
		while(loc != std::string::npos)
		{
			loc = str.find(c, loc + 1);
			if (loc != std::string::npos)
			{
				 count++;
			}
		}
		if (count == 3) return true;
	}
	return false;
}

long getID(std::string inFile)
{
	char line[256];
	std::ifstream myFile(inFile);
	long numDoubles = 0;
	long numTriples = 0;
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			myFile.getline(line, 256);
			std::string str(line);

			if (containsDoubles(str)) numDoubles++;
			if (containsTriples(str)) numTriples++;
		}
	}
	return numDoubles * numTriples;
}


int main()
{
	long result = getID("input.txt");
	std::cout << result << std::endl;
	system("pause");
}

