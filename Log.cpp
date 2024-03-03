#include "Log.h"     //preprocessor directives
#include <iostream>
#include <string>
#include <map>
using namespace std;

Log::Log(std::map<string, int> x)     //defines the instructor requiring parameters
{
	tempMap = x;
}

void Log::itemSearch()     //defines the member function for searching for an item
{
	int counter = 0;
	string temp;
	cout << endl;
	cout << "Please Input the Item Name" << endl;
	cin >> temp;
	
	for (auto &it:tempMap)
	{
		if (it.first == temp)
		{
			cout << endl;
			cout << it.first << it.second << endl;
		}
	}
	
	cout << endl;
	cout << endl;

}

void Log::numericalItemFrequency()     //defines the function for menu option 2
{
	it = tempMap.begin();

	while (it != tempMap.end())
	{
		cout << it->first << " " << it->second << endl;
		it++;
	}
}

void Log::histogramItemFrequency()     //defines the function for menu option 3
{
	it = tempMap.begin();

	while (it != tempMap.end())
	{
		cout << it->first;

		for (int i = 0; i < it->second; i++)
		{
			cout << "*";
		}
		it++;
		cout << endl;
	}
	
	cout << endl;

}
