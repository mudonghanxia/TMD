//数组是一组有的数据集合，
//可以通过构造函数Array(),和运算符new来实现。
const a = new Array();//空数组
const a = new Array(1,2,3,"4","5");//带参数
const a = new Array(6);//定义指定长度的数组
const a = Array(6);
const a = [1,2,3,"4","5"];
alert(a[2]);
a[2] = "!";//可以修改数组成员

const str = "";
let a = [1,2,3,4,5];
for(let i = 0;i < a.length; i++){
    str += a[i] + '-';
}
document.write(a + "<br/>");
document.write(str);

//输出结果：
/*
	1,2,3,4,5
	1-2-3-4-5-
*/

//数组的大小可由length修改,若小于直接删掉多余元素,若大于当前元素,则不影响输出
const a = [1,2,3,4,5];  //1,2,3,4,5
document.write(a);
document.write('<br/>');
a.length = 4;    //1,2,3,4
document.write(a);   //2
document.write('<br/>' + a[1]);

//push函数和pop函数均可在数组中使用
//unshift和shift分别对应push和pop函数,不过操作于队首
const a = [];
a.push(1,2,3);   //1,2,3
document.write(a + '<br/>');
a.push(4,5,6,7); //1,2,3,4,5,6,7
document.write(a + '<br/>');
a.pop();  //1,2,3,4,5,6
document.write(a + '<br/>');
delete(a[2]);  //1,2,,4,5,6
document.write(a + '<br/>');
a.unshift(-1,0);   //-1,0,1,2,,4,5,6
document.write(a + '<br/>');
a.shift();	//0,1,2,,4,5,6
document.write(a + '<br/>');

//splice函数,第一个参数指定插入下标,第二个参数指定删除元素的个数,第三个参数指定插入的具体元素
const value = [1,2,3,4,5,6];
const value_ = value.splice(1,2);	
document.write(value);  //1,4,5,6
document.write(value_); //2,3

//reverse函数，可以翻转数组，无参数
const a = [1,2,3,4];
a.reverse();// 4,3,2,1
document.write(a);

//join函数，将数组转换为字符串。默认参数是以逗号隔开，否则以参数的形式隔开
const a = [1,2,3,4,5];
const b =  a.join('-');
document.write(typeof(a) + " " + typeof(b) + '<br/>');  //object string
document.write(a + "<br/>"); //1,2,3,4,5
document.write(b); //1-2-3-4-5

//concat函数，可以连接数组，从尾部连接
let a = [1,2,3,4,5];
const b = [7,8,9];
a = a.concat(b);
document.write(a); //1,2,3,4,5,7,8,9
a = a.concat([12,345],[34554],[4453,[1,23,[45]]]);
document.write('<br/>' + a); //1,2,3,4,5,7,8,9,12,345,34554,4453,1,23,45

//slite函数，截取数组
const a = [1,2,3,4,5];
document.write(a.slice(1,3)); //2,3		
