#include "Time.h"
#include <iostream>

void Time::SetHour(unsigned int value)
{
	if (value > 23 || value < 0)
		value = 0;
	this->hour = value;
}

void Time::SetMinute(unsigned int value)
{
	if (value > 59 || value < 0)
		value = 0;
	this->minute = value;
}

void Time::SetSecond(unsigned int value)
{
	if (value > 59 || value < 0)
		value = 0;
	this->second = value;
}


void Time::Init_time(unsigned int hour, unsigned int minute, unsigned int second)
{
	SetHour(hour);
	SetMinute(minute);
	SetSecond(second);
}

void Time::Read()
{
	unsigned int h, m, s;
	do {
		cout << " Enter hour: "; cin >> h;
	} while (h > 23 || h < 0);

	do {
		cout << " Enter minute: "; cin >> m;
	} while (m > 59 || m < 0);

	do {
		cout << " Enter second: "; cin >> s;
	} while (s > 59 || s < 0);

	Init_time(h, m, s);
}

void Time::Display() {
	cout << endl << toString() << endl;
}

string Time::toString() const {
	stringstream sout;
	sout << " " << hour << ":" << minute << ":" << second;
	return sout.str();
}


////////////////////////////////////////////////////////////////////////
bool Time::IsEarlierThan(Time T2)
{
	if (hour == T2.hour)
	{
		if (minute == T2.minute)
		{
			if (second == T2.second)
				return false;
			else if (second < T2.second)
				return true;
			else
				return false;
		}
		else if (minute < T2.minute)
			return true;
		else
			return false;
	}
	else if (hour < T2.hour)
		return true;
	else
		return false;
}

bool Time::IsSameAs(Time T2)
{
	if (hour == T2.hour)
	{
		if (minute == T2.minute)
		{
			if (second == T2.second)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool Time::IsLaterThan(Time T2)
{
	if (IsEarlierThan(T2))
		return false;
	else if (!IsSameAs(T2))
		return true;
}

void Time::SubstractSeconds()
{
	unsigned int substr;
	do {
		cout << "Enter how much seconds to substract: "; cin >> substr;
	} while (substr < 1);

	hour -= trunc(substr / 3600.);
	minute -= trunc(substr % 3600 / 60.);
	second -= substr % 60;

	if (second >= 60 || second < 0)
	{
		minute += second / 60;
		second %= 60;
		if (second < 0)
		{
			minute--;
			second = 60 + second;
		}
	}

	if (minute >= 60 || minute < 0)
	{
		hour += minute / 60;
		minute = minute % 60;
		if (minute < 0)
		{
			hour--;
			minute = 60 + minute;
		}
	}

	if (hour >= 24 || hour < 0)
		hour = (hour < 0 ? 24 : 0) + hour % 24;
}

void Time::TimePlusSeconds()
{
	unsigned int seconds;
	do {
		cout << "Enter how much seconds to add: "; cin >> seconds;
	} while (seconds < 1);

	int hm = trunc(seconds / 3600.);
	hour += trunc(seconds / 3600.);
	minute += trunc(seconds % 3600 / 60.);
	second += seconds % 60;

	if (second >= 60 || second < 0)
	{
		minute += second / 60;
		second %= 60;
		if (second < 0)
		{
			minute--;
			second = 60 + second;
		}
	}

	if (minute >= 60 || minute < 0)
	{
		hour += minute / 60;
		minute = minute % 60;
		if (minute < 0)
		{
			hour--;
			minute = 60 + minute;
		}
	}

	if (hour >= 24 || hour < 0)
		hour = (hour < 0 ? 24 : 0) + hour % 24;
}

unsigned int Time::ToSeconds()
{
	unsigned int t;
	t = hour * 3600 + minute * 60 + second;
	return t;
}

unsigned int Time::ToMinutes()
{
	unsigned int t;
	if (second < 1)
	{
		t = hour * 60 + minute;
	}
	if (second > 0)
	{
		t = hour * 60 + minute + 1;
	}
	return t;
}

unsigned int Difference(Time T1, Time T2)
{
	return T2.ToSeconds() - T1.ToSeconds();
}

unsigned int DifferenceForT(Time T1, Time T2)
{
	int k;
	k = Difference(T1, T2) / 60.;
	return k;
}
