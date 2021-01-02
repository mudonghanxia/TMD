#include <iostream>
#include <easyx.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

enum E_snake { 向上w = 119, 向上W = 87, 向下s = 115, 向下S = 83, 向左a = 97, 向左A = 65, 向右d = 100, 向右D = 68, 空格 = 32 };
int x = 0;
int y = 0;
char choice;
class  C_snake
{
public:
	C_snake() {};
	int x[1000];
	int y[1000];
	static int size;
	static bool Over;//结束
	static bool Eat_Food;
	//下一步是否食得食物
	bool Food_Eat( const char&);
	//判断食物是否生成在蛇身
	bool Food_in_snake();
	//判断撞墙
	bool snake_will_snake(const char&);
	//游戏初始化
	static void Game_for_bengin();
}snake;
//正式进入游戏内容
void Play_Game();
//游戏结束
bool Game_Over();
//游戏帮助提示
void Game_help();
//游戏界面化
void Game();
//界面处理,食物坐标
void Draw_Game_play();
//蛇移动，兼判断是否撞墙
bool snake_move(const char&);
void Game()
{
	initgraph(500, 500);
	settextcolor(BLUE);
	setbkcolor(WHITE);
	cleardevice();
	srand(unsigned(time(NULL)));
	settextstyle(20, 10, "黑体",10,10,200,1,1,0);
	outtextxy(100, 150, "*****欢迎来到贪吃蛇游戏！*******\0");
	settextstyle(20, 10, "宋体", 8, 8, 20, 0, 0, 0);
	setfillcolor(LIGHTCYAN);
	setbkmode(LIGHTCYAN);
	fillrectangle(190, 220, 280, 250);
	outtextxy(195, 225, "开始游戏");
	fillrectangle(190, 280, 280, 310);
	outtextxy(195, 285, "结束游戏");
	fillrectangle(190, 340, 280, 370);
	outtextxy(195, 345, "查看帮助");
	MOUSEMSG p;
	while (1)
	{
		p = GetMouseMsg();
		if ((p.x >= 190 && p.x <= 280) && (p.y >= 220 && p.y <= 250))
		{
			setfillcolor(CYAN);
			fillrectangle(190, 220, 280, 250);
			outtextxy(195, 225, "开始游戏");
			if (p.uMsg == WM_LBUTTONDOWN)
			{
				Play_Game();
				Game_Over();
			}
		}
		else
		{
			setfillcolor(LIGHTCYAN);
			fillrectangle(190, 220, 280, 250);
			outtextxy(195, 225, "开始游戏");
		}
		if ((p.x >= 160 && p.x <= 300) && (p.y >= 270 && p.y <= 310))
		{
			setfillcolor(CYAN);
			fillrectangle(190, 280, 280, 310);
			outtextxy(195, 285, "结束游戏");
			if (p.uMsg == WM_LBUTTONDOWN)
				exit(0);
		}
		else
		{
			setfillcolor(LIGHTCYAN);
			fillrectangle(190, 280, 280, 310);
			outtextxy(195, 285, "结束游戏");
		}
		if ((p.x >= 160 && p.x <= 300) && (p.y >= 310 && p.y <= 370))
		{
			setfillcolor(CYAN);
			fillrectangle(190, 340, 280, 370);
			outtextxy(195, 345, "查看帮助");
			if (p.uMsg == WM_LBUTTONDOWN)
			Game_help();
		}
		else
		{
			setfillcolor(LIGHTCYAN);
			fillrectangle(190, 340, 280, 370);
			outtextxy(195, 345, "查看帮助");
		}
	}
}

void Play_Game()//正式进入游戏内容
{
	char foot = 'd';
	snake.x[0] = 250;
	snake.y[0] = 250;
	initgraph(520, 520);
	settextstyle(10, 10, "宋体");
	Draw_Game_play();
	outtextxy(250, 250, '*');
	while (true)
	{
		do //防止食物生成在蛇身上
			if (C_snake::Eat_Food)
			{
				x = rand() % 400 + 50;
				y = rand() % 400 + 50;
				C_snake::Eat_Food = false;
			}
			else
				break;
		while (!snake.Food_in_snake());
		outtextxy(x, y, '*');
		switch (int(foot)) //按键操作
		{
		case 空格:
		{
			C_snake::Over = true;
			break;
		}
		case 向左a:
		case 向左A:
		{
			snake_move('a');
			break;
		}
		case 向下s:
		case 向下S:
		{
			snake_move('s');
			break;
		}
		case 向右d:
		case 向右D:
		{
			snake_move('d');
			break;
		}
		case 向上w:
		case 向上W:
		{
			snake_move( 'w');
			break;
		}
		default:
			break;
		}
		if (C_snake::Over == true)
			break;
		while (!_kbhit())
		{
			snake_move(foot);
			if (C_snake::Eat_Food == true || C_snake::Over == true)
				break;
			Sleep(100);
		}
		if (C_snake::Over == true)
			break;
		if (C_snake::Eat_Food != true)
		{
			choice = _getch();
			if (choice == 'w' || choice == 'a' || choice == 's' || choice == 'd' || choice == ' ')
			foot = choice;
		}
	}
	return ;
}
bool Game_Over()//游戏结束
{
	initgraph(400, 150);
	setbkcolor(RED);
	cleardevice();
	settextcolor(WHITE);
	settextstyle(20,10, "楷体");
	outtextxy(20, 0, "得分:");
	char s[10];
	_stprintf(s, _T("%d"), C_snake::size);
	outtextxy(120, 0, s);
	outtextxy(20, 50, "游戏结束，选择以下选项");
	rectangle(20, 100, 100, 130);
	outtextxy(40, 104, "复活");
	rectangle(140, 100, 240, 130);
	outtextxy(150, 104, "重新开始");
	rectangle(280, 100, 380, 130);
	outtextxy(288, 104, "退出游戏");
	setbkmode(GREEN);
	MOUSEMSG p;
	while (1)
	{
		setlinecolor(WHITE);
		rectangle(20, 100, 100, 130);
		rectangle(140,100, 240, 130);
		rectangle(280,100, 380, 130);
		p = GetMouseMsg();
		while ((p.x >= 20 && p.x <= 100) && (p.y >= 100 && p.y <= 130))
		{
			p = GetMouseMsg();
			setlinecolor(LIGHTMAGENTA);
			rectangle(20, 100, 100, 130);
			if (p.uMsg == WM_LBUTTONDOWN)
			{
				C_snake::Over = false;
				Play_Game();				
				Game_Over();
			}
		}
		while ((p.x >= 140 && p.x <= 240) && (p.y >= 100 && p.y <= 130))
		{
			p = GetMouseMsg();
			setlinecolor(LIGHTMAGENTA);
			rectangle(140, 100, 240, 130);
			if (p.uMsg == WM_LBUTTONDOWN)
			{
				C_snake::Game_for_bengin();
				Play_Game();
				Game_Over();
			}
		}
		while ((p.x >= 280 && p.x <= 380) && (p.y >= 100 && p.y <= 130))
		{
			p = GetMouseMsg();
			setlinecolor(LIGHTMAGENTA);
			rectangle(280, 100, 380, 130);
			if (p.uMsg == WM_LBUTTONDOWN)
			{
				exit(0);
			}
		}
	}
}
void Game_help()//游戏帮助提示
{
	cleardevice();//清除屏幕
	outtextxy(0, 0, "1. w向左移动");
	outtextxy(0, 20, "2. s向下移动");
	outtextxy(0, 40, "3. a向左移动");
	outtextxy(0, 60, "4. d向右移动");
	outtextxy(0, 80, "5. 注意一切按键均以英文输入法下，中文无法识别");
	outtextxy(0, 100, "6. 蛇头撞墙会死亡，但是接触自己不会死亡");
	outtextxy(0, 120, "7. 按空格退出游戏");
	outtextxy(0, 140, "点击鼠标退出帮助界面");
	char a = '\0';
	MOUSEMSG p;
	while (1)
	{
		p = GetMouseMsg();
		if (p.uMsg == WM_LBUTTONDOWN && p.x >= 0 && p.x <= 600 && p.y >= 0 && p.y <= 600)
			break;
	}
	Game();
}
void Draw_Game_play()
{
	cleardevice();
	line(10, 10, 10, 500);
	line(14, 10, 14, 500);
	line(18, 10, 18, 500);
	line(10, 10, 500, 10);
	line(10, 14, 500, 14);
	line(10, 18, 500, 18);
	line(10, 500, 500, 500);
	line(10, 496, 500, 496);
	line(10, 492, 500, 492);
	line(500, 10, 500, 500);
	line(496, 10, 496, 500);
	line(492, 10, 492, 500);
}

 int C_snake::size = 0;
 bool C_snake::Over = false;
 bool C_snake::Eat_Food = true;
 bool snake_move(const char& choice)
{
	 Draw_Game_play();
	 if (!snake.Food_Eat(choice))
		 outtextxy(x, y, '*');
	 for (int a = C_snake::size; a >= 1; a--)
	 {
		 snake.x[a] = snake.x[a - 1];
		 snake.y[a] = snake.y[a - 1];
	 }
	 if (choice == 'a')
		 snake.x[0] -= 5;
	 if (choice == 's')
		 snake.y[0] += 5;
	 if (choice == 'w')
		 snake.y[0] -= 5;
	 if (choice == 'd')
		 snake.x[0] += 5;
	 if (snake.snake_will_snake(choice))
	 {
		 C_snake::Over = true;
		 return false;
	 }
	 for (int a = C_snake::size; a >= 0; a--)
	 {
		 outtextxy(snake.x[a], snake.y[a], '*');
	 } 
	 return true;
}

 bool C_snake::Food_Eat(const char& choice)
 {
	 switch (int(choice))
	 {
	 case 向上w:
	 {
		 if (this->x[0] >= ::x - 3 && this->x[0] <= ::x + 13 && this->y[0] - 5 >= ::y - 3 && this->y[0] - 5 <= ::y + 13)
		 {
			 C_snake::size++;
			 this->Eat_Food = true;
			 return true;
		 }
		 return false;
	 }
	 case 向下s:
	 {
		 if (this->x[0] >= ::x - 3 && this->x[0] <= ::x + 13 && this->y[0] + 5 >= ::y - 3 && this->y[0] + 5 <= ::y + 13)
		 {
			 C_snake::size++;
			 this->Eat_Food = true;
			 return true;
		 }
		 return false;
	 }
	 case 向左a:
	 {
		 if (this->x[0] - 5 >= ::x - 3 && this->x[0] - 5 <= ::x + 13 && this->y[0] >= ::y - 3 && this->y[0] <= ::y + 13)
		 {
			 C_snake::size++;
			 this->Eat_Food = true;
			 return true;
		 }
		 return false;
	 }
	 case 向右d:
	 {
		 if (this->x[0] + 5 >= ::x - 3 && this->x[0] + 5 <= ::x + 13 && this->y[0] >= ::y - 3 && this->y[0] <= ::y + 13)
		 {
			 C_snake::size++;
			 this->Eat_Food = true;
			 return true;
		 }
		 return false;
	 }
	 }
	 return true;
 }

 bool C_snake::Food_in_snake()
 {
	 for (int a = 0; a <= this->size; a++)
	 {
		 if (this->x[a] >= ::x && this->x[a] <= ::x + 10 && this->y[a] >= ::y && this->y[a] <= ::y + 10)
		 {
			 return true;
		 }
	 }
	 return false;
 }

 bool C_snake::snake_will_snake(const char& choice)
 {
	 switch (int(choice))
	 {
	 case 向上w:
	 {
		 if (this->y[0] <= 18)
			 return true;
		 return false;
	 }
	 case 向下s:
	 {
		 if (this->y[0] >= 482)
			 return true;
		 return false;
	 }
	 case 向左a:
	 {
		 if (this->x[0] <= 18)
			 return true;
		 return false;
	 }
	 case 向右d:
	 {
		 if (this->x[0] >= 482)
			 return true;
		 return false;
	 }
	 }
	 return true;
 }

 void C_snake::Game_for_bengin()
 {
	C_snake::size = 0;
	C_snake::Over = false;//结束
	C_snake::Eat_Food = true;
 }

 int main()
 {
	 Game();
	 return 0;
 }
