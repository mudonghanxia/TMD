#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
enum choice{None,Up = 1,Down,Right,Left};
typedef struct point{
    int x;//横
    int y;//纵
    choice begin_way;//上一步方向
    choice next_way;//下一步方向
}Point;
typedef Point* Pointptr;
class labyrinth{
private:
    vector<Pointptr> point_vecotr;//vector保存方向
    string way[5];//输出方向
    int** array;//二维数组
    int length;//迷宫的横
    int width;//迷宫的纵
    /**
     * 辅助函数
     * @param begin_way 当前没有墙可以走的方向
    */
    bool Aid_function(choice begin_way);
public:
    /**
     * 迷宫的构造函数
     * @param width 行
     * @param length 列
    */
    labyrinth(int width,int length);
    /**
     * 迷宫的数据输入
     * @param width 行
     * @param length 列
     * @param data 数据
    */
    void initialize(int width, int length, int data);
    //进入迷宫
    void game();
    //判断该方向是否为墙
    bool game_load();
    //输出方案
    void print();
};
bool labyrinth::Aid_function(choice begin_way){
    Pointptr newpoint = new point;
    newpoint->begin_way = this->point_vecotr.back()->begin_way;
    newpoint->x = this->point_vecotr.back()->x;
    newpoint->y = this->point_vecotr.back()->y;
    switch (begin_way)
    {
        case Up:{
            this->array[newpoint->x][newpoint->y] = 1;
            newpoint->x -= 1;
            this->point_vecotr.back()->next_way = Up;
            newpoint->begin_way = Up;
            this->point_vecotr.push_back(newpoint);
            return true;
        }
        case Left:{
            this->array[newpoint->x][newpoint->y] = 1;
            newpoint->y -= 1;
            this->point_vecotr.back()->next_way = Left;
            newpoint->begin_way = Left;
            this->point_vecotr.push_back(newpoint);
            return true;       
        }
        case Right:{
            this->array[newpoint->x][newpoint->y] = 1;
            newpoint->y += 1;
            this->point_vecotr.back()->next_way = Right;
            newpoint->begin_way = Right;
            this->point_vecotr.push_back(newpoint);
            return true;
        }
        case Down:{
            this->array[newpoint->x][newpoint->y] = 1;
            newpoint->x += 1;
            this->point_vecotr.back()->next_way = Down;
            newpoint->begin_way = Down;
            this->point_vecotr.push_back(newpoint);
            return true;
        }
    }
}
bool labyrinth::game_load(){
    switch(this->point_vecotr.back()->begin_way){
        case Up:{
            if(!this->array[this->point_vecotr.back()->x][this->point_vecotr.back()->y + 1] && Aid_function(Right)) return true;//Right
            if(!this->array[this->point_vecotr.back()->x][this->point_vecotr.back()->y - 1] && Aid_function(Left)) return true;//Left
            if(!this->array[this->point_vecotr.back()->x - 1][this->point_vecotr.back()->y] && Aid_function(Up)) return true;//Up
            return false;
        }
        case Down:{
            if(!this->array[this->point_vecotr.back()->x + 1][this->point_vecotr.back()->y] && Aid_function(Down)) return true;//Down
            if(!this->array[this->point_vecotr.back()->x][this->point_vecotr.back()->y + 1] && Aid_function(Right)) return true;//Right
            if(!this->array[this->point_vecotr.back()->x][this->point_vecotr.back()->y - 1] && Aid_function(Left)) return true;//Left
            return false;
        }
        case Left:{
            if(!this->array[this->point_vecotr.back()->x + 1][this->point_vecotr.back()->y] && Aid_function(Down)) return true;//Down
            if(!this->array[this->point_vecotr.back()->x][this->point_vecotr.back()->y - 1] && Aid_function(Left)) return true;//Left           
            if(!this->array[this->point_vecotr.back()->x - 1][this->point_vecotr.back()->y] && Aid_function(Up)) return true;//Up
            return false;
        }
        case Right:{
            if(!this->array[this->point_vecotr.back()->x + 1][this->point_vecotr.back()->y] && Aid_function(Down)) return true;//Down
            if(!this->array[this->point_vecotr.back()->x][this->point_vecotr.back()->y + 1] && Aid_function(Right)) return true;//Right
            if(!this->array[this->point_vecotr.back()->x - 1][this->point_vecotr.back()->y] && Aid_function(Up)) return true;//Up
            return false;
        }
    }
}
void labyrinth::game(){
    Pointptr newpoint;
    newpoint = new point;
    newpoint->x = 1;
    newpoint->y = 1;
    newpoint->next_way = None;
    newpoint->begin_way = Right;
    point_vecotr.push_back(newpoint);
    while(point_vecotr.back()->x != this->width || point_vecotr.back()->y != this->length){
        if(!game_load()){
            this->array[this->point_vecotr.back()->x][this->point_vecotr.back()->y] = 1;
            this->point_vecotr.pop_back();
        }
        if(point_vecotr.back()->x == 1 && point_vecotr.back()->y == 1){
            this->point_vecotr.clear();
            break;
        }
    }
}
void labyrinth::print(){
    if(this->point_vecotr.empty()){
        cout << "本迷宫无解！" << endl;
        return;
    }
    for(vector<Pointptr>::const_iterator begin = point_vecotr.begin(), end = point_vecotr.end(); begin != end; begin++)
        cout << "<" << (*begin)->x << "," << (*begin)->y << "," << way[(*begin)->next_way] << ">";
}
labyrinth::labyrinth(int width,int length){
    way[0] = "None";
    way[1] = "Down";
    way[2] = "Right";
    way[3] = "Left";
    this->length = length;
    this->width = width;
    array = new int* [width + 2];
    for(int a = 0; a < width + 2; a++) array[a] = new int[length + 2];
    for(int a = 0; a < width + 2; a++){
        array[a][length + 1] = 1;
        array[a][0] = 1;
    }
    for(int a = 0; a < length + 2; a++){
        array[width + 1][a] = 1;
        array[0][a] = 1;
    }
}
void labyrinth::initialize(int width,int length,int data){
    this->array[width][length] = data;        
}
int main (){
    cout << "本程序需要您提供m行n列的矩阵来构建迷宫" << endl << "首先请输入m和n" << endl;
    int m,n;
    cin >> m >> n;
    int data;
    if(m <= 0 || n <= 0){
        cout << "输入数据有误！\n程序结束" << endl;
        exit(-1);
    }
    cout << "请注意，0代表联通，1代表墙无法通过！请输入m行n列的矩阵\n";
    labyrinth TMD(m,n);
    for(int a = 1; a <= m; a++){
        for(int b = 1; b <= n; b++){
            cin >> data;
            if(data == 0 || data == 1)
                TMD.initialize(a,b,data);
            else{
                cout << "输入数据有误" << endl;
                exit(-1);
            }
        }
    }
    TMD.game();
    TMD.print();
}
