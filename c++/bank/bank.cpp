#include "bank.h"
#include <iostream>
#include <vector>
#include <iomanip>
using std::vector;
using std::setw;
using std::setprecision;
using std::setfill;
using std::fixed;
using std::cout;
using std::endl;
using std::cin;
using std::showpos;//if number > 0 ,than print '+' and this number
using std::noshowpoint;
using std::noshowpos;
using std::showpoint;

bank::bank(){
    this->root = new user_data;
    this->root->begin = NULL;
    this->root->end = NULL;
};

bank::~bank(){
}

bool bank::Print_bank_user(const ll& number){
    user_dataptr TMD = this->system_has_this_user(number);
    if(TMD == NULL){
        cout << "system not has this account number\n";
        return false;
    }
    this->Aid_print_user_data(TMD);
    return true;
}

void bank::Aid_print_user_data(const user_dataptr& ptr){
    cout << "account number is: " << ptr->number << "\nuser name is:" << ptr->name << "\nuser remain money is: " << showpoint << setprecision(6) << fixed << ptr->money << endl;
    cout << noshowpoint;
    if(ptr->history.empty())
        cout << "your's expense and revenue is empty!" << endl;
    else{
        cout << "then print your experse and revenue's history\n" << showpos;
        for(vector<double>::const_iterator begin = ptr->history.begin(), end = ptr->history.end(); begin != end; begin++)
            cout << *begin << "\t";
        cout << noshowpos;
    }
    cout << endl;
}

bool bank::Initialize_bank_user(const user_data& user){
    if(system_has_this_user(user.number)){
        cout << "we have the same account number, please input the other one!" << endl;
        return false;
    } 
    user_dataptr newuser = new user_data;
    newuser->money = user.money;
    newuser->name = user.name;
    newuser->number = user.number;
    user_dataptr TMD = root;
    if(root == NULL || (root->end != NULL && root->end->number > user.number)){
        newuser->begin = root;
        newuser->end =root->end;
        root->end = newuser;
        return true;
    }
    while(TMD->end != NULL && TMD->end->number < user.money)
        TMD = TMD->end;
    newuser->begin = TMD;
    newuser->end = TMD->end;
    TMD->end = newuser;
    return true;
}

user_dataptr bank::system_has_this_user(const ll& number){
    user_dataptr TMD = this->root;
    while(TMD != NULL){
        if(TMD->number == number)
            break;
        TMD = TMD->end;
    }
    if(TMD == NULL)
        return NULL;
    else return TMD;
}

bool bank::Delete_bank_user(const ll& number){
    user_dataptr delete_user = this->system_has_this_user(number);
    if(delete_user == NULL){
        cout << "system not has this account number\n";
        return false;
    }
    cout << "you want to delete this user:" << endl;
    this->Aid_print_user_data(delete_user);
    cout << "please be suer again you want to delete this user(Y/N): ";
    char char_choice;
    cin >> char_choice;
    if(char_choice == 'Y' || char_choice == 'y'){
        delete_user = delete_user->begin;
        delete_user->end->end->begin = delete_user;
        delete_user->end = delete_user->end->end;
        return true;       
    }
    return false;
}

bool bank::Expense_revenue(const ll& number,const double& money){
    user_dataptr ptr = this->system_has_this_user(number);
    if(ptr == NULL){
        cout << "system not has this account number\n";
        return false;
    }
    if(money < 0 && ptr->money + money < 0){
        cout << "you cann't expense $" << money << ",because you cann't have enough money" << endl;
        return false;
    }
    ptr->money += money;
    ptr->history.push_back(money);
    return true;
}

void menu(){
    cout << endl;
    cout << setw(35) << setfill(' ') << "welcome use bank system" << endl;
    cout << setw(20) << setfill(' ') << "insert new user" << setw(15) << setfill('-') << "1" << endl;
    cout << setw(20) << setfill(' ') << "delete user" << setw(15) << setfill('-') << "2" << endl;
    cout << setw(20) << setfill(' ') << "print user data" << setw(15) << setfill('-') << "3" << endl;
    cout << setw(20) << setfill(' ') << "Expense or revenue" << setw(15) << setfill('-') << '4' << endl;
    cout << setw(20) << setfill(' ') << "abort" << setw(15) << setfill('-') << "5" << endl;
    cout << "please input your choice: ";
}
