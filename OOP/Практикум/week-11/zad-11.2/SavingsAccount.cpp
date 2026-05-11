#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double balance, double interestRate)
	:BankAccount(balance), interestRate(interestRate)
{
	if (interestRate < 0)
		throw std::invalid_argument("Invalid interest rate");
}

void SavingsAccount::applyInterest()
{
	double interest = Balance * interestRate / 100;

	deposit(interest);
}
