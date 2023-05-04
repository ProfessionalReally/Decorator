#pragma once

#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

//���������
class Medication
{
public: 
	virtual string GetName() = 0;
	virtual string GetDuration() = 0;
};

//���������� ������ ��������������� �������
class DrugTreatment : public Medication
{
public:
	virtual string GetName()
	{
		return string("Drug Treatment");
	}

	virtual string GetDuration()
	{
		return string("48 hours");
	}
};

//���������� ������ ������������
class Prophylaxis : public Medication
{
public:	
	virtual string GetName()
	{
		return string("Prophylaxis");
	}

	virtual string GetDuration()
	{
		return string("14 days");
	}
};

//���������
class GoToHospital : public Medication
{
protected:
	Medication* item; //������������ ������
public:
	GoToHospital(Medication* ITEM) { item = ITEM;}
	~GoToHospital() { if (item) delete item; }
	virtual string GetName() = 0;
	virtual string GetDuration() = 0;
};

//���������� ��������� ��������������
class Hospitalization : public GoToHospital
{
public:
	Hospitalization(Medication* ITEM) : GoToHospital(ITEM) {}
	virtual string GetName() 
	{ 
		return item->GetName() + string(" and ") + string("Hospitalization");
	}
	virtual string GetDuration() 
	{
		return item->GetDuration() + string (" and ") + string("1 week");
	}
};

//���������� ��������� ��������������
class DayHospital : public GoToHospital
{
public:
	DayHospital(Medication* ITEM) : GoToHospital(ITEM) {}
	virtual string GetName()
	{
		return item->GetName() + string(" and ") + string("Day Hospital");
	}
	virtual string GetDuration()
	{
		return item->GetDuration() + string(" and ") + string("1 month");
	}
};


