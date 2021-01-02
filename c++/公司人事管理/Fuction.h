#include <iostream>
#include "class.h"
#include <string>
void Function_1(std::string&,int& , Manage&);//添加人员
bool Function_choice_1(std::string& choice_, int& choice_1);
void Function_choice_2(std::string& choice_, int& choice_1);
void Function_choice_3(std::string& choice_, int& choice_1);
bool Function_choice_4(int& number, std::string post, Manage& manage,int);
bool Function_show(int number, std::string post, Manage& manage);
void Function_2(std::string choice_, int& choice_1, Manage& manage);//修改信息
void Function_3(std::string choice_, int& choice_1, Manage& manage);//浏览信息
void Function_4(Manage& manage);//按姓名查找
void Function_5(std::string choice_, int& choice_1, Manage& manage);//月薪排序
