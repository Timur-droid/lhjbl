#pragma once
#include "Build.h"
#include "Account.h"
#include <vector>
#include <fstream>
#include <algorithm>

class Office : public Build {
	int floor;
	string Type;
	string Type2;
	double money;
	static vector<Account*> accounts;
	static vector<Account*> accounts1;
public:
	Office(int floor = 1, string Type = "Office", double money = 0) : floor(floor), Type(Type), money(money) {
		accounts1.push_back(new Account("Mike", 1234, 4321, 600000.0));
		accounts1.push_back(new Account("John", 5678, 8765, 300000.0));
		accounts1.push_back(new Account("Kile", 2345, 5432, 300000.0));
		accounts1.push_back(new Account("Jack", 3456, 6543, 900000.0));
		fstream fs;
		fs.open("Accounts.txt");
		for (auto acc : accounts1) {
			fs.read((char*)& accounts, sizeof(Account));
		}
		fs.close();

		/*for (int i = 0; i < size; i++) {
			cout << accounts[i]->getName() << endl;
		}*/
	}
	static Account* getAccounts(int i) {
		return accounts.at(i);
	}
	int getSize() const override {
		return accounts.size();
	}
	string getType() const override {
		return Type;
	}
	string getType2() const override {
		return Type2;
	}
	int getFloor() const override {
		return floor;
	}
	void setFloor(int floor) override {
		this->floor = floor;
	}
	void operator()(int floor) {
		this->floor = floor;
	}
	void Buy(int acc_no, int pin, double amount) override {
		int find = findBUY(pin, acc_no, amount);
		if (find == 2) {
			cout << "NOT FOUND!" << endl;
		}
		if (find == 3) {
			string name = findName(pin, acc_no);
			cout << name << endl;
			cout << "You don't have enough money!" << endl;
		}
		if (find == 1) {
			string name = findName(pin, acc_no);
			cout << name << endl;
			cout << "You bought an Office!" << endl;
			cout << "Sellers telephone number - +9989********" << endl;
			cout << "And now, you have " << findMoney(pin, acc_no) << "$" << endl;
		}
	}

	double findMoney(int pin, int acc_no) override {
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i]->getAcc_n() == acc_no && accounts[i]->getPin() == pin) {
				return accounts[i]->getMoney();
			}
		}
	}

	int findBUY(int pin, int acc_no, double amount) override {
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i]->getAcc_n() == acc_no && accounts[i]->getPin() == pin) {
				if (accounts[i]->getMoney() > amount) {
					double a = accounts[i]->getMoney() - amount;
					accounts[i]->setMoney(a);
					return 1;
				}
				else { return 3; }
			}
		}
		return 2;
	}
	string findName(int pin, int acc_no) override {
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i]->getAcc_n() == acc_no && accounts[i]->getPin() == pin) {
				return accounts[i]->getName();
			}
		}
	}
	void Arenda(int acc_no, int pin, double amount, double month) {
		int find = findArenda(pin, acc_no, amount, month);
		if (find == 2) {
			cout << "NOT FOUND!" << endl;
		}
		if (find == 3) {
			cout << "You don't have enough money!" << endl;
		}
		if (find == 1) {
			cout << "Sellers telephone number - +9989********" << endl;
			cout << "If you arended this Office, you will have " << getMoney(1) << "$ !" << endl;
		}
	}

	int findArenda(int pin, int acc_no, double amount, double month) override {
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i]->getAcc_n() == acc_no && accounts[i]->getPin() == pin) {
				money = accounts[i]->getMoney() - (amount * month);
				if (money > 0) {
					return 1;
				}
				else { return 3; }
			}
		}
		return 2;
	}

	double getMoney(int i) override {
		return money;
	}

	~Office() {
	while (!accounts.empty()) {
			accounts.pop_back();
		}
		/*for (int i = 0; i < accounts.size(); i++) {
			delete accounts1[i];
		}*/
	}

};
vector<Account*> Office::accounts;
vector<Account*> Office::accounts1;