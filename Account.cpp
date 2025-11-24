#include "Account.h"
#include <iostream>
using namespace std;

int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;

Account::Account(int accNumHelp, int codeHelp, string emailHelp)  // Accepts values and if one of the values is wrong then sets default values and throws an appropriate message
{
	if (codeHelp > 9999 || codeHelp < 1000)
		throw "ERROR: code must be of 4 digits!";
	else if (email.find('@') == -1)
		throw "ERROR: email must contain @!";
	else if (email.find(".com") != -1 || email.find(".co.il") != -1)
		throw "ERROR: email must end at .com or .co.il!";
	else
		accountNumber = accNumHelp, code = codeHelp, email = emailHelp;

}

istream& operator>>(istream& is, Account& a)
{
	string emailHelp;
	int accNumHelp, codeHelp, balanceHelp;
	is >> accNumHelp >> codeHelp >> emailHelp;
	if (codeHelp > 9999 || codeHelp < 1000)
		throw "ERROR: code must be of 4 digits!";
	else if (emailHelp.find('@') == -1)
		throw "ERROR: email must contain @!";
	else if (emailHelp.find(".com") == -1 && emailHelp.find(".co.il") == -1)
		throw "ERROR: email must end at .com or .co.il!";
	else
		a.accountNumber = accNumHelp, a.code = codeHelp, a.email = emailHelp;
	return is;
}

void Account::withdraw(int nis) //A method for withdrawing cash and checking otherwise throws an error
{
	if (balance - nis < (-6000))
		throw "ERROR: cannot have less than - 6000 NIS!";
	if (nis > 2500)
		throw "ERROR: cannot withdraw more than 2500 NIS!";
	else
	{
		balance -= nis;
		sumWithdraw += nis;
	}
}

void Account::deposit(int cashCheck) //A check deposit method throws an appropriate message if there is an error
{
	if (cashCheck > 10000)
		throw "ERROR: cannot deposit more than 10000 NIS!";
	else
	{
		balance += cashCheck;
		sumDeposit += cashCheck;
	}
}
