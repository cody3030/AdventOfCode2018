// Puzzle2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


void findMatchs(std::string id, std::vector<std::string> *ids)
{
	for (auto b : *ids)
	{
		if (b != id)
		{
			int count = 0;
			int i = 0;
			int loc;
			auto it = b.begin();
			for (char &c : id)
			{
				if (it != b.end())
				{
					if (c != b[i])
					{
						count++;
						loc = i;
					}
					it++;
				}
				i++;
			}
			if (count == 1)
			{
				id.erase(id.begin() + loc);
				std::cout << id << std::endl;
			}
		}
	}
}

std::string getID(std::string inFile)
{
	std::vector < std::string> ids;
	char line[256];
	std::ifstream myFile(inFile);
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			myFile.getline(line, 256);
			std::string str(line);
			ids.push_back(str);
		}
	}
	//auto it = ids.begin();
	for (std::string a: ids)
	{
		findMatchs(a, &ids);
	}
	return "";
}


int main()
{
	std::string result = getID("input.txt");
	//std::cout << result << std::endl;
	system("pause");
}

