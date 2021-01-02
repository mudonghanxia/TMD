#include <string>
#include <vector>
using std::vector;
using std::string;
#ifndef bank_
#define bank_
typedef long long ll;
typedef struct data_{
    ll number;//bank account number
    string name;//user name
    double money;//user remain money
    vector<double> history;//expense or revenue's history
    struct data_* begin;
    struct data_* end;
}user_data;

typedef user_data* user_dataptr;
class bank{
public:
    bank();
    ~bank();
    /**
     * insert new user
     * @param user [type is user_data] all user data
     * @return if insert success, return true,else return false
    */
    bool Initialize_bank_user(const user_data& user);
    /**
     * delete user
     * @param number [type is long long] delete user's bank account number
     * @return if delete success, then return true. else return false
    */
    bool Delete_bank_user(const ll& number);
    /**
     * print this-> user all data
     * @param number [type is long long] user account number
     * @return if print success, return true; else return false
    */
    bool Print_bank_user(const ll& number);
    /**
     * have or not have account number
     * @param number [type is long long] user account number
     * @return if We has this account number, return this account number's pointer,else return NULL
    */
    user_dataptr system_has_this_user(const ll& number);
    /**
     * insert user expense and revenue's history
     * @param number [type is long long] user account number
     * @param money [type is double] if money > 0, is expense, else if money < 0, is revenue, else no take
     * @return if insert success, return true; else return false
    */
    bool Expense_revenue(const ll& number,const double& money);
private:
    user_dataptr root;//all user_pointer begin
    /**
     * print this->pointer's all data
     * @param ptr [type is user_dataptr*] pointer
    */
    void Aid_print_user_data(const user_dataptr& ptr);
};

// print menu 
void menu();
#endif
