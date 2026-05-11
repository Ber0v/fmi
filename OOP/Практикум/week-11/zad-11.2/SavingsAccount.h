#pragma once
#include "BankAccount.h"

class SavingsAccount : public BankAccount
{
public:
	SavingsAccount(double balance, double interestRate = 0);

	void applyInterest();
private:
	double interestRate;
};