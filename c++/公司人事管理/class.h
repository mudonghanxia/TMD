#include <string>
#include <vector>
class Rerson
{
public:
	Rerson(int = 0,std::string = "",std::string = "",double = 0.0);
	~Rerson();
	//返回编号
	int Number();
	//返回名字
	std::string Name();
	//返回工资
	double Money();
	//返回岗位
	std::string Post();
protected:
	int number;//编号
	std::string name;//名字
	std::string post;//岗位
	double money;//工资
};
//技术人员
class Technician : public Rerson
{
public:
	bool operator==(Technician& A);//重载相等运算
	Technician(int = 0, std::string = "", std::string = "", int = 0);//构造函数
	virtual ~Technician();//析构函数
	bool operator<(Technician& A);//重载小于运算符
	//返回技术等级
	int& Age();
	//返回编号
	int Number();
	//返回名字
	std::string& Name();
	//返回工资
	double& Money();
	//返回岗位
	std::string& Post();
protected:
	int age = 0;//技术等级
};
//销售人员
class Salesman : public Rerson
{
public:
	bool operator==(Salesman& A);//重载相等运算符
	Salesman(int = 0, std::string = "", std::string = "", double = 0.0);//构造函数
	bool operator<(Salesman& A);//重载小于运算符
	virtual ~Salesman();
	//返回销售额
	double& Sales_Voume();
	//返回总销售额
	double All_Sales_Voume();
	//返回编号
	int Number();
	//返回名字
	std::string& Name();
	//返回工资
	double& Money();
	//返回岗位
	std::string& Post();
	static double all_sales_voume;//总销售额
protected:
	double sales_voume;//销售额
};
//经理
class Manager :public Rerson
{
public:
	bool operator==(Manager& A);//重载相同运算符
	static Manager* Manager_One(int = 0, std::string = "", std::string = "");//伪构造函数
	virtual ~Manager();//析构函数
	//返回编号
	int Number();
	//返回名字
	std::string& Name();
	//返回工资
	double& Money();
	//返回岗位
	std::string& Post();
	bool operator<(Manager& A);
	static int one;
private:
	Manager(int = 0, std::string = "", std::string = "");//单例模式确保存在一个经理
};
//销售经理
class Sales_Manager :  public Rerson
{
public:
	bool operator==(Sales_Manager& A);//存在相同函数
	static Sales_Manager* Sales_Manager_One(int = 0, std::string = "", std::string = "");//伪构造函数
	virtual ~Sales_Manager();//析构函数
	//返回编号
	int Number();
	//返回名字
	std::string& Name();
	//返回工资
	double& Money();
	//返回岗位
	std::string& Post();
	bool operator<(Sales_Manager& A);
	static int one;
private:
	Sales_Manager(int = 0, std::string = "", std::string = "");//制造函数
};
class Manage
{
public:
	Manage();//构造函数
	~Manage();//析构函数
	bool Push_Manager(int, std::string, Manage&);//添加经理
	bool Push_Sales_Manager(int, std::string, Manage&);//添加销售经理
	bool Push_Salesman(int, std::string, double, Manage&);//添加销售人员
	bool Push_Technician(int, std::string, int, Manage&);//添加技术人员
	void Pop_Manager();//弹出经理
	void Pop_Sales_Manager();//弹出销售经理
	void Pop_Salesman(int);//弹出销售人员
	void Pop_Technician(int);//弹出技术人员
	bool Find_Number(int);//查找是否存在相同的编码
	bool Show_Manager();//输出经理数据
	bool Show_Technician(int);//输出技术人员数据
	void Show_All_Technician();//输出全部技术人员的数据
	bool Show_Sales_Manager();//输出销售经理的数据
	bool Show_Salesman(int);//输出销售人员的数据
	void Show_All_Salesman();//输出全部销售人员的数据
	void Find_Name(std::string);//按姓名查找
	bool Empty_Manager(int&);//判断当前系统中是否存在经理
	bool Empty_Sales_Manager(int&);//判断当前系统中是否存在销售经理
	void Show_Sort_Month_Money_Salesman();//显示排序后的销售人员
	void Show_Sort_Month_Money_Technician();//显示排序后的技术人员
	bool Manager_Want_Change_Job_To(std::string, Manage&, int, std::string);//经理转职
	bool Sales_Manager_Want_Change_Job_To(std::string, Manage&, int, std::string);//销售经理转职
	bool Salesman_Want_Change_Job_To(std::string, Manage&, int, std::string);//销售人员转职
	bool Technician_Want_Change_Job_To(std::string, Manage&, int, std::string);//技术人员转职
	bool Manage_Manager(std::string&);//给经理编码赋值
	bool Manage_Sales_Manager(std::string&);//给销售经理编码赋值
	bool Manage_Slesman(int&, std::string&);//给销售人员的编码下的各项数据赋值
	bool Manage_Technician(int&, std::string&);//给技术人员编码下的各项数据赋值
	void In_File();//写入文件函数
	void Out_File();//写出文件函数
private:
	std::vector<Manager> manager;
	std::vector<Manager>::iterator ptr_Manager;
	std::vector<Sales_Manager>sales_manager;
	std::vector<Sales_Manager>::iterator ptr_Sales_Manager;
	std::vector<Salesman>salesman;
	std::vector<Salesman>::iterator ptr_Salesman;
	std::vector<Technician>technician;
	std::vector<Technician>::iterator ptr_Technician;
};
