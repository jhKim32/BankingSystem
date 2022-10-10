/*
 * BankingSystem ver 0.2
 * �ۼ��� : ������
 * ���� : Account Class ����, ��ü ������ �迭 ����
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
        cout << "���� : ";
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
    cout << "1. ���°���" << endl;
    cout << "2. �� ��" << endl;
    cout << "3. �� ��" << endl;
    cout << "4. �������� ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;
}

void MAkeAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[���°���]" << endl;
    cout << "���� ID : "; cin >> id;
    for(int i=0; i<accNum; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            cout << "�̹� �����ϴ� ID�Դϴ�." << endl << endl;
            return;
        }
    }
    cout << "�� �� : "; cin >> name;
    cout << "�Աݾ� : "; cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney()
{
    int money;
    int id;
    cout << "[��   ��]" << endl;
    cout << "���� ID : "; cin >> id;
    cout << "�Աݾ� : "; cin >> money;
    
    for(int i=0; i<accNum; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            accArr[i]->Deposit(money);
            cout << "�Ա� �Ϸ�" << endl << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void WithdrawrMoney()
{
    int money;
    int id;
    cout << "[��   ��]" << endl;
    cout << "���� ID : "; cin >> id;
    cout << "�Աݾ� : "; cin >> money;
    
    for(int i=0; i<accNum; i++)
    {
        if(accArr[i]->GetAccID() == id)
        {
            if(accArr[i]->Withdraw(money) == 0)
            {
                cout << "�ܾ� ����" << endl << endl;
                return;
            }
            cout << "��� �Ϸ�" << endl << endl;
        }
    }
    cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void ShowAllAccInfo()
{
    for(int i=0; i<accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }  
}




 
  
