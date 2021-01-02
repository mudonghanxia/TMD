#include "bank.h"
#include <iostream>
using std::cout;
using std::cin;
int main (){
    bank mybank;
    user_data user;
    string name;
    ll account_number;
    double initialize_money;
    int choice = 0;
    while(choice != 5){
        cout << '\n';
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:{
            cout << "please input account number: ";
            cin >> user.number;
            if(user.number < 0){
                cout << "you cann't initialize account number less than 0\n";
                break;
            }
            cout << "please input user name: ";
            cin >> user.name;
            cout << "please input initialize money: ";
            cin >> user.money;
            if(user.money < 0){
                cout << "you cann't initialize money less than 0\n";
                break;
            }
            mybank.Initialize_bank_user(user);
            break;
        }
        case 2:{
            cout << "please input you want delete account number: ";
            cin >> user.number;
            mybank.Delete_bank_user(user.number);
            break;
        }
        case 3:{
            cout << "please input you want look account number: ";
            cin >> user.number;
            mybank.Print_bank_user(user.number); 
            break;
        }
        case 4:{
            cout << "please input you Expense or revenue account number and money: ";
            cin >> user.number >> user.money;
            mybank.Expense_revenue(user.number,user.money);
            break;
        }
        case 5:{
            break;
        }
        default:
            cout << "your's choice is mistake,please input again\n";
        }
    }
    cout << "system is close, welcome again use";
    return 0;
}
