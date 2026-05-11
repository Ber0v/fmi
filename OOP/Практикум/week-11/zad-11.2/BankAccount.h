#pragma once
#include <ostream>
class BankAccount
{
public:
	BankAccount(double Balance = 0);

	BankAccount operator+(BankAccount& other);
	bool operator==(const BankAccount& other) const;
	friend std::ostream& operator<<(std::ostream& os, const BankAccount& acc);

	void deposit(double amount);
	void withdraw(double amount);

	unsigned getAccountNumber() const { return AccountNumber; }
	double getBalace() const { return Balance; }
	static double getTotalMoney() { return totalMoney; }

private:
	static unsigned ID;
	const unsigned AccountNumber;

protected:
	static double totalMoney;
	double Balance;
};