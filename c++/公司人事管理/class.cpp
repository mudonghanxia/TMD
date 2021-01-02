#include "class.h"
#include <iostream>
#include <algorithm>
#include<vector>
#include <fstream>
#include <iomanip>
Rerson::Rerson(int _number, std::string _name, std::string _post,double _money)
	:number(_number),name(_name),post(_post),money(_money)
{}
Rerson::~Rerson()
{}
int Rerson::Number()
{
	return number;
}
std::string Rerson::Name()
{
	return name;
}
double Rerson::Money()
{
	return money;
}
std::string Rerson::Post()
{
	return post;
}
Technician::Technician(int _number, std::string _name, std::string _post,int _age)
	:Rerson(_number,_name,_post),age(_age)
{
	Technician::money = 1.0 * (1600 + 300 * 1.0 * this->age);
}
bool Technician::operator==(Technician& A)
{
	if (A.Age() == this->Age() && A.Money() == this->Money() && A.Name() == this->Name() && A.Number() == this->Number() && A.Post() == this->Post())
	{
		return true;
	}
	else
		return false;
}
bool Technician::operator<(Technician& A)
{
	if (this->Money() < A.Money())
	{
		return true;
	}
	return false;
}
Technician::~Technician()
{}
int& Technician::Age()
{
	return this->age;
}
int Technician::Number()
{
	return Technician::number;
}
std::string& Technician::Name()
{
	return Technician::name;
}
double& Technician::Money()
{
	return Technician::money;
}
std::string& Technician::Post()
{
	return Technician::post;
}
Salesman::Salesman(int _number, std::string _name, std::string _post, double _sales_voume)
	:Rerson(_number, _name, _post), sales_voume(_sales_voume)
{
	this->all_sales_voume += this->sales_voume;
	Salesman::money = 0.04 * this->sales_voume;
}
bool Salesman::operator==(Salesman& A)
{
	if (A.Money() == this->Money() && A.Name() == this->Name() && A.Number() == this->Number() && A.Post() == this->Post() && A.Sales_Voume() == this->Sales_Voume())
	{ 
		return true;
	}
	else
		return false;
}
double Salesman::all_sales_voume = 0;
double Salesman::All_Sales_Voume()
{
	return Salesman::all_sales_voume;
}
bool Salesman::operator<(Salesman& A)
{
	if (this->Money() < A.Money())
	{
		return true;
	}
	return false;
}
double& Salesman::Sales_Voume()
{
	return this->sales_voume;
}
Salesman::~Salesman()
{
	this->all_sales_voume -= this->sales_voume;
}
int Salesman::Number()
{
	return Salesman::number;
}
std::string& Salesman::Name()
{
	return Salesman::name;
}
double& Salesman::Money()
{
	return Salesman::money;
}
std::string& Salesman::Post()
{
	return Salesman::post;
}
int Manager::one = 0;
Manager* Manager::Manager_One(int _number, std::string _name, std::string _post)
{
	if (Manager::one == 0)
	{
		Manager::one = 1;
		return (new(Manager)(_number, _name, _post));
	}
	std::cout << "经理已经存在一位，不可重复添加" << std::endl;
	return NULL;
}
Manager::Manager(int _number, std::string _name, std::string _post)
	:Rerson(_number, _name, _post)
{
	Manager::money = 8000;
}
Manager::~Manager()
{
	one = 0;
}
bool Manager::operator<(Manager& A)
{
	if (this->Money() < A.Money())
	{
		return true;
	}
	return false;
}
bool Manager::operator==(Manager& A)
{
	if (A.Money() ==this->Money() && A.Name() == this->Name() && A.Number() == this->Number() && A.Post() == this->Post())
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Manager::Number()
{
	return Manager::number;
}
std::string& Manager::Name()
{
	return Manager::name;
}
double& Manager::Money()
{
	return Manager::money;
}
std::string& Manager::Post()
{
	return Manager::post;
}
Sales_Manager::Sales_Manager(int _number, std::string _name, std::string _post)
	:Rerson(_number, _name, _post)
{
	Sales_Manager::money = 8000 + (1500 + 0.002 * Salesman::all_sales_voume);
}
int Sales_Manager::one = 0;
Sales_Manager* Sales_Manager::Sales_Manager_One(int _number, std::string _name, std::string _post)
{
	if (one == 0)
	{
		one = 1;
		return (new(Sales_Manager)(_number, _name, _post));
	}
	std::cout << "销售经理已经存在一位，不可重复添加" << std::endl;
	return NULL;
}
bool Sales_Manager::operator<(Sales_Manager& A)
{
	if (this->Money() < A.Money())
	{
		return true;
	}
	return false;
}
Sales_Manager::~Sales_Manager()
{}
bool Sales_Manager::operator==(Sales_Manager& A)
{
	if (A.Money() == this->Money() && A.Name() == this->Name() && A.Number() == this->Number() && A.Post() == this->Post())
		return true;
	return false;
}
int Sales_Manager::Number()
{
	return Sales_Manager::number;
}
std::string& Sales_Manager::Name()
{
	return Sales_Manager::name;
}
double& Sales_Manager::Money()
{
	return Sales_Manager::money;
}
std::string& Sales_Manager::Post()
{
	return Sales_Manager::post;
}
Manage::Manage()
{}
Manage::~Manage()
{}
bool Manage::Push_Manager(int number, std::string name, Manage& manage)
{
	if (manage.Find_Number(number))
	{
		std::cout << "系统中存在与该编号，请重新修改！" << std::endl;
		return false;
	}
	if (Manager::one == 0)
	{
		Manager* ptr = Manager::Manager_One(number, name, "经理");
		manager.push_back(*ptr);
		return true;
	}
	else
	std::cout << "已经存在一位经理，不可重复添加！" << std::endl;
	return false;
}
bool Manage::Push_Sales_Manager(int number, std::string name, Manage& manage)
{
	if (manage.Find_Number(number))
	{
		std::cout << "系统中存在与该编号，请重新修改！" << std::endl;
		return false;
	}
	if (Sales_Manager::one == 0)
	{
		Sales_Manager* ptr = Sales_Manager::Sales_Manager_One(number, name, "销售经理");
		sales_manager.push_back(*ptr);
		return true;
	}
	else
		std::cout << "已经存在一位销售经理，不可重复添加！" << std::endl;
		return false;
}
bool Manage::Push_Salesman(int number, std::string name, double sales_voume,Manage& manage)
{
	if (manage.Find_Number(number))
	{
		std::cout << "系统中存在与该编号，请重新修改！" << std::endl;
		return false;
	}
	salesman.push_back(Salesman(number, name, "销售人员", sales_voume));
	return true;
}
bool Manage::Push_Technician(int number, std::string name, int age,Manage& manage)
{
	if (manage.Find_Number(number))
	{
		std::cout << "系统中存在与该编号，请重新修改！" << std::endl;
		return false;
	}
	if (age > 0 && age < 8)
	{
		technician.push_back(Technician(number, name, "技术人员", age));
		return true;
	}
	else
	{
		std::cout << "技术等级超出范围，请重新操作！" << std::endl;
		return false;
	}
}
void Manage::Pop_Manager()
{
	if (!manager.empty())
	{
		manager.erase(manager.begin());
		return;
	}
	std::cout << std::endl << "没有目标，删除失败！请重新操作！" << std::endl;
}
void Manage::Pop_Salesman(int A)
{
	for (ptr_Salesman = salesman.begin(); ptr_Salesman != salesman.end(); ptr_Salesman++)
	{
		if (ptr_Salesman->Number() == A)
		{
			salesman.erase(ptr_Salesman);
			return;
		}
	}
	std::cout << std::endl << "没有目标，删除失败！请重新操作！" << std::endl;
}
void Manage::Pop_Sales_Manager()
{
	if (!sales_manager.empty())
	{
		sales_manager.erase(ptr_Sales_Manager);
		return;
	}
	std::cout << std::endl << "没有目标，删除失败！请重新操作！" << std::endl;
}
void Manage::Pop_Technician(int A)
{
	for (ptr_Technician = technician.begin(); ptr_Technician != technician.end(); ptr_Technician++)
	{
		if (ptr_Technician->Number() == A)
		{
			technician.erase(ptr_Technician);
			return;
		}
	}
	std::cout << std::endl << "没有目标，删除失败！请重新操作！" << std::endl;
}
bool Manage::Find_Number(int number)
{
	for (ptr_Manager = manager.begin(); ptr_Manager < manager.end(); ptr_Manager++)
	{
		if (ptr_Manager->Number() == number)
		{
			std::cout << "编号重复，请重新输入！" << std::endl;
			return true;
		}
	}
	for (ptr_Salesman = salesman.begin(); ptr_Salesman < salesman.end(); ptr_Salesman++)
	{
		if (ptr_Salesman->Number() == number)
		{
			std::cout << "编号重复，请重新输入！" << std::endl;
			return true;
		}
	}
	for (ptr_Sales_Manager = sales_manager.begin(); ptr_Sales_Manager < sales_manager.end(); ptr_Sales_Manager++)
	{
		if (ptr_Sales_Manager->Number() == number)
		{
			std::cout << "编号重复，请重新输入！" << std::endl;
			return true;
		}
	}
	for (ptr_Technician = technician.begin(); ptr_Technician < technician.end(); ptr_Technician++)
	{
		if (ptr_Technician->Number() == number)
		{
			std::cout << "编号重复，请重新输入！" << std::endl;
			return true;
		}
	}
	return false;
}
bool Manage::Show_Manager()
{
	if (!manager.empty())
	{
		ptr_Manager = manager.begin();
		std::cout << "名字:" << ptr_Manager->Name() << std::endl;
		std::cout << "编号:" << std::setw(9) << std::setfill('0') << ptr_Manager->Number() << std::endl;
		std::cout << "职位:" << ptr_Manager->Post() << std::endl;
		std::cout << "月薪:" << ptr_Manager->Money() << std::endl;
		return true;
	}
	std::cout << "没有目标，请重新操作" << std::endl;
	return false;
}
bool Manage::Show_Technician(int A)
{
	for (ptr_Technician = technician.begin(); ptr_Technician != technician.end(); ptr_Technician++)
	{
		if (ptr_Technician->Number() == A)
		{
			std::cout << "名字:" << ptr_Technician->Name() << std::endl;
			std::cout << "编号:" << std::setw(9) << std::setfill('0') << ptr_Technician->Number() << std::endl;
			std::cout << "职位:" << ptr_Technician->Post() << std::endl;
			std::cout << "技术等级" << ptr_Technician->Age() << std::endl;
			std::cout << "月薪" << ptr_Technician->Money() << std::endl;
			return true;
		}
	}
	std::cout << "没有目标，请重新操作" << std::endl;
	return false;
}
void Manage::Show_All_Technician()
{
	for (ptr_Technician = technician.begin(); ptr_Technician != technician.end(); ptr_Technician++)
	{
			std::cout << "名字:" << ptr_Technician->Name() << std::endl;
			std::cout << "编号:" << std::setw(9) << std::setfill('0') << ptr_Technician->Number() << std::endl;
			std::cout << "职位:" << ptr_Technician->Post() << std::endl;
			std::cout << "技术等级" << ptr_Technician->Age() << std::endl;
			std::cout << "月薪" << ptr_Technician->Money() << std::endl;
	}
}
bool Manage::Show_Salesman(int A)
{
	for (ptr_Salesman = salesman.begin(); ptr_Salesman != salesman.end(); ptr_Salesman++)
	{
		if (ptr_Salesman->Number() == A)
		{
			std::cout << "名字:" << ptr_Salesman->Name() << std::endl;
			std::cout << "编号:" << std::setw(9) << std::setfill('0') << ptr_Salesman->Number() << std::endl;
			std::cout << "职位:" << ptr_Salesman->Post() << std::endl;
			std::cout << "销售额" << ptr_Salesman->Sales_Voume() << std::endl;
			std::cout << "月薪" << ptr_Salesman->Money() << std::endl;
			return true;
		}
	}
	std::cout << "没有目标，请重新操作" << std::endl;
	return false;
}
void Manage::Show_All_Salesman()
{
	for (ptr_Salesman = salesman.begin(); ptr_Salesman != salesman.end(); ptr_Salesman++)
	{
			std::cout << "名字:" << ptr_Salesman->Name() << std::endl;
			std::cout << "编号:" << std::setw(9) << std::setfill('0') << ptr_Salesman->Number() << std::endl;
			std::cout << "职位:" << ptr_Salesman->Post() << std::endl;
			std::cout << "销售额" << ptr_Salesman->Sales_Voume() << std::endl;
			std::cout << "月薪" << ptr_Salesman->Money() << std::endl;
	}
}
bool Manage::Show_Sales_Manager()
{
	if (!sales_manager.empty())
	{
		ptr_Sales_Manager = sales_manager.begin();
		std::cout << "名字:" << ptr_Sales_Manager->Name() << std::endl;
		std::cout << "编号:" << std::setw(9) << std::setfill('0') << ptr_Sales_Manager->Number() << std::endl;
		std::cout << "职位:" << ptr_Sales_Manager->Post() << std::endl;
		std::cout << "月薪" << ptr_Sales_Manager->Money() << std::endl;
		return true;
	}
	std::cout << "没有目标，请重新操作" << std::endl;
	return false;
}
bool Manage::Empty_Manager(int &number)
{
	if (manager.empty())
		return true;
	else
	{
		ptr_Manager = manager.begin();
		number = ptr_Manager->Number();
		return false;
	}
}
bool Manage::Empty_Sales_Manager(int & number)
{
	if (sales_manager.empty())
		return true;
	else
	{
		ptr_Sales_Manager = sales_manager.begin();
		number = ptr_Sales_Manager->Number();
		return false;
	}
}
void Manage::Find_Name(std::string name)
{
	ptr_Manager = manager.begin();
	int sum = 0;
	if (!manager.empty() && ptr_Manager->Name() == name)
	{
		std::cout << "名字:" << ptr_Manager->Name() << std::endl;
		std::cout << "编号:" << std::setw(9) << std::setfill('0') << ptr_Manager->Number() << std::endl;
		std::cout << "职位:" << ptr_Manager->Post() << std::endl;
		std::cout << "月薪" << ptr_Manager->Money() << std::endl;
		sum++;
	}
	ptr_Sales_Manager = sales_manager.begin();
	if (!sales_manager.empty() && ptr_Sales_Manager->Name() == name)
	{
		std::cout << "名字:" << ptr_Sales_Manager->Name() << std::endl;
		std::cout << "编号:" << std::setw(9) << std::setfill('0') << ptr_Sales_Manager->Number() << std::endl;
		std::cout << "职位:" << ptr_Sales_Manager->Post() << std::endl;
		std::cout << "月薪" << ptr_Sales_Manager->Money() << std::endl;
		sum++;
	}
	for (ptr_Technician = technician.begin(); ptr_Technician != technician.end(); ptr_Technician++)
	{
		if (ptr_Technician->Name() == name)
		{
			std::cout << "名字:" << ptr_Technician->Name() << std::endl;
			std::cout << "编号:" << std::setw(9) << std::setfill('0') << ptr_Technician->Number() << std::endl;
			std::cout << "职位:" << ptr_Technician->Post() << std::endl;
			std::cout << "技术等级" << ptr_Technician->Age() << std::endl;
			std::cout << "月薪" << ptr_Technician->Money() << std::endl;
			sum++;
		}
	}
	for (ptr_Salesman = salesman.begin(); ptr_Salesman != salesman.end(); ptr_Salesman++)
	{
		if (ptr_Salesman->Name() == name)
		{
			std::cout << "名字:" << ptr_Salesman->Name() << std::endl;
			std::cout << "编号:" << std::setw(9) << std::setfill('0') << ptr_Salesman->Number() << std::endl;
			std::cout << "职位:" << ptr_Salesman->Post() << std::endl;
			std::cout << "销售额" << ptr_Salesman->Sales_Voume() << std::endl;
			std::cout << "月薪" << ptr_Salesman->Money() << std::endl;
			sum++;
		}
	}
	if (sum == 0)
	std::cout << "没有目标，请重新操作" << std::endl;
}
void Manage::Show_Sort_Month_Money_Salesman()
{
	sort(salesman.begin(), salesman.end());
}
void Manage::Show_Sort_Month_Money_Technician()
{
	sort(technician.begin(), technician.end());
}
bool Manage::Manager_Want_Change_Job_To(std::string Want_Job ,Manage& manage,int number,std::string name)
{
	if (Want_Job == "经理")
	{
		std::cout << "目前已经是经理，转职失效！" << std::endl;
		return false;
	}
	manage.Manage_Manager(name);
	manage.Pop_Manager();
	if (Want_Job == "销售经理")
		manage.Push_Sales_Manager(number, name, manage);
	if (Want_Job == "技术人员")
	{
		int age;
		std::cout << "请输入被添加技术人员的技术等级；";
		std::cin >> age;
		technician.push_back(Technician(number, name, "技术人员", age));
	}
	if (Want_Job == "销售人员")
	{
		double sales_voume;
		std::cout << "请输入被添加销售人员的销售额；";
		std::cin >> sales_voume;
		salesman.push_back(Salesman(number, name, "销售人员", sales_voume));
	}
	std::cout << "以成功转职！" << std::endl;
	return true;
}
bool Manage::Sales_Manager_Want_Change_Job_To(std::string Want_Job, Manage& manage, int number, std::string name)
{
	if (Want_Job == "销售经理")
	{
		std::cout << "目前已经是销售经理，转职失效！" << std::endl;
		return false;
	}
	manage.Manage_Sales_Manager(name);
	manage.Pop_Sales_Manager();
	if (Want_Job == "经理")
		manage.Push_Manager(number, name, manage);
	if (Want_Job == "技术人员")
	{
		int age;
		std::cout << "请输入被添加技术人员的技术等级；";
		std::cin >> age;
		technician.push_back(Technician(number, name, "技术人员", age));
	}
	if (Want_Job == "销售人员")
	{
		double sales_voume;
		std::cout << "请输入被添加销售人员的销售额；";
		std::cin >> sales_voume;
		salesman.push_back(Salesman(number, name, "销售人员", sales_voume));
	}
	std::cout << "以成功转职！" << std::endl;
	return true;
}
bool Manage::Salesman_Want_Change_Job_To(std::string Want_Job, Manage& manage, int number, std::string name)
{
	if (Want_Job == "销售人员")
	{
		std::cout << "目前已经是销售人员，转职失效！" << std::endl;
		return false;
	}
	manage.Manage_Slesman(number, name);
	manage.Pop_Salesman(number);
	if (Want_Job == "销售经理")
		manage.Push_Sales_Manager(number, name, manage);
	if (Want_Job == "经理")
		manage.Push_Manager(number, name, manage);
	if (Want_Job == "技术人员")
	{
		int age;
		std::cout << "请输入被添加技术人员的技术等级；";
		std::cin >> age;
		technician.push_back(Technician(number, name, "技术人员", age));
	}
	std::cout << "以成功转职！" << std::endl;
	return true;
}
bool Manage::Technician_Want_Change_Job_To(std::string Want_Job, Manage& manage, int number, std::string name)
{
	if (Want_Job == "技术人员")
	{
		std::cout << "目前已经是技术人员，转职失效！" << std::endl;
		return false;
	}
	manage.Manage_Technician(number, name);
	manage.Pop_Technician(number);
	if (Want_Job == "经理")
		manage.Push_Manager(number, name, manage);
	if (Want_Job == "销售经理")
		manage.Push_Sales_Manager(number, name, manage);
	if (Want_Job == "销售人员")
	{
		double sales_voume;
		std::cout << "请输入被添加销售人员的销售额；";
		std::cin >> sales_voume;
		salesman.push_back(Salesman(number, name, "销售人员", sales_voume));
	}
	std::cout << "以成功转职！" << std::endl;
	return true;
}
bool Manage::Manage_Manager(std::string& name)
{
	if (manager.empty())
		return false;
	ptr_Manager = manager.begin();
	name = ptr_Manager->Name();
	return true;
}
bool Manage::Manage_Sales_Manager(std::string& name)
{
	if (sales_manager.empty())
		return false;
	ptr_Sales_Manager = sales_manager.begin();
	name = ptr_Sales_Manager->Name();
	return true;
}
bool Manage::Manage_Slesman(int& number, std::string& name)
{
	for (ptr_Salesman = salesman.begin(); ptr_Salesman != salesman.end(); ptr_Salesman++)
	{
		if (ptr_Salesman->Number() == number)
		{
			name = ptr_Salesman->Name();
			return true;
		}
	}
	return false;
}
bool Manage::Manage_Technician(int& number, std::string& name)
{
	for (ptr_Technician = technician.begin(); ptr_Technician != technician.end(); ptr_Technician++)
	{
		if (ptr_Technician->Number() == number)
		{
			name = ptr_Technician->Name();
			return true;
		}
	}
	return false;
}
void Manage::In_File()
{
	std::ofstream in;
	in.open("Rerson.txt", std::ios::out);
	if (!in)
	{
		std::cerr << "File was not open!" << std::endl;
		exit(-1);
	}
	if (!manager.empty())
	{
		ptr_Manager = manager.begin();
		in << ptr_Manager->Post() << " " << ptr_Manager->Name() << " " << ptr_Manager->Number() << "\n";
	}
	if (!sales_manager.empty())
	{
		ptr_Sales_Manager = sales_manager.begin();
		in << ptr_Sales_Manager->Post() << " " << ptr_Sales_Manager->Name() << " " << ptr_Sales_Manager->Number() << "\n";
	}
	if (!salesman.empty())
	{
		ptr_Salesman = salesman.begin();
		while (ptr_Salesman != salesman.end())
		{
			in << ptr_Salesman->Post() << " " << ptr_Salesman->Name() << " " << ptr_Salesman->Number() << " " << ptr_Salesman->Sales_Voume() << "\n";
			ptr_Salesman++;
		}
	}
	if (!technician.empty())
	{
		ptr_Technician = technician.begin();
		while (ptr_Technician != technician.end())
		{
			in << ptr_Technician->Post() << " " << ptr_Technician->Name() << " " << ptr_Technician->Number() << " " << ptr_Technician->Age() << "\n";
			ptr_Technician++;
		}
	}
	in.close();
	return;
}
void Manage::Out_File()
{
	int number;
	std::string name;
	std::string post;
	double sales_voume;
	int age;
	std::ifstream out;
	out.open("Rerson.txt", std::ios::in);
	if (!out)
	{
		std::cerr << "File was not been open!" << std::endl;
		exit(-1);
	}
	while (out >> post)
	{
		if (post == "经理")
		{
			out >> name >> number;
			this->Push_Manager(number, name,*this);
 		}
		if (post == "销售经理")
		{
			out >> name >> number;
			this->Push_Sales_Manager(number, name,*this);
		}
		if (post == "技术人员")
		{
			out >> name >> number >> age;
			this->Push_Technician(number, name, age, *this);
		}
		if (post == "销售人员")
		{
			out >> name >> number >> sales_voume;
			this->Push_Salesman(number, name, sales_voume, *this);
		}
	}
	out.close();
}
