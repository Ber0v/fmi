#include "BankAccount.h"

unsigned BankAccount::ID = 1;
double BankAccount::totalMoney = 0;

BankAccount::BankAccount(double Balance)
	:AccountNumber(ID++), Balance(Balance)
{
	if (Balance < 0)
		throw std::invalid_argument("Invalid balance");

	totalMoney += Balance;
}

BankAccount BankAccount::operator+(BankAccount& other)
{
	double sum = Balance + other.Balance;

	Balance = 0;
	other.Balance = 0;
	totalMoney -= sum;

	return BankAccount(sum);
}

bool BankAccount::operator==(const BankAccount& other) const
{
	return this->Balance == other.Balance;
}

void BankAccount::deposit(double amount)
{
	if (amount <= 0) throw std::invalid_argument("Error");

	Balance += amount;
	totalMoney += amount;
}

void BankAccount::withdraw(double amount)
{
	if (amount <= 0)
		throw std::invalid_argument("Invalid amount");

	if (amount > Balance)
		throw std::invalid_argument("Not enough money");

	Balance -= amount;
	totalMoney -= amount;
}

std::ostream& operator<<(std::ostream& os, const BankAccount& acc)
{
	return os << acc.AccountNumber << " " << acc.Balance;
}
