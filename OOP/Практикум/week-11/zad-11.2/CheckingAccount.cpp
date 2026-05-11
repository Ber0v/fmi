#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(double balance, double overdraftLimit)
	:BankAccount(balance), overdraftLimit(overdraftLimit)
{
	if (overdraftLimit < 0)
		throw std::invalid_argument("Invalid overdraft limit");
}

void CheckingAccount::withdraw(double amount)
{
	if (amount <= 0)
		throw std::invalid_argument("Invalid amount");

	if (Balance - amount < -overdraftLimit)
		throw std::invalid_argument("Not enough money");

	Balance -= amount;
	totalMoney -= amount;
}
