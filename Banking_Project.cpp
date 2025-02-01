#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
class Bank
{ // define bank class
	string name, actype;
	int acno, balance;

public:
	bool type(string ac)
	{ // function for deposite balance according to actype
		if (ac == "saving")
		{
			cout << "Enter the balance to be deposite  " << endl;
			cout << "min deposite : 1000" << endl;
			cin >> balance;
			if (balance >= 1000)
			{
				balance = balance;
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (ac == "current")
		{
			cout << "Enter the balance to be deposite  " << endl;
			cout << "min deposite : 5000" << endl;
			cin >> balance;
			if (balance >= 5000)
			{
				balance = balance;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	bool openaccount(int i)
	{ // function for open account  it return true if all detail is correct else return false
		cout << "Name of the canditate: ";
		cin >> name;
		cout << "select the account Type: " << endl;
		int choice;
	typ:
		cout << "1. saving" << endl;
		cout << "2. current " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			actype = "saving";
			break;
		case 2:
			actype = "current";
			break;
		default:
			cout << "select correct choice ";
			goto typ;
		}
		if (type(actype))
		{
			acno = i;
			cout << "Your account number is ";
			cout << acno << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	void deposite()
	{
		int d;
		cout << "Enter the deposite money " << endl;
		cin >> d;
	mode:
		cout << "which mode: " << endl;
		cout << "1. By check " << endl;
		cout << "2. By NEFT" << endl;
		cout << "3. By cash" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "By check" << endl;
			break;
		case 2:
			cout << "By NEFT" << endl;
			break;
		case 3:
			cout << "By cash" << endl;
			break;
		default:
			cout << "incorrect choice ";
			goto mode;
		}
		balance = balance + d;

		cout << "Your final balance is " << balance << endl;
	}
	void withdraw()
	{
		int w;
		cout << "Enter the withdraw money " << endl;
		cin >> w;

		if (w > balance)
		{
			cout << "Insufficient balance" << endl;
		}
		else
		{
			balance = balance - w;
			cout << "Your final balance is " << balance << endl;
		}
	}
	void showdetail()
	{
		cout << "account number " << acno << endl;
		;
		cout << "Name is " << name << endl;
		cout << "Final balance is " << balance << endl;
	}
	int getaccount()
	{
		return acno;
	}
};
int main()
{
	unordered_map<long long, Bank> b; // unordered_map for easily searching account and all detail of customer
	unordered_map<long long, int> p;
	Bank c;
	int k;
	static long long count = 705528;
	while (1)
	{
	menu:
		cout << "******* Main Menu *********" << endl;
		cout << "1. Open account " << endl;
		cout << "2. Deposite Money " << endl;
		cout << "3. withdraw Money " << endl;
		cout << "4. Account detail " << endl;
		cout << "5. Delete account " << endl;
		cout << "6. changed pin " << endl;
		cout << "7. close window" << endl;
		while (1)
		{
			int f = 0, acno, i;

			int choice;
			cout << "enter the choice" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				if (c.openaccount(count))
				{
					b.insert({count, c});
					cout << "******************" << endl;
					cout << "your account is successfully open " << endl;
					int pin;
					cout << "Set your account pin " << endl;
					cin >> pin;
					p.insert({count, pin});
					count++;
				}
				else
				{
					cout << "account not opened due to low deposite or invalid account type " << endl
						 << endl;
				}

				break;
			case 2:
				cout << "Enter the account number ";
				cin >> acno;
				if (b.find(acno) != b.end())
				{
					int pin;
					cout << "Enter the pin " << endl;
					cin >> pin;
					if (pin == p[acno])
					{
						b[acno].deposite();
					}
					else
					{
						cout << "Incorrect pin " << endl;
					}
				}
				else
				{
					cout << "account not found" << endl;
				}
				break;
			case 3:
				cout << "Enter the account number ";
				cin >> acno;
				if (b.find(acno) != b.end())
				{
					int pin;
					cout << "Enter the pin " << endl;
					cin >> pin;
					if (pin == p[acno])
					{
						b[acno].withdraw();
					}
					else
					{
						cout << "Incorrect pin " << endl;
					}
				}
				else
				{
					cout << "account not found" << endl;
				}
				break;
			case 4:
				cout << "Enter the account number ";
				cin >> acno;
				if (b.find(acno) != b.end())
				{
					int pin;
					cout << "Enter the pin " << endl;
					cin >> pin;
					if (pin == p[acno])
					{
						b[acno].showdetail();
					}
					else
					{
						cout << "Incorrect pin " << endl;
					}
				}
				else
				{
					cout << "account not found" << endl;
				}
				break;
			case 5:
				cout << "Enter the account number ";
				cin >> acno;
				if (b.find(acno) != b.end())
				{
					int pin;
					cout << "Enter the pin " << endl;
					cin >> pin;
					if (pin == p[acno])
					{
						b.erase(acno);
					}
					else
					{
						cout << "Incorrect pin " << endl;
					}
				}
				else
				{
					cout << "account not found" << endl;
				}
				break;
			case 6:
				cout << "Enter the account number ";
				cin >> acno;
				if (b.find(acno) != b.end())
				{
					int pin;
					cout << "Enter the pin " << endl;
					cin >> pin;
					if (pin == p[acno])
					{
						int p1;
						cout << "Enter the new pin " << endl;
						cin >> p1;
						p[acno] = p1;
						cout << endl
							 << "your pin is successfully changed" << endl;
					}
				}
				else
				{
					cout << "Incorrect pin " << endl;
				}
				break;

			case 7:

				goto label;
			default:
				cout << "Incorrect number";
			}
			int menu;
			cout << "press 9 for main menu " << endl;
			cin >> menu;
			if (menu == 9)
			{
				goto menu;
			}
		}
	}
label:
	cout << "Thank you for visiting us!!" << endl;
}
