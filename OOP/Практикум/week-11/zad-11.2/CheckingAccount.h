#pragma once
#include"BankAccount.h"
class CheckingAccount : public BankAccount
{
public:
	CheckingAccount(double balance, double overdraftLimit = 0);

	void withdraw(double amount);

private:
	double overdraftLimit;
};