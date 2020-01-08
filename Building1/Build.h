#pragma once
#include <iostream>
using namespace std;
class Build
{
public:
	virtual string getType() const = 0;
	virtual int getSize() const = 0;
	virtual void Buy(int, int, double) = 0;
	virtual int getFloor() const = 0;
	virtual string getType2() const = 0;
	virtual void setFloor(int) = 0;
	virtual double findMoney(int, int) = 0;
	virtual int findBUY(int, int, double) = 0;
	virtual string findName(int, int) = 0;
	virtual void Arenda(int, int, double, double) = 0;
	virtual int findArenda(int, int, double, double) = 0;
	virtual double getMoney(int) = 0;
};