#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "class.h"
enum leixing { 添加人员, 修改信息, 浏览信息, 按姓名查找, 月薪排序, 退出, 经理, 技术人员, 销售人员, 销售经理, 继续, 编号, 名字, 删除, 职位, 技术等级, 销售额, 单个查询, 整体查询 };
bool Function_choice_1(std::string& choice_, int& choice_1){
	if (choice_ == "添加人员")
	{
		choice_1 = 添加人员;
		return true;
	}
	if (choice_ == "修改信息")
	{
		choice_1 = 修改信息;
		return true;
	}
	if (choice_ == "浏览信息")
	{
		choice_1 = 浏览信息;
		return true;
	}
	if (choice_ == "按姓名查找")
	{
		choice_1 = 按姓名查找;
		return true;
	}
	if (choice_ == "月薪排序")
	{
		choice_1 = 月薪排序;
		return true;
	}
	return false;
}
bool Function_choice_2(std::string& choice_, int& choice_1)
{
	std::cout << "可供选择的操作类型有：经理，技术人员，销售人员，销售经理,退出\n";
	std::cout << "请输入您想操作的类型: ";
	std::cin >> choice_;
	if (choice_ == "经理")
	{
		choice_1 = 经理;
		return true;
	}
	if (choice_ == "技术人员")
	{
		choice_1 = 技术人员;
		return true;
	}
	if (choice_ == "销售人员")
	{
		choice_1 = 销售人员;
		return true;
	}
	if (choice_ == "销售经理")
	{
		choice_1 = 销售经理;
		return true;
	}
	return false;
}
void Function_choice_3(std::string& choice_, int& choice_1)
{
	while (1)
	{
		std::cout << "可供操作类型：继续、退出：";
		std::cout << "请输入您想操作的类型: ";
		std::cin >> choice_;
		if (choice_ != "继续" && choice_ != "退出")
		{
			std::cout << "输入错误，请重新选择操作类型：" << std::endl;
		}
		if (choice_ == "退出" || choice_ == "继续")
			break;
	}
}
bool Function_show(int number,std::string post,Manage& manage)
{
	if (post == "经理" && manage.Show_Manager())
		return true;
	if (post == "技术人员" && manage.Show_Technician(number))
		return true;
	if (post == "销售人员" && manage.Show_Salesman(number))
		return true;
	if (post == "销售经理" && manage.Show_Sales_Manager())
		return true;
	return false;
}
bool Function_choice_4(int& number, std::string post, Manage& manage,int A = 0)
{

	if (A == 1)//修改
	{
		if ((post == "经理" && manage.Empty_Manager(number)) || (post == "销售经理" && manage.Empty_Sales_Manager(number)))
		{
			std::cout << "不存在" << post << "，无法修改！" << std::endl;
			return false;
		}
		else if (post == "经理" || post == "销售经理")
			return true;
		std::cout << "请输入被操作" << post << "的编号：";
		std::cin >> number;
		std::cout << "操作前的信息为:" << std::endl;
		Function_show(number, post, manage);
		return true;
	}
	if (A == 0)//添加
	{
		std::cout << "请输入被操作" << post << "的编号：";
		std::cin >> number;
		if (!manage.Find_Number(number))
		{
			std::cout << "操作前的信息为:" << std::endl;
			Function_show(number, post, manage);
			return true;
		}
		return false;
	}
	return true;
}
void Function_1(std::string& choice_, int& choice_1, Manage& manage)
{
	int number;
	int age;
	std::string name;
	double sales_voume;
	while (1)
	{
		if (!Function_choice_2(choice_, choice_1)) 
			choice_1 = -1;
		if (choice_ == "退出")
			break;
		switch (choice_1)
		{
		case 经理:
		{
			if (Manager::one == 1)
				std::cout << "已存在经理，请勿重复操作!" << std::endl;
			else
			{
				std::cout << "请输入被添加经理的编号：";
				std::cin >> number;
				if (!manage.Find_Number(number))
				{
					std::cout << "请输入被添加经理的名字：";
					std::cin >> name;
					manage.Push_Manager(number, name, manage);
				}
			}
			break;
		}
		case 技术人员:
		{
			while (1)
			{
				std::cout << "请输入被添加技术人员的编号：";
				std::cin >> number;
				if (!manage.Find_Number(number))
				{
					std::cout << "请输入被添加技术人员的名字：";
					std::cin >> name;
					std::cout << "请输入被添加技术人员的技术等级；";
					std::cin >> age;
					manage.Push_Technician(number, name, age, manage);
					Function_choice_3(choice_, choice_1);
					if (choice_ == "退出")
						break;
				}
			}
			break;
		}
		case 销售人员:
		{
			while (1)
			{
				std::cout << "请输入被添加销售人员的编号：";
				std::cin >> number;
				if (!manage.Find_Number(number))
				{
					std::cout << "请输入被添加销售人员的名字：";
					std::cin >> name;
					std::cout << "请输入被添加销售人员的销售额；";
					std::cin >> sales_voume;
					manage.Push_Salesman(number, name, sales_voume, manage);
					Function_choice_3(choice_, choice_1);
					if (choice_ == "退出")
						break;
				}
			}
			break;
		}
		case 销售经理:
		{
			if (Sales_Manager::one == 1)
				std::cout << "已存在销售经理，请勿重复操作!" << std::endl;
			else
			{
				std::cout << "请输入被添加销售经理的编号：";
				std::cin >> number;
				if (!manage.Find_Number(number))
				{
					std::cout << "请输入被添加销售经理的名字：";
					std::cin >> name;
					manage.Push_Sales_Manager(number, name, manage);
				}
			}
			break;
		}
		default:
		{
			std::cout << "输入错误，请重新操作\n";
			break;
		}
		}
	}
}
void Function_2(std::string choice_, int& choice_1, Manage& manage)
{
	int number;//编号
	std::string name;//名字
	int age;//技术等级
	std::string post1;//函数内职位
	double sales_voume;//销售额
	std::string post;//职位
	std::cout << "请输入需要修改的职位" << std::endl;
	std::cin >> post;
	while (1)
	{
		if (post == "经理" || post == "销售经理")
		{
			std::cout << "可供选择的类型有:删除、职位、退出\n请问您想操作什么？";
		}
		else if (post == "技术人员")
		{
			std::cout << "可供选择的类型有:删除、职位、退出、技术等级\n请问您想操作什么？" ;
		}
		else if (post == "销售人员")
		{
			std::cout << "可供选择的类型有:删除、职位、销售额、退出\n请问您想操作什么？";
		}
		else
		{
			std::cout << "输入有误，请重新操作！" << std::endl;
		}
		std::cin >> choice_;
		if (choice_ == "删除")
			choice_1 = 删除;
		else if (choice_ == "职位")
			choice_1 = 职位;
		else if (choice_ == "技术等级")
			choice_1 = 技术等级;
		else if (choice_ == "销售额")
			choice_1 = 销售额;
		else if (choice_ == "退出")
			break;
		else
		{
			std::cout << "输入有误，请重新操作！" << std::endl;
			continue;
		}
		if ((post == "经理" || post == "销售经理") && (choice_1 == 技术等级 || choice_1 == 销售额)
			|| (post == "技术人员" && choice_1 == 销售额)
			|| (post == "销售人员" && choice_1 == 技术等级))
		{
			std::cout << "输入有误！请重新操作！" << std::endl;
			continue;
		}
		switch (choice_1)
		{
		case 删除:
		{
			while (1)
			{
				if (Function_choice_4(number, post, manage,1))
				{
					std::cout << "确认操作？（确认、不确认）：";
					std::cin >> choice_;
					if (choice_ == "确认")
					{
						if (post == "经理")
							manage.Pop_Manager();
						if (post == "技术人员")
							manage.Pop_Technician(number);
						if (post == "销售人员")
							manage.Pop_Salesman(number);
						if (post == "销售经理")
							manage.Pop_Sales_Manager();
					}
					else if (choice_ == "不确认")
						std::cout << "以取消操作!" << std::endl;
					else
						std::cout << "输入错误，请重新操作！" << std::endl;
				}
				Function_choice_3(choice_, choice_1);
				if (choice_ == "退出")
					break;
			}
			break;
		}
		case 职位:
		{
			while (1)
			{
				if (Function_choice_4(number, post, manage,1))
				{
					std::cout << "请输入操作后的" << post << "的职位:";
					std::cin >> post1;
					std::cout << "确认操作？（确认、不确认）：";
					std::cin >> choice_;
					if (choice_ == "确认")
					{
						if (post == "经理")
							manage.Manager_Want_Change_Job_To(post1, manage, number, name);
						if (post == "技术人员")
							manage.Technician_Want_Change_Job_To(post1, manage, number, name);
						if (post == "销售人员")
							manage.Salesman_Want_Change_Job_To(post1, manage, number, name);
						if (post == "销售经理")
							manage.Sales_Manager_Want_Change_Job_To(post1, manage, number, name);
					}
					else if (choice_ == "不确认")
						std::cout << "以取消操作!" << std::endl;
					else
						std::cout << "输入错误，请重新操作！" << std::endl;
				}
				Function_choice_3(choice_, choice_1);
				if (choice_ == "退出")
					break;
			}
			break;
		}
		case 技术等级:
		{
			while (1)
			{
				if (Function_choice_4(number, post, manage,1))
				{
					std::cout << "请输入操作后的" << post << "的技术等级:";
					std::cin >> age;
					std::cout << "确认操作？（确认、不确认）：";
					std::cin >> choice_;
					if (choice_ == "确认")
					{
						manage.Pop_Technician(number);
						manage.Push_Technician(number, name, age, manage);
						std::cout << "操作成功" << std::endl;
						std::cout << "修改后的信息为:" << std::endl;
						Function_show(number, post, manage);
					}
					else if (choice_ == "不确认")
						std::cout << "以取消操作!" << std::endl;
					else
						std::cout << "输入错误，请重新操作！" << std::endl;
				}
				Function_choice_3(choice_, choice_1);
				if (choice_ == "退出")
					break;
			}
			break;
		}
		case 销售额:
		{
			while (1)
			{
				if (Function_choice_4(number, post, manage,1))
				{
					std::cout << "请输入操作后的" << post << "的销售额:";
					std::cin >> sales_voume;
					std::cout << "确认操作？（确认、不确认）：";
					std::cin >> choice_;
					if (choice_ == "确认")
					{
						manage.Pop_Salesman(number);
						manage.Push_Salesman(number, name, sales_voume, manage);
						std::cout << "操作成功" << std::endl;
						std::cout << "修改后的信息为:" << std::endl;
						Function_show(number, post, manage);
					}
					else if (choice_ == "不确认")
						std::cout << "以取消操作!" << std::endl;
					else
						std::cout << "输入错误，请重新操作！" << std::endl;
				}
				Function_choice_3(choice_, choice_1);
				if (choice_ == "退出")
					break;
			}
			break;
		}
		default:
		{
			std::cout << "输入有误，请重新操作!" << std::endl;
			break;
		}
		}
	}
}
void Function_3(std::string choice_, int& choice_1, Manage& manage)
{
	int number;//编码
	std::string post;//职位
	while (1)
	{
		std::cout << "请输入需要浏览的职位或者选择退出" << std::endl;
		std::cin >> post;
		if (post == "退出")
			break;
		if (post == "经理" && manage.Show_Manager() || post == "销售经理" && !manage.Show_Sales_Manager())
			continue;
		else if (post == "经理" || post == "销售经理")
			continue;
		else if (post != "技术人员" && post != "销售人员")
		{
			std::cout << "输入有误，请重新操作！" << std::endl;
			continue;
		}
		std::cout << "可供操作类型：单个查询，整体查询，退出：";
		std::cin >> choice_;
		if (choice_ == "单个查询")
			choice_1 = 单个查询;
		if (choice_ == "整体查询")
			choice_1 = 整体查询;
		switch (choice_1)
		{
		case 单个查询:
		{
			while (1)
			{
				std::cout << "请输入您想查询" << post <<"的编码:";
				std::cin >> number;
				if (post == "技术人员")
					manage.Show_Technician(number);
				if (post == "销售人员")
					manage.Show_Salesman(number);
				Function_choice_3(choice_, choice_1);
				if (choice_ == "退出")
					break;
			}
			break;
		}
		case 整体查询:
		{
			while (1)
			{
				if (post == "技术人员")
					manage.Show_All_Technician();
				if (post == "销售人员")
					manage.Show_All_Salesman();
				Function_choice_3(choice_, choice_1);
				if (choice_ == "退出")
					break;
			}
			break;
		}
		default:
		{
			std::cout << "输入错误，请重新操作" << std::endl;
			break;
		}
		}
	}
}
void Function_4(Manage& manage)
{
	std::string name;//名字
	std::cout << "请输入查找的姓名：";
	std::cin >> name;
	manage.Find_Name(name);
}
void Function_5(std::string choice_, int& choice_1, Manage& manage)
{
	while (1)
	{
		Function_choice_2(choice_,choice_1);
		if (choice_ == "退出")
			break;
		switch (choice_1)
		{
		case 技术人员:
		{
			manage.Show_Sort_Month_Money_Technician();
			std::cout << "排序后的结果为：" << std::endl;
			manage.Show_All_Technician();
			break;
		}
		case 销售人员:
		{
			manage.Show_Sort_Month_Money_Salesman();
			std::cout << "排序后的结果：" << std::endl;
			manage.Show_All_Salesman();
			break;
		}
		case 经理:
		{
			std::cout << "本系统只允许出现一个经理，以下输出当前经理数据：" << std::endl;
			manage.Show_Manager();
			break;
		}
		case 销售经理:
		{
			std::cout << "本系统只允许出现一个销售经理，以下输出当前销售经理数据：" << std::endl;
			manage.Show_Sales_Manager();
			break;
		}
		default:
		{
			std::cout << "输入错误，请重新操作!" << std::endl;
			break;
		}
		}
	}
}
