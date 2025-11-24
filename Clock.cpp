#include "Clock.h"

Clock::Clock(int h, int m, int s) //A constructor that puts parameters and if there is an error throws an appropriate message
{
	if (s < 0)
		throw "Invalid time - negative number of seconds.";
	if (s > 59)
		throw "Invalid time - more than 60 seconds.";
	if (m < 0)
		throw "Invalid time - negative number of minutes.";
	if (m > 59)
		throw "Invalid time - more than 60 minutes.";
	if (h < 0)
		throw "Invalid time - negative number of hours.";
	if (h > 23)
		throw "Invalid time - more than 24 hours.";
	hour = h;
	minute = m;
	second = s;

}
//set functions
void Clock::setSecond(int s)
{
	if (s < 0)
		throw "Invalid time - negative number of seconds.";
	else if (s > 59)
		throw "Invalid time - more than 60 seconds.";

	second = s;
}
//set setMinute
void Clock::setMinute(int m)
{

	if (m < 0)
		throw "Invalid time - negative number of minutes.";
	else if (m > 59)
		throw "Invalid time - more than 60 minutes.";

	minute = m;
}
// set setHour
void Clock::setHour(int h)
{

	if (h < 0)
		throw "Invalid time - negative number of hours.";
	else if (h > 23)
		throw "Invalid time - more than 24 hours.";

	hour = h;
}
//operators functions
void Clock :: operator+=(int s)  //change the clock according to given seconds amount
{
	s += getSecond();
	if (s > 59) //there are more than one minute
	{
		setSecond(s % 60);
		int minutes = (s / 60) + getMinute();
		if (minutes > 59)   //there are more than one hour
		{
			setMinute(minutes % 60);
			int hours = (minutes / 60) + getHour();
			if (hours > 23) //there are more than one day
			{
				setHour(hours % 24);
			}
			else
				setHour(hours);
		}
		else
			setMinute(minutes);
	}
	else
		setSecond(s);
}
// operator <<
ostream& operator<<(ostream& os, const Clock& c)
{
	if (c.hour < 10)
		os << "0" << c.hour << ":";
	else
		os << c.hour << ":";

	if (c.minute < 10)
		os << "0" << c.minute << ":";
	else
		os << c.minute << ":";

	if (c.second < 10)
		os << "0" << c.second;
	else
		os << c.second;
	return os;
}
// operator >>
istream& operator >> (istream& is, Clock& c)
{
	int s, m, h;
	is >> s >> m >> h;
	s += c.getSecond();
	if (s > 59) //there are more than one minute
	{
		c.setSecond(s % 60);
		int minutes = (s / 60) + c.getMinute();
		if (minutes > 59)   //there are more than one hour
		{
			c.setMinute(minutes % 60);
			int hours = (minutes / 60) + c.getHour();
			if (hours > 23) //there are more than one day
			{
				c.setHour(hours % 24);
			}
			else
				c.setHour(hours);
		}
		else
			c.setMinute(minutes);
	}
	else
		c.setSecond(s);
	return is;
}
