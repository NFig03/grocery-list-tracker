#include "Log.h"     //necessary preprocessor directives
#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

void printMenu();     //function declarations to allow main to be at top
std::map<string, int> readToMap();
void menuFunction(Log a);

int main()     //main function
{
	Log currentList = Log(readToMap());     //creates a log item with the argument of the list that the read to map function returns
	printMenu();     //function to print the menu for cleaner code
	menuFunction(currentList);     //function that defines the functionality of the menu screen
	return 0;
}

void printMenu()     //simply prints the menu in a clean and clear format
{
	cout << "********** Corner Grocer **********" << endl;
	cout << "1 - Item Search " << endl;
	cout << "2 - Numerical Item Frequency " << endl;
	cout << "3 - Histogram Item Frequency " << endl;
	cout << "4 - Exit Program " << endl;
}

std::map<string, int> readToMap()     //reads input from the file into the map
{
	ifstream listFS;
	string item;
	map<string, int> groceryList;

	listFS.open("CS210_Project_Three_Input_File.txt");

	if (!listFS.is_open())
	{
		cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
	}

	getline(listFS, item);

	while (!listFS.fail())
	{
		if (groceryList.count(item) == 0)     //if the item is not yet in the list
		{
			groceryList.insert({ item, 1 });
		}
		else     //the item must be in the list
		{
			groceryList[item]++; 
		}
		getline(listFS, item);
	}

	ofstream stream("frequency.dat");     //creates a data backup file

	map<string, int>::iterator it;     //iterator to iterate through the map
	it = groceryList.begin();

	while (it != groceryList.end())     //prints the contents of the map to the file
	{
		stream << it->first << " " << it->second << endl;
		it++;
	}

	stream.close();     //closes the output stream

	return groceryList;     //returns the map
}

void menuFunction(Log a)     //this function provides the functionality for the menu
{
	int input;

	cin >> input;
	
	while (input != 4)     //switch to assign numbers to a menu option
	{
		switch (input)
		{
		case 1:
			a.itemSearch();
			printMenu();
			break;
		case 2:
			cout << endl;
			a.numericalItemFrequency();
			cout << endl;
			printMenu();
			break;
		case 3:
			cout << endl;
			a.histogramItemFrequency();
			cout << endl;
			printMenu();
			break;
		case 4:
			break;
		}
		cin >> input;
	}
	return;
}