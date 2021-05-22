const a = 100;
alert(typeof(toString(a)));//返回string
//typeof()返回数据类型
//数据转换为string

const a = "123.23";
const b = parseInt(a);//返回数值123
const c = parseFloat(a);//返回数值123.23
const d = a * 1;
alert(typeof(d));//返回number

const a = 1234;
const b = !!a;//把变量转换为bool值
alert(b);//返回true
alert(typeof(b));//返回boolean

//特殊数据类型
/*
null
	是NULL,只有一个值，null，它表示空值，当对象为空，或者变量没有引用任何对象，其返回值为null
*/
/*
undefined
	表示未定义，区别于对象，数组，数值，字符串，布尔型，变量未初始化时，默认为undefined类型
*/
