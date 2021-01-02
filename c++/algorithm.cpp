#include <iostream>
#include <string>
#include <stack>
#include <queue>    
#include <vector>
#include <iomanip>
#include <cmath>
using std::abs;
using std::stack;
using std::setprecision;
using std::fixed;
using std::vector;
using std::setw;
using std::priority_queue;
using std::string;
using std::cin;
using std::endl;
using std::cout;
#define M INT_MAX  //正无穷

/**
 * n_queen结构体
 * @param width 行
 * @param length 列
*/
typedef struct n_queen{
    int width;
    int length;
}struct_queen;

/**
 * 活动时间结构体
 * @param begin_time 起始时间
 * @param end_time 结束时间
*/
typedef struct active_plan{
    int begin_time;
    int end_time;
}time_plan;

/**
 * 哈夫曼树节点树结构体
 * @param Rhood 右节点
 * @param Lhood 左节点
 * @param number 频率
 * @param word 若为'.'则表示不是叶子节点，若为'a'~'z'则表示为叶子节点
*/
typedef struct two_Huffman_tree{
    struct two_Huffman_tree* Rhood;
    struct two_Huffman_tree* Lhood;
    int number;
    char word;
}Huffman_tree;
typedef Huffman_tree* Huffman_treeptr;

/**
 * 仅用于优先队列中可以存放指针
 * @param ptr 是Huffman_treeptr指针
*/
typedef struct two_Huffman_treeptr{
    Huffman_treeptr ptr;
    friend bool operator < (two_Huffman_treeptr A,two_Huffman_treeptr B){
        return A.ptr->number > B.ptr->number;
    }   
}Huffman_tree_ptr;

/**
 * 最小生成树结构体
 * @param begin 弧尾
 * @param end 弧头
 * @param data 权值
*/
typedef struct the_small_tree{
    int begin;
    int end;
    int data;
    friend bool operator <(the_small_tree A,the_small_tree B){
        return A.data > B.data;//从小到大
    }
}small_tree;

//只为解决二维数组无法仅靠实参传递所创建的类
template <typename T>
class class_array{
public:
    T** array;
    int width;
    int length;
    /**
     * 二维数组构造函数
     * @param width 横
     * @param length 列
    */
    class_array(int width,int length);
    /**
     * 二维数据的初始化函数
     * @param width 所添加二维数据的横
     * @param length 所添加二维数据的列
     * @param data 所添加二维数据的值
    */
    void initialize(int width,int length,T data);
    /**
     * 输出当前数组
    */
    void show();
    /**
     * 运算符重载()
     * @param width 横
     * @param length 列
     * @return [width][length]的引用
    */
    T& operator()(int width,int length);
};

template <typename T>
T& class_array<T>::operator()(int width,int length){
    return this->array[width][length];
}
template <typename T>
class_array<T>::class_array(int _width,int _length):width(_width),length(_length){
    this->array = new T*[width];
    for(int a = 0; a < width; a++) this->array[a] = new T[length];
}
template <typename T>
void class_array<T>::initialize(int width,int length,T data){
    this->array[width][length] = data;
}
template <typename T>
void class_array<T>::show(){
    for(int a = 0; a < this->width; a++){
        for(int b = 0; b < this->length; b++)
            cout << setw(4) << this->array[a][b] << " ";
        cout << endl;
    }
}
//算法
class algorithm{
    /**
     * 辅助实现Tsp
     * @param array 二维无向完全图邻接矩阵
     * @param vector_int 当前路径
     * @param add_now 当前路径权值和
     * @param vector_ans 当前最优路径
     * @param add_min 当前最优路径和
    */
   template <typename T>
    void Aid_tsp(class_array<T> array,vector<int>& vector_int,int& add_now,vector<int>& vector_ans,int& add_min);
    /**
     * 辅助n皇后
     * @param queen vector实现保存以及输出
     * @param queen_length 总共要放置的皇后数量
     * @param length 当前已放置皇后数量
    */
    void Aid_n_queen(vector<struct_queen>& queen,int queen_length,int length);
    /**
     * 辅助实现全排列
     * @param array 待排序的整数数组[0,length]
     * @param length 辅助数组的大小
     * @param length_frist 起始排列下标
    */
    void Aid_arrange(int* array,int length,int length_frist);
    /**
     * 辅助实现整数划分
     * @param number 待划分的整数
     * @param min 可以划分的最大子数
     * @return 返回可划分的个数
    */
    int Aid_big_math_part(int number,int min);
    /**
     * 辅助实现二分查找(升序)数组
     * @param array 升序数组[0,length]
     * @param length 数组长度
     * @param number 待查询数字
     * @param Frist 待查询首下标
     * @param end 待查询结束下标
    */
    int Aid_find_math(int* array,int length,int number,int Frist,int end);
    /**
     * 辅助二分排序
     * @param array 被排序的数组[begin,end]
     * @param value 辅助排序数组
     * @param begin 允许的起始下标
     * @param end 允许的终止下标
    */
    void Aid_sort_two_part(int* array,int* value,int begin,int end);
    /**
     * 辅助快排
     * @param array 被排序的数组[begin,end]
     * @param begin 起始坐标
     * @param end 终止坐标
     * @param value 辅助数组
     * @param choice 基准数
    */
    void Aid_sort_quick(int* array,int begin,int end,int* value,int choice);
    /**
     * 线性时间选择(快排思想)
     * @param array 查询数组[begin,end]
     * @param begin 辅助数组起始下标
     * @param end 辅助数组的结束下标
     * @param vlaue 辅助存放的数组
     * @param k 第k下标
     * @param choice 快速排序划分基准
     * @param cc 判断是否找到，找到则置为true，使得递归加速
    */
    void Aid_find_the_k_1(int* array,int begin,int end,int* value,int k,int choice,bool& cc);
    /**
     * 线性时间选择(中位数)
     * @param array 查询数组[begin,end]
     * @param begin 辅助数组起始下标
     * @param end 辅助数组的结束下标
     * @param vlaue 辅助存放的数组
     * @param k 第k下标
     * @param choice 快排划分基准
    */
    void Aid_find_the_k_3(int* array,int begin,int end,int* value,int k,int choice);
    /**
     * 寻找中位数
     * @param array 查询数组[begin,end]
     * @param begin 起始下标
     * @param end 终止下标
     * @return 返回中位数的值
    */
    int Aid_find_between(int* array,int begin,int end);
    /**
     * 活动安排辅助函数——按照最先结束时间排序
     * @param array 时间数组[0,length)，active_play.begin_time是开始时间,active_time.end_time是结束时间
     * @param length 时间数组的大小
    */
    void Aid_activity_plan_end_sort(active_plan* array,int length);
    /**
     * 哈夫曼树编码输出(递归)
     * @param Huffman_tree 哈夫曼树根节点
     * @param str 字符串保存当前编码
    */
    void Aid_Huffman(Huffman_treeptr Huffman_tree,string& str);
    /**
     * @param weight 重量数组[0,length)
     * @param length 长度
     * @param capacity_1 第一艘船的容量
     * @param nowweight 当前所装的重量
     * @param capacity 下界---若是小于下界则截肢
     * @param number 当前被装物品的下标
     * @param remain 剩余容量
     * 辅助递归实现装载
    */
    void Aid_loading_ship(int* weight,int& length,int& capacity_1,int nowweight,int& capacity,int number,int remain);
public:
    algorithm(){}
    ~algorithm(){}
    /**
     * 实现全排列算法
     * @param array 排列数组[0,length]
     * @param length 长度
    */
    void Arrange(int* array,int length);
    /**
     * 整数划分算法
     * @param number 被划分的整数
     * @return 返回可划分的个数
    */
    int Big_math_part(int number);
    /**
     * 二分搜索
     * @param array 二分搜索数组(升序)
     * @param length 数组的大小[0,length]
     * @param number 待搜索数字
     * @return 数字在数组中的位置，若不存在，则返回-1
    */
    int Find_math(int* array,int length,int number);
    /**
     * 二分排序
     * @param array_1 被数组[0,length]
     * @param length_1 数组的大小
    */
    void Sort_two_part(int* array,int length);
    /**
     * 快速排序
     * @param array 被排序的数组[0,length]
     * @param length 被排序数组的大小
    */
    void Sort_quick(int* array,int length);
    /**
     * 冒泡排序
     * @param array 被排序数组[0,length]
     * @param length 被排序数组长度
    */
    void Sort_bubble(int* array,int length);
    /**
     * 插入排序
     * @param array 被排序数组[0,length]
     * @param length 被排序数组长度
    */
    void Sort_instert(int* array,int length);
    /**
     * 选择排序
     * @param array 被排序数组[0,length]
     * @param length 被排序数组的长度
    */
    void Sort_choice(int* array,int length);
    /**
     * 线性时间选择(借助快排思想)
     * @param array 寻找数组[0,length]
     * @param length 数组长度
     * @param k number
     * @return 返回第k大的元素
    */
    int Find_the_k_1(int* array,int length,int k);    
    /**
     * 线性时间选择(二分排序后输出指定位置的元素)
     * @param array 被查询数组[0,length]
     * @param length 长度
     * @param k 第k大元素
     * @return 返回指定位置的数据
    */
    int Find_the_k_2(int* array,int length,int k);
    /**
     * 线性时间选择(中位数选择)
     * @param array 被查询数组[0,length]
     * @param length 长度
     * @param k 第k大元素
     * @return 返回指定位置的数据
    */
    int Find_the_k_3(int* array,int length,int k);
    /**
     * 矩阵连乘
     * @param array 矩阵横纵序列[1,length)
     * @param length 矩阵长度
     * @return 最小乘次
    */
    int Matrix_mul(int * array,int length);
    /**
     * 最长公共子序列
     * @param array1 第一个序列[0,array1_length)
     * @param array1_length 第一个序列的长度
     * @param array2 第二个序列[0,array2_length)
     * @param array2_length 第二个序列的长度
     * @return 返回公共子序列的长度
    */
    int The_same_list(int* array1,int array1_length,int* array2,int array2_length);
    /**
     * 电路布线问题(默认与递增序列想比较)求递增序列长度
     * @param array 第一个序列[0,length]
     * @param length array和array2的长度
     * @return 最长不相交长度
    */
    int The_road(int* array,int length);
    /**
     * 最大字段和
     * @param  array 数组[0,length]
     * @param length array的长度
     * @return 返回最大的和
    */
    int The_max_add(int* array,int length);
    template <typename T>
    /**
     * 投资问题
     * @param array 二维数据类
     * @return 返回投资结果
    */
    int Invest(class_array<T> array);
    /**
     * 0-1背包问题
     * @param length 物品多少
     * @param weight 重量数组[0,length - 1]
     * @param value 价值数组[0,length - 1]
     * @param capacity 容量
     * @return 背包的价值
    */
    int Bag_0_1(int length,int* weight,int* value,int capacity);
    /**
     * 活动安排(贪心策略：从结束时间最早的最先安排)
     * @param array 起始时间和终止时间数组[0,length)
     * @param length 数组的大小
     * @return 返回活动数
    */
    int Activity_plan_end_sort(time_plan* array,int length);
    /**
     * 最优装载问题(贪心策略：从最轻开始往最重的装)
     * @param weight 重量数组[0,length)
     * @param length 重量数组的大小
     * @param capacity 容量
     * @return 返回最大载重个数
    */
    int Greedy_shipment(int* weight,int length,int capacity);
    /**
     * 哈夫曼编码压缩
     * @param c_array 字符数组[0,length)
     * @param length 数组长度
     * @param i_array 频率数组[0,length)
    */
    void Huffman(char* c_array,int length,int* i_array);
    /**
     * 最小生成树-prim算法
     * @param array 图的邻接矩阵
    */
    template <typename T>
    void The_smallest_tree_prim(class_array<T> array);
    /**
     * 最小生成树--kruskal算法
     * @param array 图的邻接矩阵
    */
    template <typename T>
    void The_smallest_tree_kruskal(class_array<T> array);
    /**
     * 单源最短路径问题
     * @param data 起始定点
     * @param array 图的邻接矩阵
    */
    template <typename T>
    void Dijkstra(int data,class_array<T> array);
    /**
     * 装载问题---回溯法
     * @param weight 重量数组[0,length)
     * @param length 重量数组大小
     * @param capacity_1 容量1
     * @param capacity_2 容量2
    */
    void Loading_ship(int* weight,int length,int capacity_1,int capacity_2);
    /**
     * n皇后问题
     * @param queen_number 皇后的数量
    */
    void N_queen(int queen_number);
    /**
     * 最大团
     * @param array 图的邻接矩阵
    */
    template <typename T>
    void The_bigest_tuan(class_array<T> array);
    /**
     * TSP
     * @param array 图的邻接矩阵
    */
    template <typename T>
    void Tsp(class_array<T> array);
};

template <typename T>
void algorithm::Tsp(class_array<T> array){
    vector<int> vector_int;
    vector<int> vector_ans;
    int add_now = 0;
    int add_min = M;
    vector_int.push_back(0);//压入第一个元素
    for(int a = 1; a < array.width;a++){
        vector_int.push_back(a);
        Aid_tsp(array,vector_int,add_now,vector_ans,add_min);
        add_now = 0;
        vector_int.clear();
        vector_int.push_back(0);
    }
    for(vector<int>::const_iterator begin = vector_ans.begin(), end = vector_ans.end(); begin != end; begin++)
        cout << *begin << " ";
    cout << endl << "权值和为" << add_min;
}
template <typename T>
void algorithm::The_bigest_tuan(class_array<T> array){
    int length = array.length;
    vector<int> vector_int;
    vector<int> vector_int_max;
    bool choice = true;//判断当前准备加的节点是否在目前团中
    for(int a = 0; a < length; a++){
        vector_int.push_back(a);
        for(int b = 0; b < length; b++){
            for(vector<int>::const_iterator begin = vector_int.begin(), end = vector_int.end(); begin != end; begin++){
                if(array(*begin,b) == M || array(*begin,b) == 0){
                    choice = false;
                    break;
                }
            }
            if(choice == false){
                choice = true;
                continue;
            }
            vector_int.push_back(b);
        }
        if(vector_int_max.size() < vector_int.size()){
            vector_int_max.clear();
            for(vector<int>::const_iterator begin = vector_int.begin(),end = vector_int.end(); begin != end; begin++)
                vector_int_max.push_back(*begin);
        }
        vector_int.clear();
    }
    for(vector<int>::const_iterator begin = vector_int_max.begin(),end = vector_int_max.end(); begin != end; begin++)
        cout << *begin + 1 << " ";
}
void algorithm::N_queen(int queen_number){
    vector<struct_queen> queen;
    struct_queen array_queen;
    array_queen.width = 0;
    for(int a = 0; a < queen_number; a++){
        array_queen.length = a;
        queen.push_back(array_queen);
        Aid_n_queen(queen,queen_number - 1,0);
        queen.pop_back();//恢复现场
    }
}
void algorithm::Loading_ship(int* weight,int length,int capacity_1,int capacity_2){
    int capacity = 0;//结果
    int remain = 0;
    for(int a = 0; a < length; a++) remain += weight[a];
    Aid_loading_ship(weight,length,capacity_1,0,capacity,0,remain);
    if(remain - capacity > capacity_2){
        cout << "本问题无解";
        return;
    }
    cout << "在A船中装入" << capacity << "吨货物\n在B船中装入" << remain - capacity << "吨货物";
}
template <typename T>
void algorithm::Dijkstra(int data,class_array<T> array){
    int length = array.width;//class_array::width 行
    int value[length];
    bool point[length];
    int add;
    int point_length = 0;
    int min = 0;
    for(int a = 0; a < length;a++) {
        value[a] = array(0,a);
        point[a] = false;
        if(value[min] > value[a]) min = a;
    }
    point[data - 1] = true;//从data开始走
    point_length = 2;
    point[min] = true;
    int newpoint = min;
    while(point_length != length){
        for(int a = 1; a < length; a++){
            if(point[a] == false){
                if(array(newpoint,a) != M && value[newpoint] != M){
                    add = array(newpoint,a) + value[newpoint];
                    if(add < value[a]) value[a] = add;
                }
            }
        }
        point[newpoint] = true;
        point_length++;
        min = M;
        for(int a = 1; a < length; a++){
            if(point[a] == false && value[a] < min){
                min = value[a];
                newpoint = a;
            }
        }
    }
    for(int a = 0; a < length; a++){
        if(a + 1 != data)
            value[a] != M ? cout << data << "到" << a + 1 << "的最短距离是" << value[a] << endl:
                            cout << data << "无法到达" << a + 1 << endl;
    }
}
template <typename T>
void algorithm::The_smallest_tree_prim(class_array<T> array){
    int length = array.width;//行数
    bool value[length];
    vector<small_tree> tree_vector;
    small_tree choice;
    for(int a = 0; a < length; a++) value[a] = false;
    value[0] = true;//初始化第一个点
    int value_len = 1;//以添加的点数
    int min = array(0,0);
    int point_begin;
    int point_end;
    while(value_len < length){
        point_begin = 0;
        point_end = 0;
        for(int a = 0; a < length; a++){
            if(value[a] != 0){//查询以添加数中
                for(int b = 0; b < length; b++){
                    if(min > array(a,b) && value[b] == 0){//在以添加数中查询到未添加数的路
                        point_begin = a;
                        min = array(a,b);//找到最小边
                        point_end = b;//所加入的点
                    }
                }
            }
        }
        choice.begin = point_begin;
        choice.end = point_end;
        for(int a = 0; a < length; a++)
            if(value[a] == 0) min = array(point_begin,a);
        choice.data = array(point_begin,point_end);
        tree_vector.push_back(choice);
        value[point_end] = true;
        value_len++;
    }
    cout << "prim算法所得最小生成树为：\n";
    for(vector<small_tree>::const_iterator b = tree_vector.begin(),e = tree_vector.end(); b != e; b++){
        cout << b->begin << "--->" << b->end << "     权值为：" << b->data << endl;
    }
}
template <typename T>
void algorithm::The_smallest_tree_kruskal(class_array<T> array){
    small_tree choice;
    priority_queue<small_tree> pr_queue;
    vector<small_tree> pr_vector;
    int length = array.width;//class_array::width为行
    int len_number = 0;//边数
    class_array<bool> value(length/2,length);//如果邻接矩阵没有问题的话，最多只能有顶点数/2个联通风量
    bool point[length];//顶点集
    int len_value = 0;//联通分量个数
    int begin,end;
    bool break_bool = false;
    for(int a = 0; a < length/2; a++)
        for(int b = 0; b < length; b++)
            value.initialize(a,b,false);
    for(int a = 0; a < length; a++){//将边分别加到优先队列中
        point[a] = false;//顺手初始化
        for(int b = a; b < length; b++)
            if(array(a,b) != M){
                choice.begin = a; choice.end = b; choice.data = array(a,b);
                pr_queue.push(choice);
            }
    }
    while(len_number != length - 1){
        begin = pr_queue.top().begin;
        end = pr_queue.top().end;
        if(!point[begin] && !point[end]){//如果两点均未被访问，创建一个新的联通分量
            value(len_number,begin) = true;
            value(len_number,end) =true;
            len_number++;
            point[begin] = true;
            point[end] = true;
            pr_vector.push_back(pr_queue.top());//保存边
        }
        else if(!point[begin]){//若是begin未被访问，end已被访问->在end所在的联通分量下加入begin
            for(int a = 0; a < len_number; a++)
                if(value(a,end) == true)//找到end
                    value(a,begin) = true;//把end分量下的begin初始化为true  
            pr_vector.push_back(pr_queue.top());//保存边
            len_number++;
        }
        else if(!point[end]){//若是end被访问，begin未被访问->在begin所在的联通分量下加入end
            for(int a = 0; a < len_number; a++)
                if(value(a,begin) == true) value(a,end) = true;
            pr_vector.push_back(pr_queue.top());//保存边
            len_number++;
        }
        else{//两个点均被访问，判断是否处于同一联通分量，若处于，则continue，否则加边
            for(int a = 0; a < len_number; a++){
                if(value(a,begin) == true && value(a,end) == true)//处于同一联通风量
                    break;
                if(value(a,begin) == true && value(a,end) == false){//begin处于，end不处于
                    value(a,end) = true;//将begin下的联通分量中的end置为true
                    pr_vector.push_back(pr_queue.top());//保存边
                    len_number++;
                    for(int b = a + 1; b < len_number; b++){
                        if(value(b,end) == true){//找到end所在行
                            for(int c = 0; c < length; c++)//将end所在联通分量所有的值传递给begin
                                if(value(b,c) == true) value(a,c) = true;
                            break;
                        }
                    }
                    break;
                }
                if(value(a,begin) == false && value(a,end) == true){//begin不处于，end处于
                    value(a,begin) = true;
                    len_number++;
                    pr_vector.push_back(pr_queue.top());//保存边
                    for(int b  = a + 1; b < len_number; b++){
                        if(value(b,begin) == true){
                            for(int c = 0; c < length; c++)
                                if(value(b,c) == true) value(a,c) = true;
                            break;
                        }
                    }
                    break;
                }
            }
        }
    pr_queue.pop();//不管有没有加边，均需要出队
    }
    cout << "kruskal算法所得最小生成树为："<< endl;
    for(vector<small_tree>::const_iterator b = pr_vector.begin(),e = pr_vector.end(); b != e; b++)
        cout << b->begin << "--->" << b->end << "      权值为:" << b->data << endl;
}
void algorithm::Huffman(char* c_array,int length,int* i_array){
    priority_queue<Huffman_tree_ptr> pr_queue;
    Huffman_tree_ptr n;
    for(int a = 0; a < length; a++){//将已有数据入队
        n.ptr = new Huffman_tree;
        n.ptr->number = i_array[a];
        n.ptr->word = c_array[a];
        pr_queue.push(n);
    }
    Huffman_tree_ptr newptr_1;//用于优先队列的压栈和出栈
    Huffman_tree_ptr newptr_2;
    Huffman_tree_ptr newptr_3;
    while(pr_queue.size() != 1){
        newptr_2.ptr = new Huffman_tree;
        newptr_1.ptr = new Huffman_tree;
        newptr_3.ptr = new Huffman_tree;
        if(pr_queue.top().ptr->word != '.'){//说明是字母，叶子节点
            newptr_1.ptr->number = pr_queue.top().ptr->number;
            newptr_1.ptr->word = pr_queue.top().ptr->word;
            newptr_1.ptr->Lhood = NULL;
            newptr_1.ptr->Rhood = NULL;
            pr_queue.pop();
        }
        else{//非叶子节点
            newptr_1.ptr->number = pr_queue.top().ptr->number;
            newptr_1.ptr->word = '.';
            newptr_1.ptr->Lhood = pr_queue.top().ptr->Lhood;
            newptr_1.ptr->Rhood = pr_queue.top().ptr->Rhood;
            pr_queue.pop();
        }
        if(pr_queue.top().ptr->word != '.'){
            newptr_2.ptr->number = pr_queue.top().ptr->number;
            newptr_2.ptr->word = pr_queue.top().ptr->word;
            newptr_2.ptr->Lhood = NULL;
            newptr_2.ptr->Rhood = NULL;
            pr_queue.pop();
        }
        else{
            newptr_2.ptr->number = pr_queue.top().ptr->number;
            newptr_2.ptr->word = '.';            
            newptr_2.ptr->Lhood = pr_queue.top().ptr->Lhood;
            newptr_2.ptr->Rhood = pr_queue.top().ptr->Rhood;
            pr_queue.pop();
        }
        newptr_3.ptr->Lhood = newptr_1.ptr;
        newptr_3.ptr->Rhood = newptr_2.ptr;
        newptr_3.ptr->number = newptr_1.ptr->number + newptr_2.ptr->number;
        newptr_3.ptr->word = '.';
        pr_queue.push(newptr_3);
        n.ptr = newptr_3.ptr;    
    }
    string str;//用于保存节点的编码
    this->Aid_Huffman(n.ptr,str);
}
int algorithm::Greedy_shipment(int* weight,int length,int capacity){
    this->Sort_two_part(weight,length - 1);
    int a = 0;
    for(; a < length && capacity > weight[a]; a++)
        capacity -= weight[a];
    return a + 1;
}
int algorithm::Activity_plan_end_sort(time_plan* array,int length){
    Aid_activity_plan_end_sort(array,length);//按照最先结束排序
    int end_time = array[0].end_time;
    int number = 0;
    cout << "所安排的第" << ++number << "个活动的起始时间是" << array[0].begin_time << ",结束时间为：" << array[0].end_time << endl;
    for(int a = 1; a < length; a++){
        if(array[a].begin_time > end_time){
            end_time = array[a].end_time;
            cout << "所安排的第" << ++number << "个活动的起始时间是" << array[a].begin_time << ",结束时间为：" << array[a].end_time << endl;
        }
    }
    return number;
}

int algorithm::Bag_0_1(int length,int* weight,int* value,int capacity){
    class_array<int> array(length + 1,capacity + 1);
    int w;
    for(int a = 0; a <= capacity; a++) array.initialize(0,a,0);
    for(int a = 1; a <= length; a++) array.initialize(a,0,0);
    for(int a = 1; a <= length; a++){//第a行，第a个物品
        for(int b = 1;b <= capacity; b++){//容量
            if(weight[a - 1] > b) array(a,b) = array(a-1,b);//装不了
            else{
                w = array(a-1,b-weight[a-1]) + value[a-1];//value[0,length-1],weight[0,length-1]
                array(a,b) = w > array(a-1,b)?w:array(a-1,b);
            }
        }
    }
    return array(length,capacity);
}
int algorithm::The_road(int* array,int length){
    int value[length + 1];
    for(int a = 0;a <= length;a++) value[a] = 1;
    for(int a = 1; a <= length;a++){
        for(int b = a - 1; b >= 0; b--){
        	    if (array[a] > array[b] && value[b] + 1 > value[a]) value[a] = value[b] + 1;
        } 
    }
    return value[length];
}
void algorithm::Arrange(int* array,int length){
    Aid_arrange(array,length,0);
}
int algorithm::Big_math_part(int number){
    return Aid_big_math_part(number,number);
}
int algorithm::Find_math(int* array,int length,int number){
    if(array[0] == number) return 0;
    return Aid_find_math(array,length,number,1,length);
}
void algorithm::Sort_two_part(int* array,int length){
    int value[length];
    Aid_sort_two_part(array,value,0,length);
}
void algorithm::Sort_quick(int* array,int length){
    int value[length];
    Aid_sort_quick(array,0,length,value,array[0]);    
}
int algorithm::Find_the_k_1(int* array,int length,int k){
    int* value = new int[length + 1];
    bool cc = false;//判断是否找到
    Aid_find_the_k_1(array,0,length,value,k - 1,array[0], cc);//第k个元素的下标排序后是第k-1
    return array[k - 1];
}
int algorithm::Find_the_k_2(int* array,int length,int k){
    Sort_two_part(array,length);
    return array[k - 1];
}
int algorithm::Find_the_k_3(int* array,int length,int k){
    int value_length =((length + 1) % 5 == 0)?(length + 1) / 5:(length + 1) / 5 + 1;//中位数存储数组
    int value[value_length];//中位数数组
    int number = 0,choice;
    if(value_length == 1) value[number] = Aid_find_between(array,0,length);//若是只有一个
    for(choice = 0; choice < value_length - 1; choice += 4) 
        value[number++] = Aid_find_between(array,choice,choice + 4);
    value[number] = Aid_find_between(array,choice,length);
    int between = Aid_find_between(value,0,number);//中位数的中位数
    int value_[length];
    Aid_find_the_k_3(array,0,length,value_,k - 1,between);//等到局部排序完成，下标为k-1的元素是第k大的元素
    return array[k - 1];
}

void algorithm::Sort_bubble(int* array,int length){
    int choice;
    for(int a = 0; a <= length; a++){
        for(int b = a + 1; b <= length; b++){
            if(array[a] > array[b]){
                choice = array[a]; array[a] = array[b]; array[b] = choice;
            }
        }
        for(int a = 0; a < length; a++)
            cout << array[a] << "　";
        cout << endl;   
    }
}

void algorithm::Sort_instert(int* array,int length){
    int value;
    for(int a = 1,choice; a <= length; a++){
        value = a;
        for(int b = a + 1; b >= 0; b--){
            if(array[b] < array[value]){
                choice = array[value]; array[value] = array[b]; array[b] = choice;
                value--;
            }
            else break;
        }
    }
}

void algorithm::Sort_choice(int* array,int length){
    for(int a = 0,min,choice; a <= length; a++){
        min = a;
        for(int b = a; b <= length; b++)
            if(array[min] > array[b]) min = b;
        choice = array[a]; array[a] = array[min]; array[min] = choice; 
    }
}

int algorithm::Matrix_mul(int * array,int length){
    class_array<int> value(length,length);
    int min;
    int a,b,c,j;
    for(a = 0; a < length;a++){
        value.initialize(a,a,0);
        value.initialize(a,a+1,0);
    }
    for(a = 2; a <= length - 1;a++){//步长
        for(b = 1;b <= length - 1 && a + b - 1 <= length; b++){//行
            j = a + b - 1;//列
            value(b - 1,j) = value(b-1,b) + value(b,j) + array[b-1]*array[b]*array[j];//选取第一个进行初始化
            for(c = b + 1; c < j; c++){
                min = value(b-1,c) + value(c,j) + array[b-1]*array[c]*array[j];
                if(min < value(b-1,j)) value(b-1,j) = min;
            }
        }
    }
    return value(0,length - 1);
}

int algorithm::The_same_list(int* array1,int array1_length,int* array2,int array2_length){
    class_array<int> array(array1_length + 1,array2_length + 1);
    for(int a = 0; a < array1_length;a++) array.initialize(a,0,0);
    for(int a = 0; a < array2_length;a++) array.initialize(0,a,0);
    for(int a = 0; a < array1_length;a++){
        for(int b = 0; b < array2_length;b++){
            if(array1[a] == array2[b]) array(a + 1,b + 1) = array(a,b) + 1;
            else array(a + 1,b + 1) = array(a,b + 1)>array(a + 1,b)?array(a,b + 1):array(a + 1,b);            
        }
    }
    return array(array1_length,array2_length);
}

int algorithm::The_max_add(int* array,int length){
    int value[length + 1];
    int down = -1;
    int ans;
    for(int a = 0; a <= length;a++){//找到第一个大于0的数据（全为负数的情况）
        if(array[a] > 0){
            down = a;
            break;
        }    
    }
    if(down < 0){//如果小于0，说明所有数据均小于等于0，找到所有非正数中最大的一个即可
        ans = array[0];
        for(int a = 1; a <= length;a++)
            if(array[a] > ans) ans = array[a];
        return ans;//若是所有数据都小于0，则输出最大的负数
    }
    value[down] = array[down];//否则down就是第一个大于0的数据
    ans = value[down];
    for(int a = down + 1; a <= length;a++){ 
        if(value[a - 1] + array[a] > 0)
            value[a] = value[a - 1] + array[a];
        else value[a] = array[a];
        if(value[a] > ans) ans = value[a];
    }
    return ans;
}

template <typename T>
int algorithm::Invest(class_array<T> array){
    int money = array.width;
    int project = array.length;
    class_array<int> value(money,project);
    int max;
    int ans;
    for(int a = 0; a <= money - 1; a++) value(a,0) = array(a,0);//把钱投给第一个项目收益就是投资收益
    for(int a = 1; a <= project - 1; a++){//把钱投给【0，a】个项目
        for(int b = 0; b <= money; b++){//所投给第a个项目的钱数
            ans = 0;
            for(int c = 0; c <= b; c++){//从0开始尝试寻找当前最大利润
                max = value(b-c,a-1) + array(c,a);
                if(ans < max) ans = max;
            }
            value(b,a) = ans;
        }
    }
    return value(money - 1,project - 1);
}

void algorithm::Aid_loading_ship(int* weight,int& length,int& capacity_1,int nowweight,int& capacity,int number,int remain){
    if(number < length){
        if(nowweight + weight[number] <= capacity_1 && remain + nowweight > capacity)//可以装进去 && 不符合剪枝
            Aid_loading_ship(weight,length,capacity_1,nowweight + weight[number],capacity,number + 1,remain - weight[number]);
        if(remain + nowweight > capacity)//不符合剪枝
            Aid_loading_ship(weight,length,capacity_1,nowweight,capacity,number + 1,remain - weight[number]);
    }
    if(nowweight > capacity) capacity = nowweight;
}

void algorithm::Aid_Huffman(Huffman_treeptr Huffman_tree,string& str){
    if(Huffman_tree->Lhood == NULL && Huffman_tree->Rhood == NULL){
        cout << Huffman_tree->word << "的编码是：" << str << endl;
       str.pop_back();
        str.pop_back();
        return;
    }
    str.append("0");
    Aid_Huffman(Huffman_tree->Lhood,str);
    str.append("1");
    Aid_Huffman(Huffman_tree->Rhood,str);
    str.pop_back();//每往回走一步删除一个节点
}
int algorithm::Aid_find_between(int* array,int begin,int end){
    int value[end];
    Aid_sort_two_part(array,value,begin,end);
    return array[(begin + end) / 2];
}
void algorithm::Aid_sort_quick(int* array,int begin,int end,int* value,int choice){
    if(begin < end){
        int b = begin,
            e = end;
        for(int a = begin; a <= end; a++){
            if(array[a] < choice) value[b++] = array[a];
            else value[e--] = array[a];
        }        
    for(int a = b; a <= e; a++) value[a] = choice;//需要提前复制，因为下一次快排会用到当前的数据
    for(int a = begin;a <= end; a++) array[a] = value[a];
        Aid_sort_quick(array,begin,b - 1,value,array[b - 1]);
        Aid_sort_quick(array,e + 1,end,value,array[e + 1]);
    }
}
void algorithm::Aid_activity_plan_end_sort(time_plan* array,int length){
    time_plan p;
    for(int a = 0; a < length; a++){//采取最简单的冒泡排序
        for(int b = a + 1; b < length; b++){
            if(array[a].end_time > array[b].end_time){
                p = array[a]; array[a] = array[b]; array[b] = p;
            }
        }
    }
}
void algorithm::Aid_sort_two_part(int* array,int* value,int begin,int end){
    if(begin < end){
        int between = (begin + end) / 2;
        Aid_sort_two_part(array,value,begin,between);
        Aid_sort_two_part(array,value,between + 1,end);
        int choice_1 = begin;
        int choice_2 = between + 1;
        int choice = begin;
        while(choice_1 <= between && choice_2 <= end){
            if(array[choice_1] >= array[choice_2]) value[choice++] = array[choice_2++];
            else value[choice++] = array[choice_1++];
        }
        if(choice_1 > between) for(int a = choice_2; a <= end; a++) value[choice++] = array[a];
        else for(int a = choice_1; a <= between; a++) value[choice++] = array[a];
        for(int a = begin; a <= end; a++) array[a] = value[a];
    }
}

int algorithm::Aid_find_math(int* array,int length,int number,int Frist,int end){
    if(Frist <= end){
        int between = (Frist + end) / 2;
        if(array[between] == number) return between;
        else if(array[between] > number) return Aid_find_math(array,length,number,Frist,between - 1);
        else return Aid_find_math(array,length,number,between + 1,end);
    }
    return -1;
}
int algorithm::Aid_big_math_part(int number,int min){
	if(number == 1 || min == 1) return 1;
	else if(number < min) return Aid_big_math_part(number,number);
	else if(number == min) return Aid_big_math_part(number,number-1) + 1;
	else return Aid_big_math_part(number,min-1)+Aid_big_math_part(number-min,min);
}
void algorithm::Aid_arrange(int* array,int length,int length_frist){
    if(length_frist == length){
        for(int a = 0; a <= length; a++) cout << array[a] << " ";
        cout << endl;
    }
    else{
        for(int a = length_frist,b; a <= length;a++){
            b = array[length_frist]; array[length_frist] = array[a]; array[a] = b;
            Aid_arrange(array,length,length_frist + 1);
            b = array[length_frist]; array[length_frist] = array[a]; array[a] = b;
        }
    }
}

void algorithm::Aid_find_the_k_3(int* array,int begin,int end,int* value,int k,int choice){
    if(begin < end){
        //完成一轮快排
        int b = begin, e = end;
        for(int a = begin; a <= end; a++){
            if(array[a] < choice) value[b++] = array[a];
            else if(array[a] > choice) value[e--] = array[a];
        }       
        for(int a = b; a <= e; a++) value[a] = choice;//需要提前复制，因为下一次快排会用到当前的数据
        for(int a = begin;a <= end; a++) array[a] = value[a];
        if(k >= b && k <= e) return;//若是符合题意，则返回
        int length;
        if(k < b){ 
            length = (b + 1);
            end = b;
        }
        else{
            length = end - e;
            begin = e + 1;
        }
        int value_length =(length % 5 == 0)? length / 5:length / 5 + 1;//中位数存储数组
        int value[value_length];//中位数数组
        int number = 0;
        int choice;
        if(value_length == 1) value[number] = Aid_find_between(array,begin,end);//若是只有一个
        for(choice = begin; choice < value_length - 1; choice += 5) 
            value[number++] = Aid_find_between(array,choice,choice + 4);
        value[number] = Aid_find_between(array,choice,end);
        int between = Aid_find_between(value,0,number);//中位数的中位数
        int value_[end];
        Aid_find_the_k_3(array,begin,end,value_,k,between);//等到局部排序完成，下标为k-1的元素是第k大的元素
   }
}

void algorithm::Aid_find_the_k_1(int* array,int begin,int end,int* value,int k,int choice, bool& cc){
    if(cc == true)
        return;
    if(begin < end){
        int b = begin,
            e = end;
        for(int a = begin + 1; a <= end; a++)
            if(array[a] < choice) value[b++] = array[a];
            else value[e--] = array[a];  
        for(int a = b; a <= e; a++) 
            value[a] = choice;
        for(int a = begin;a <= end; a++)//需要提前复制，因为下一次快排会用到当前的数据
            array[a] = value[a];
        if(k >= b && k <= e) {
            cc = true;
            return;   
        }
        Aid_find_the_k_1(array,begin,b,value,k,array[begin],cc);
        Aid_find_the_k_1(array,e + 1,end,value,k,array[e + 1],cc);
    }
}

void algorithm::Aid_n_queen(vector<struct_queen>& queen,int queen_length,int length){
    if(length == queen_length){
        for(vector<struct_queen>::const_iterator begin = queen.begin(),end = queen.end(); begin != end; begin ++)
            cout << begin->width << " " << begin->length << "    ";
        cout << endl;
        return;
    }
    bool choice = true;//判断是否可以放置新皇后
    struct_queen new_queen;
    new_queen.width = length + 1;
    for(int a = 0; a <= queen_length; a++){
        new_queen.length = a;
        for(vector<struct_queen>::const_iterator begin = queen.begin(),end = queen.end(); begin != end; begin++){
            if(begin->length == new_queen.length || abs(begin->length - new_queen.length) == abs(begin->width - new_queen.width)){//列相同||对角线
                choice = false;
                break;
            }
        }
        if(choice == false){
            choice = true;//恢复现场
            continue;   
        }
        queen.push_back(new_queen);
        Aid_n_queen(queen,queen_length,length + 1);
        queen.pop_back();
    }  
}

template <typename T>
void algorithm::Aid_tsp(class_array<T> array,vector<int>& vector_int,int& add_now,vector<int>& vector_ans,int& add_min){
    for(vector<int>::const_iterator begin = vector_int.begin(), end = vector_int.end(); begin != end; begin++)
        cout << *begin << " ";
    cout << endl;
    if(vector_int.size() == array.width){//最后一个节点可以被加入，说明得到一个解
        cout << "TMD";
        vector_ans.clear();
        for(vector<int>::const_iterator begin = vector_int.begin(), end = vector_int.end(); begin != end; begin++)
            vector_ans.push_back(*begin);
        add_min = add_now;
        return;
    }
    bool choice = true;//当前点是否可以使用
    for(int a = 0; a < array.length; a++){
        for(vector<int>::const_iterator begin = vector_int.begin(),end = vector_int.end(); begin != end; begin++){
            if(*begin == a){
                choice = false;
                break;
            }
        }
        if(choice == false){
            choice = true;
            continue;
        }
        if(array(a,vector_int.back()) + add_min > add_min) continue;//如果当前路径大于最优路径，则剪枝
        vector_int.push_back(a);
        add_now += array(a,vector_int.back());
        Aid_tsp(array,vector_int,add_now,vector_ans,add_min);
        add_now -= array(a,vector_int.back());
        vector_int.pop_back();
    }
}
int main(){
    algorithm TMD;
    /*
    全排列
    int array[7] = {1,2,3,4,5,6,7};
    TMD.Arrange(array,4);
    */ 

    /*
    整数划分
    cout << TMD.Big_math_part(6);
    */
   
    /*
    二分查找
    int array[5] = {1,2,4,5,7};
    cout << TMD.Find_math(array,4,5);
    */

    /*
    二分排序   
    int array[6] = {1,6,7,4,5,3};
    for(int a = 0; a < 6; a++) cout << array[a] << " ";
    TMD.Sort_two_part(array,5);
    cout << endl;
    for(int a = 0; a < 6; a++) cout << array[a] << " ";
    */

    /*
    快速排序
    int array[5] = {2,4,1,5,3};
    TMD.Sort_quick(array,4);
    for(int a = 0; a < 5;a++) cout << array[a] << " ";
    */
    int array[10] = {15,21,06,25,36,54,18,45,13,68};
    TMD.Sort_bubble(array,10);
    
    for(int a = 0; a < 10;a++) cout << array[a] << " ";
    /*
    冒泡排序，插入排序，选择排序
    int array[6] = {1,7,5,3,7,2};
    TMD.Sort_bubble(array,5);
    TMD.Sort_instert(array,5);
    TMD.Sort_choice(array,5);
    for(int a = 0; a < 6; a++) cout << array[a] << " ";
    */

    /**
    第k大的元素
    int array[6] = {1,4,3,5,2,2};
    cout << TMD.Find_the_k_1(array,5,4);//快排思想
    cout << TMD.Find_the_k_2(array,5,4);//二分排序后输出指定位置位置大小
    cout << TMD.Find_the_k_3(array,5,6);//不断找到中位数，用来减少排序次数
    */

    /**
    矩阵连乘
    int array[7] = {30,35,15,5,10,20,25};
    cout << TMD.Matrix_mul(array,7);
    */

    /**
    最长公共子序列
    int array1[] = {1,2,3,5,67,1,2,3,4,6,3,45};
    int array2[] = {2,3,1,4,6,3,2,45};
    cout << TMD.The_same_list(array1,12,array2,8);
    */

    /**
    电路布线（最长的递增序列）
    int array[7] = {4,3,4,7,2,6,8};
    cout << TMD.The_road(array,6);
    */

    /**
    最大子段和
    int array[6] = {-2,11,-4,13,-5,-2};
	cout << TMD.The_max_add(array,5);
    */

    /**
     * 投资问题：
     * 测试数据：
6 4
 0  0  0  0
11  0  2 20
12  5 10 21
13 10 30 22
14 15 32 23
15 20 40 24
    函数：
    int money;
    int project;
    int data;
    cout << "请输入总钱数以及项目数：" << endl;
    cin >> money >> project;
    cout << "请输入利润矩阵\n";
    class_array<int> TMD_array(money,project);
    for(int a = 0; a < money; a++){
        for(int b = 0; b < project; b++){
            cin >> data;
            TMD_array.initialize(a,b,data);
        }
    }
    cout << "所得利润为；" << TMD.Invest(TMD_array);
    */

    /**
     * 0-1背包问题
    int n = 5,c= 10;
    int w[5] = {2, 2, 6, 5, 4};
    int v[5] = {6, 3, 5, 4, 6};
    cout << TMD.Bag_0_1(n,w,v,c);
    */

    /**
     * 活动安排(greedy)
    time_plan array[11] = {{1,4},{5,7},{5,9},{0,6},{6,10},{8,11},{3,5},{8,12},{3,8},{2,13},{12,14}};
    cout << TMD.Activity_plan_end_sort(array,11);
    */
   
    /**
     * 最大装载个数    
    int array[6] = {4,3,7,1,8,5};
    int capacity = 15;
    cout << TMD.Greedy_shipment(array,6,capacity);
    */

    /**
     * 哈夫曼树最优编码压缩
    int length = 6;
    char c_array[length] = {'a','b','c','d','e','f'};//字符数组
    int i_array[length] = {45,13,12,16,9,5};//频率数组
    TMD.Huffman(c_array,length,i_array);
    */

	/**
	 * prim算法求得最小生成树 || kruskal算法求得最小生成树
    测试数据
6 6
-1  6  1  5 -1 -1
 6 -1  5 -1  3 -1
 1  5 -1  5  6  4
 5 -1  5 -1 -1  2
-1  3  6 -1 -1  6
-1 -1  4  2  6 -1
    函数：
    int width;
    int length;
    int data;
    cout << "请输入邻接矩阵的行数和列数" << endl;
    cin >> width >> length;
    cout << "请输入邻接矩阵(-1表示无穷大)\n";
    class_array<int> TMD_array(width,length);
    for(int a = 0; a < width; a++){
        for(int b = 0; b < length; b++){
            cin >> data;
            if(data == -1)
                TMD_array.initialize(a,b,M);
            else
                TMD_array.initialize(a,b,data);
        }
    }
	TMD.The_smallest_tree_prim(TMD_array);//prim算法求得最小生成树
	TMD.The_smallest_tree_kruskal(TMD_array);//kruskal算法求得最小生成树
	*/

    /**
    Dijkstra算法求单源路径最短
    测试数据为：
5 5
 -1  10  -1  30 100
 -1  -1  50  -1  -1
 -1  -1  -1  -1  10
 -1  -1  20  -1  60
 -1  -1  -1  -1  -1
    函数：
    int width;
    int length;
    int data;
    cout << "请输入邻接矩阵的行数和列数" << endl;
    cin >> width >> length;
    cout << "请输入邻接矩阵矩阵(-1表示无穷大)\n";
    class_array<int> TMD_array(width,length);
    for(int a = 0; a < width; a++){
        for(int b = 0; b < length; b++){
            cin >> data;
            if(data == -1)
                TMD_array.initialize(a,b,M);
            else
                TMD_array.initialize(a,b,data);
        }
    }
    cout << "请输入起始顶点：";
    cin >> data;
    TMD.Dijkstra(data,TMD_array);
    */

    /**
     * 装载问题---回溯法
    int length = 7;
    int weight[length] = {90,80,40,30,20,12,10};
    int capacity_1 = 152;
    int capacity_2 = 130;
    TMD.Loading_ship(weight,length,capacity_1,capacity_2);
    */

    /**
     * n皇后问题
    TMD.N_queen(6);
    */

    /**
     * 图的最大团
    测试数据：
5 5 
 0  1 -1  1  1
 1  0  1 -1  1
-1  1  0 -1  1
 1 -1 -1  0  1
 1  1  1  1  0  
    函数：
    int width;
    int length;
    int data;
    cout << "请输入邻接矩阵的行数和列数" << endl;
    cin >> width >> length;
    cout << "请输入邻接矩阵(-1表示无穷大)\n";
    class_array<int> TMD_array(width,length);
    for(int a = 0; a < width; a++){
        for(int b = 0; b < length; b++){
            cin >> data;
            if(data == -1)
                TMD_array.initialize(a,b,M);
            else
                TMD_array.initialize(a,b,data);
        }
    }
    TMD.The_bigest_tuan(TMD_array);
    */    

    /**
     * TSP
    测试数据：
4 4
 0 30  6  4
30  0  5 10
 6  5  0 20
 4 10 20  0
    */
    // int width,length,data;
    // cout << "请输入邻接矩阵的行数和列数" << endl;
    // cin >> width >> length;
    // cout << "请输入邻接矩阵(-1表示无穷大)\n";
    // class_array<int> TMD_array(width,length);
    // for(int a = 0; a < width; a++){
    //     for(int b = 0; b < length; b++){
    //         cin >> data;
    //         if(data == -1)
    //             TMD_array.initialize(a,b,M);
    //         else
    //             TMD_array.initialize(a,b,data);
    //     }
    // }
    // TMD.Tsp(TMD_array);
    // return 0;
}
