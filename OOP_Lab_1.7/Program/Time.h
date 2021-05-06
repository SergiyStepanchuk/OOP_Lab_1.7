#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Time
{
private:
	unsigned int hour, minute, second;
public:
	unsigned int GetHour() const { return hour; };
	unsigned int GetMinute() const { return minute; };
	unsigned int GetSecond() const { return second; };

	void SetHour(unsigned int);
	void SetMinute(unsigned int);
	void SetSecond(unsigned int);

	void Init_time(unsigned int, unsigned int, unsigned int);
	void Read();
	void Display();
	string toString() const;
	//////////////////////////////////////////////////////////////////////

	// Порівняння моментів часу
	bool IsEarlierThan(Time);
	bool IsSameAs(Time);
	bool IsLaterThan(Time);

	//відніманняння з часу заданої кількості секунд
	void SubstractSeconds();// хз, чи правильно

	//додавання до часу задану кількість секунд
	void TimePlusSeconds();// хз, чи правильно

	//обчислення різниці між двома моментами часу в секундах
	friend unsigned int Difference(Time, Time);

	friend unsigned int DifferenceForT(Time T1, Time T2);//minutes

	// Переведення в секунди
	unsigned int ToSeconds();

	// Переведення у хвилини (з округленням до цілої хвилини)
	unsigned int ToMinutes();

};
