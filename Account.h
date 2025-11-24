#pragma once
#include <iostream>
using namespace std;
class Account
{

	int accountNumber;
	int code;
	int balance;
	string email;
public:
	Account() :accountNumber(0), code(0), balance(0), email("") {}; //An empty constructor that sets 0
	Account(int accNumHelp, int codeHelp, string emailHelp);

	friend istream& operator>>(istream& is, Account& a);
	int getAccountNumber() { return accountNumber; };
	int getCode() { return code; };
	int getBalance() { return balance; };
	string getEmail() { return email; };

	void withdraw(int nis);
	void deposit(int cashCheck);

	static int sumWithdraw;//Counts the amount of all withdrawals from bank accounts
	static int sumDeposit; //Counts the sum of all deposits in the bank

	static int getSumWithdraw() { return sumWithdraw; };// A method that returns the sum of all withdrawals from all accounts together
	static int getSumDeposit() { return sumDeposit; }; // A method that returns the amount of all checks deposited so far.
};
