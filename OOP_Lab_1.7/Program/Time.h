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

	// ��������� ������� ����
	bool IsEarlierThan(Time);
	bool IsSameAs(Time);
	bool IsLaterThan(Time);

	//����������� � ���� ������ ������� ������
	void SubstractSeconds();// ��, �� ���������

	//��������� �� ���� ������ ������� ������
	void TimePlusSeconds();// ��, �� ���������

	//���������� ������ �� ����� ��������� ���� � ��������
	friend unsigned int Difference(Time, Time);

	friend unsigned int DifferenceForT(Time T1, Time T2);//minutes

	// ����������� � �������
	unsigned int ToSeconds();

	// ����������� � ������� (� ����������� �� ���� �������)
	unsigned int ToMinutes();

};
