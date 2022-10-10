#ifndef ACCOUNT_H
#define ACCOUNT_H

#pragma once
#include <iostream>
#include <cstring>

using namespace std;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
private:
    int accID;
    int balance;
    char* cusName;

public:
    Account(int ID, int money, char* name);
    ~Account();
    int GetAccID();
    void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo();
};

#endif