#ifndef CHECKINGS_H_INCLUDED
#define CHECKINGS_H_INCLUDED
#pragma once
#include "Account.h"

class Checkings : public Account  //inheritence from base class 'account'
{
private:
	double c_balance = 0;

public:
	void setBalance(double deposit);
	double getBalance() const;
	void setWithdraw();
	void setDeposit();
	double getTransfer();

};


#endif // CHECKINGS_H_INCLUDED
