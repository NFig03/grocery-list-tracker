#ifndef LOG     //definition guards
#define LOG

#include <string>     //preprocessor directives
#include <map>

using namespace std;

class Log     //declares a log class to create log objects
{
	public:
		Log();     //constructors
		Log(std::map<string, int> x);

		void itemSearch();     //class member functions
		void numericalItemFrequency();
		void histogramItemFrequency();

	private:     //private class variables
		map<string, int>::iterator it;
		map<string, int> tempMap;
};

#endif