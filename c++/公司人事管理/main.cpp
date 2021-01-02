#include <iostream>
#include <string>
#include<algorithm>
#include <fstream>
#include "Function.h"
using namespace std;

int main()
{
	enum leixing { 添加人员, 修改信息, 浏览信息, 按姓名查找, 月薪排序, 退出};
	string choice_ = " ";
	int choice_1 = 0;
	Manage manage;
	manage.Out_File();
	std::cout << "     ************************\n";
	std::cout << "     * 欢迎来到人事管理系统 *\n";
	std::cout << "     ************************\n";
	std::cout << "注意：本系统全程搜索和操作按照编号实现，可重名，不可重编号！" << endl;
	std::cout << "      系统开始运行前会从数据库中调用上次的数据，正常退出会保存数据！" << endl;
	while (1)
	{
		cout << "可供选择的操作类型有：添加人员，修改信息，浏览信息，按姓名查找，月薪排序，退出";
		cout << "请输入您想操作的类型 :\n";
		cin >> choice_;
		if (!Function_choice_1(choice_, choice_1)) 
			choice_1 = -1;
		if (choice_ == "退出")
		{
			cout << "感谢使用人事管理系统！系统祝您工作顺利*__* 再见！" << endl;
			break;
		}
		switch (choice_1)
		{
		case 添加人员:
		{
			Function_1(choice_, choice_1, manage);
			break;
		}
		case 修改信息:
		{
			Function_2(choice_, choice_1, manage);
			break;
		}
		case 浏览信息:
		{
			Function_3(choice_, choice_1, manage);
			break;
		}
		case 按姓名查找:
		{
			Function_4(manage);
			break;
		}
		case 月薪排序:
		{
			Function_5(choice_, choice_1, manage);
			break;
		}
		default:
		{
			cout << "输入有误，请重新操作！" << endl;
			break;
		}
		}
	}
	manage.In_File();
	return 0;
}
