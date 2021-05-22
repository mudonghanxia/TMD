<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./main.css">
    <title>c++</title>
    <style>
.absc1{
    position: fixed;
    right: 0px;
    top: 50%;
    width: 50px;
    height: 90px;
    background-color: white;
}
.absc2{
    position: fixed;
    right: 0px;
    top: 75%;
    width: 50px;
    height: 90px;
    background-color: white;
}
.absc1 a,.absc2 a{
    display: block;
    color: black;
}
    </style>
</head>

<body>
    <div class="absc1"><a href="#algorithm">返回算法顶部</a></div>
    <div class="absc2"><a href="#data-style">返回结构顶部</a></div>
    <div class="back_main"><a href="./main.html">返回主页</a></div>
    <a name="data-style"></a>
    <div>优先队列</div>
    <div class="n1">
        <a name="algorithm"></a>
        <h1>优先队列</h1>
        <li>头文件--#include &lt;queue&gt;</li>
        <li>优先队列是一种自带排序的数据结构，适合于不断需要排序或是操作后需要重新排序，可以对struct自定义指定排序方式，或是一般数据类型进行排序</li>
        <li> 函数
            <ol>
                <li>
                    top ----accesses the top element <br>
                    (public member function)
                </li>
                <li>
                    empty-----checks whether the underlying container is empty <br>
                    (public member function)
                </li>
                <li>
                    size----returns the number of elements <br>
                    (public member function)
                </li>
                <li>
                    push----inserts element and sorts the underlying container <br>
                    (public member function)
                </li>
                <li>
                    emplace----constructs element in-place and sorts the underlying container <br>
                    (public member function)
                </li>
                <li>
                    pop----removes the top element <br>
                    (public member function)
                </li>
                <li>
                    swap---swaps the contents <br>
                    (public member function)
                </li>
            </ol>
        </li>
        <li> 参数解释
            <P>T - The type of the stored elements. The behavior is undefined if T is not the same type
                as
                Container::value_type. (since C++17)</P>
            <P>Container - The type of the underlying container to use to store the elements. The
                container
                must satisfy the requirements of SequenceContainer, and its iterators must satisfy the
                requirements of LegacyRandomAccessIterator. Additionally, it must provide the following
                functions with the usual semantics:</P>
            front() <br>
            push_back() <br>
            pop_back() <br>
            <p>The standard containers std::vector and std::deque satisfy these requirements.</p>
            <p>Compare - A Compare type providing a strict weak ordering.
                Note that the Compare parameter is defined such that it returns true if its first
                argument
                comes before its second argument in a weak ordering. But because the priority queue
                outputs
                largest elements first, the elements that "come before" are actually output last. That
                is,
                the front of the queue contains the "last" element according to the weak ordering
                imposed by
                Compare.</p>
        </li>
        <li>
            就是说，T这个参数是实际的数据类型，实际到int，double，或是struct类型。<br>
            而container 是数据的存储方式，要求要有front或是push_back()，pop_back()函数，一般的vector和queue就符合要求了。 <br>
            最后的参数，compare是比较函数，greater&lt;T&gt;是默认值，从小到大排序 less&lt;T&gt;是从大到小
        </li>
        <li>类型分类
            <ol>
                <li>普通类型 -- int,double,char......
                    <ul>
                        <li>
                            <pre>
template&lt;
    class T,
    class Container = std::vector&lt;T&gt;,
    class Compare = std::less&lt;typename Container::value_type&gt;
> class priority_queue;</pre>
                        </li>
                        <li>
                            <pre class="pre">
priority_queue&lt;int,vector&lt;int&gt;,greater&lt;int&gt;&gt; ans;</pre>
                        <li>greater
                            <pre class="pre">
priority_queue&lt;int,vector&lt;int&gt;,greater&lt;int&gt;&gt; ans;
    ans.push(23);
    ans.push(345324);
    ans.push(3);
    for(int a = 0; a < 3; ++a){
        cout << ans.top() << " ";
        ans.pop();
    }
//3 23 345324</pre>
                        </li>
                        <li>less
                            <pre class="pre">
priority_queue&lt;int,vector&lt;int&gt;,less&lt;int&gt;&gt; ans;
    ans.push(23);
    ans.push(345324);
    ans.push(3);
    for(int a = 0; a < 3; ++a){
        cout << ans.top() << " ";
        ans.pop();
    }
//345324 23 3 </pre>
                        </li>
                </li>
                </ul>
        </li>
        <li>特殊类型
            <pre class="pre">
struct aa
{
int age;
string ans;
friend bool operator<(const struct aa &A, const struct aa &B)
{
return A.age < B.age;
}
};

function: main
struct aa v = {12, "aaa"},
b = {1, "34"},
c = {11, "333"},
d = {111, "dfdf"};
priority_queue<struct aa, vector<struct aa>> ans;
ans.push(v);
ans.push(b);
ans.push(c);
ans.push(d);
for (int a = 0; a < 4; ++a)
{
cout << ans.top().age << " " << ans.top().ans << endl;
ans.pop();
}
//111 dfdf
//12 aaa
//11 333
//1 34</pre>
            </ol>
        </li>
    </div>
    <div>
        <h1>reverse函数</h1>
        <ul>
            <li>头文件--#include&lt;algorithm&gt;</li>
            <li>
                <pre>
template&lt; class BidirIt &gt;
void reverse( BidirIt first, BidirIt last );
(until C++20)
template&lt; class BidirIt &gt;
constexpr void reverse( BidirIt first, BidirIt last );
(since C++20)
template&lt; class ExecutionPolicy, class BidirIt &gt;
void reverse( ExecutionPolicy&& policy, BidirIt first, BidirIt last );
(since C++17)


first, last	-	the range of elements to reverse
policy	-	the execution policy to use. See execution policy for details.</pre>
            </li>
            <li>
                <pre class="pre">
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
    
int main()
{
    std::vector<int> v{1, 2, 3};
    std::reverse(v.begin(), v.end());
    for(auto e : v) std::cout << e;
    std::cout << '\n';
    
    int a[] = {4, 5, 6, 7};
    std::reverse(std::begin(a), std::end(a));
    for(auto e : a) std::cout << e;
}
output:
321
7654</pre>
            </li>
        </ul>
    </div>
    <div class="">
        <h1>queue</h1>

        <pre>
front - access the first element 
back - access the last element 
empty - checks whether the underlying container is empty 
size - returns the number of elements  &&在层次遍历的时候，巧用size
push - inserts element at the end 
emplace - constructs element in-place at the end 
pop - removes the first element 
swap - swaps the contents </pre>
    </div>
</body>

</html>
