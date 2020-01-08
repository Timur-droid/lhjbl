#pragma once
#include <iostream>
#include "House.h"
#include "Office.h"
#include "Account.h"
#include <iterator>
using namespace std;

class Work
{
	int ID;
	int Pass;
	House a;
	Office b;
public:

	bool proverka(int ID, int pass) {
		vector<Account*> accounts;
		for (int i = 0; i < a.getSize(); i++) {
			accounts.push_back(a.getAccounts(i));
		}

		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i]->getAcc_n() == ID && accounts[i]->getPin() == pass) {
				this->ID = accounts[i]->getAcc_n();
				this->Pass = accounts[i]->getPin();
				return true;
			}
		}
		return false;
	}

	void welcome() {
		system("cls");
		cout << "************************************" << endl;
		cout << "*   Insert your account's number   *" << endl;
		cout << "************************************" << endl;
		cin >> ID;
		system("cls");
		cout << "************************************" << endl;
		cout << "*  Insert your account's pincode   *" << endl;
		cout << "************************************" << endl;
		cin >> Pass;
		system("cls");
		sohronit(ID, Pass);
	}
	void sohronit(int ID, int Pass){
		try {
			if (proverka(ID, Pass) == false) {
				throw 1;
			}
			mainMenu();
		}
		catch (int i) {
			int a;
			cout << "Your account not found!" << endl;
			cout << "Press 1 to try again!" << endl;
			cin >> a;
			system("cls");
			welcome();
		}
	}

	void mainMenu() {
		system("cls");
		int choise;
		cout << endl;
		cout << "\tWelcome " << a.findName(Pass, ID);
		cout << endl;
		cout << "\t1 - Office" << endl;
		cout << "\t2 - House" << endl;
		cout << "\t3 - Exit" << endl;
		cout << endl;
		cout << "\tChoise one of them ";
		cin >> choise;
		if (choise == 1) {
			office();
		}
		if (choise == 2) {
			menu();
		}
		if (choise == 3) {
			welcome();
		}
	}

	void office() {
		system("cls");
		int choise;
		cout << endl;
		cout << "\t1 - Buy Office" << endl;
		cout << "\t2 - Arend Office" << endl;
		cout << "\t3 - Your balance" << endl;
		cout << "\t4 - Main menu" << endl;
		cout << "\t5 - Exit" << endl;
		cout << endl;
		cout << "\tChoise one of them ";
		cin >> choise;
		if (choise == 1) {
			office1();
		}
		if (choise == 2) {
			office2();
		}
		if (choise == 4) {
			mainMenu();
		}
		if (choise == 3) {
			system("cls");
			cout << "Your balance = " << ShowBalance(Pass, ID) << "$" << endl;
			cout << "Back to menu - 1" << endl;
			cin >> choise;
			office();
		}
		if (choise == 5) {
			welcome();
		}
	}

	void office2() {
		system("cls");
		cout << endl;
		int floors;
		int month;
		cout << "\tHow many floors" << endl;
		cin >> floors;
		cout << "\tHow many month" << endl;
		cin >> month;
		if (floors > 90) {
			system("cls");
			cout << "We don't have building with " << floors << " floors" << endl;
			cout << "Press somthing, to change floors" << endl;
			system("pause");
			office2();
		}
		double amount = 1250 * floors;
		int choise;
		system("cls");
		b.Arenda(ID, Pass, amount, month);
		cout << endl;
		cout << "Press 1 to menu!" << endl;
		cout << "Press 2 to Exit!" << endl;
		cin >> choise;
		if (choise == 1) {
			mainMenu();
		}
		if (choise == 2) {
			welcome();
		}
	}

	void office1() {
		system("cls");
		cout << endl;
		int floors;
		cout << "\tHow many floors" << endl;
		cin >> floors;
		if (floors > 90) {
			system("cls");
			cout << "We don't have building with " << floors << " floors" << endl;
			cout << "Press somthing, to change floors" << endl;
			system("pause");
			office1();
		}
		double amount = 100000 * floors;
		int choise;
		system("cls");
		cout << "Total cash - " << amount << "$" << endl;
		cout << "Press 10 to buy or press 20 to menu" << endl;
		cin >> choise;
		if (choise == 10) {
			BuyOffice(amount);
		}
		if (choise == 20) {
			office();
		}
	}

	void BuyOffice(int amount) {
		system("cls");
		int choise;
		b.Buy(ID, Pass, amount);
		cout << endl;
		cout << "Press 1 to menu!" << endl;
		cout << "Press 2 to Exit!" << endl;
		cin >> choise;
		if (choise == 1) {
			mainMenu();
		}
		if (choise == 2) {
			welcome();
		}
	}

	void menu() {
		system("cls");
		int choise;
		cout << endl;
		cout << "\t1 - Buy House" << endl;
		cout << "\t2 - Arend House" << endl;
		cout << "\t3 - Your balance" << endl;
		cout << "\t4 - Main menu" << endl;
		cout << "\t5 - Exit" << endl;
		cout << endl;
		cout << "\tChoise one of them ";
		cin >> choise;
		if (choise == 1) {
			menu1();
		}
		if (choise == 2) {
			menu2();
		}
		if (choise == 4) {
			mainMenu();
		}
		if (choise == 3) {
			cout << "Your balance = " << ShowBalance(Pass, ID) << "$" << endl;
			cout << "Back to menu - 1" << endl;
			cin >> choise;
			menu();
		}
		if (choise == 5) {
			welcome();
		}
	}
	double ShowBalance(int Pass, int ID) {
		vector<Account*> accounts;
		for (int i = 0; i < a.getSize(); i++) {
			accounts.push_back(a.getAccounts(i));
		}

		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i]->getAcc_n() == ID && accounts[i]->getPin() == Pass) {
				return accounts[i]->getMoney();
			}
		}
	}

	void menu1(){
		system("cls");
		cout << endl;
		cout << endl;
		int floor;
		cout << "    How much floor ?" << endl;
		cin >> floor;
		a(floor);
		system("cls");
		cout << endl;
		cout << endl;
		if (floor == 1) {
			Howfloor(1);
		}
		if (floor == 2) {
			Howfloor(2);
		}
		if (floor == 3) {
			Howfloor(3);
		}
		if (floor == 4) {
			Howfloor(4);
		}
		if (floor > 5) {
			int choise;
			cout << "We don't house with " << floor << " floors" << endl;
			cout << "Press 1, to change floors!" << endl;
			cin >> choise;
			menu1();
		}
	}
	void menu2() {
		system("cls");
		cout << endl;
		cout << endl;
		system("cls");
		cout << endl;
		cout << endl;
		double floor;
		double month;
		cout << "    How much floor ?" << endl;
		cin >> floor;
		cout << "    How much month ?" << endl;
		cin >> month;
		a(floor);
		system("cls");
		cout << endl;
		cout << endl;
		ArendaHouse(floor, month);
	}

	void ArendaHouse(double floor, double month) {
		int choise;
		system("cls");
		cout << endl;
		cout << endl;
		if (floor > 5) {
			int choise;
			cout << "We don't have house with " << floor << " floors" << endl;
			cout << "Press 1, to change floors!" << endl;
			cin >> choise;
			menu1();
		}
		double amount = 1000 * floor;
		int accNumber = getAccNo();
		int pn = getAccPIN();
		a.Arenda(accNumber, pn, amount, month);
		cout << endl;
		cout << "Press 1 to menu!" << endl;
		cout << "Press 2 to Exit!" << endl;
		cin >> choise;
		if (choise == 1) {
			mainMenu();
		}
		if (choise == 2) {
			welcome();
		}
	}
	void Howfloor(int floor) {
		double amount;
		if (floor == 1) {
			amount = 100000.0;
		}
		if (floor == 2) {
			amount = 200000.0;
		}
		if (floor == 3) {
			amount = 300000.0;
		}
		if (floor == 4) {
			amount = 400000.0;
		}
		int choise;
		cout << "\tHouse with " << a.getFloor() << " floors - " << amount << "$" << endl;
		cout << endl;
		cout << "If you want to change floors, press 1." << endl;
		cout << "To continue press 2." << endl;
		cin >> choise;
		system("cls");
		if (choise == 1) {
			menu1();
		}
		if (choise == 2) {
			int accNumber = getAccNo();
			int pn = getAccPIN();
			a.Buy(accNumber, pn, amount);
			cout << endl;
			cout << "Press 1 to menu!" << endl;
			cout << "Press 2 to Exit!" << endl;
			cin >> choise;
			if (choise == 1) {
				mainMenu();
			}
			if (choise == 2) {
				welcome();
			}
		}
	}

	int getAccNo() {
		vector<Account*> accounts;
		for (int i = 0; i < a.getSize(); i++) {
			accounts.push_back(a.getAccounts(i));
		}

		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i]->getAcc_n() == ID && accounts[i]->getPin() == Pass) {
				return accounts[i]->getAcc_n();
			}
		}
	}
	int getAccPIN() {
		vector<Account*> accounts;
		for (int i = 0; i < a.getSize(); i++) {
			accounts.push_back(a.getAccounts(i));
		}

		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i]->getAcc_n() == ID && accounts[i]->getPin() == Pass) {
				return accounts[i]->getPin();
			}
		}
	}

};