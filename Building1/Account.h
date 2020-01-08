#pragma once
#include <iostream>
using namespace std;
class Account
{
private:
	int acc_no;
	int pin;
	double money;
	string name;
public:
	Account() {}
	Account(string name, int acc_no, int pin, double money) : name(name), acc_no(acc_no), pin(pin), money(money) {}
	string getName() const {
		return name;
	}
	double getMoney() const {
		return money;
	}
	int getAcc_n() const {
		return acc_no;
	}
	int getPin() const {
		return pin;
	}
	void setMoney(double money) {
		this->money = money;
	}
	friend istream& operator>>(istream& in, Account& acc) {
		in >> acc.name;
		in >> acc.money;
		in >> acc.acc_no;
		in >> acc.pin;
		return in;
	}
	friend ostream& operator<<(ostream& out, const Account& acc) {
		out << acc.name;
		out << acc.money;
		out << acc.acc_no;
		out << acc.pin;
		return out;
	}
};