#pragma once
#include <iostream>
using namespace std;

class Clock
{

	int hour = 0;
	int minute = 0;
	int second = 0;
public:
	Clock(int h, int m, int s);
	//set functions
	void setSecond(int s);
	void setMinute(int m);
	void setHour(int h);

	//get functions
	int getSecond() { return second; };
	int getMinute() { return minute; };
	int getHour() { return hour; };
	void operator +=(int s);
	friend ostream& operator <<(ostream& os, const Clock& c);
	friend istream& operator >> (istream& is, Clock& c);
};
