#include "Account.h"

Account::Account(int ID, int money, char* name)
: accID(ID), balance(money)
{
    cusName = new char[strlen(name)+1];
    strcpy(cusName, name);
}

Account::~Account()
{
    delete[] cusName;
}

int  Account::GetAccID()
{
    return accID;
}

void  Account::Deposit(int money)
{
    balance += money;
}

int Account::Withdraw(int money)
{
    if(balance < money)
        return 0;
    balance -= money;
    return money;
}

void Account::ShowAccInfo()
{
    cout << "°èÁÂID : " << accID << endl;
    cout << "ÀÌ ¸§ : " << cusName << endl;
    cout << "ÀÜ ¾× : " << balance << endl;
}

