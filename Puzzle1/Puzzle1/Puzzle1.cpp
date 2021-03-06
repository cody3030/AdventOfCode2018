// Puzzle1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>

bool getFrequencies(std::string inFile, std::vector<long>* list)
{
	long result = list->back();
	std::ifstream myFile(inFile);
	long a;
	if(myFile.is_open())
	{
		while (!myFile.eof())
		{
			myFile >> a;
			result += a;
			
			if(std::find(list->begin(), list->end(), result) == list->end() || list->empty()) list->push_back(result);
			else
			{
				std::cout << result << std::endl;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	std::vector<long> frequencies;
	frequencies.push_back(0);
	//long result = getFrequencies("input.txt", &frequencies);
	while(!getFrequencies("input.txt",&frequencies)){}
	system("pause");
}

