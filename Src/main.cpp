/*
 * BankingSystem ver 0.2
 * 작성자 : 김정훈
 * 내용 : Account Class 정의, 객체 포인터 배열 적용
 */

#include "Account.h"

using namespace std;
const int NAME_LEN = 20;

void ShowMenu();
void MAkeAccount();
void DepositMoney();
void WithdrawrMoney();
void ShowAllAccInfo();

Account *accArr[100];
int accNum = 0;

int main()
{
    int choice;

    while(1)
    {
        ShowMenu();
        cout << "선택 : ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case MAKE:
                MAkeAccount();
            break;

            case DEPOSIT:
                DepositMoney();
            break;

            case WITHDRAW:
                WithdrawrMoney();
            break;

            case INQUIRE:
                ShowAllAccInfo();
            break;

            case EXIT:
                for(int i=0; i<accNum; i++)
                {
                    delete accArr[i];
                }
                return 0;
            break;
            
            default:
                cout << "Illegal Selection!!" << endl;
        }
    }

    return 0;
}

void ShowMenu()
{
    cout << "-----Menu------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void MAkeAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[계좌개설]" << endl;
    cout << "계좌 ID : "; cin >> id;
    for(int i=0; i<accNum; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            cout << "이미 존재하는 ID입니다." << endl << endl;
            return;
        }
    }
    cout << "이 름 : "; cin >> name;
    cout << "입금액 : "; cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney()
{
    int money;
    int id;
    cout << "[입   금]" << endl;
    cout << "계좌 ID : "; cin >> id;
    cout << "입금액 : "; cin >> money;
    
    for(int i=0; i<accNum; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            accArr[i]->Deposit(money);
            cout << "입금 완료" << endl << endl;
            return;
        }
    }
    cout << "유효하지 않은 ID입니다." << endl << endl;
}

void WithdrawrMoney()
{
    int money;
    int id;
    cout << "[출   금]" << endl;
    cout << "계좌 ID : "; cin >> id;
    cout << "입금액 : "; cin >> money;
    
    for(int i=0; i<accNum; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            if(accArr[i]->Withdraw(money) == 0)
            {
                cout << "잔액 부족" << endl << endl;
                return;
            }
            cout << "출금 완료" << endl << endl;
        }
    }
    cout << "유효하지 않은 ID입니다." << endl << endl;
}

void ShowAllAccInfo()
{
    for(int i=0; i<accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }  
}




 
  
