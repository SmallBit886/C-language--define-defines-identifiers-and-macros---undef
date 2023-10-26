#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//在define定义标识符的时候，最后不要在最后加上 ;
//#define MAX 1000;
////#define MAX 1000
////例如：
//int main()
//{
//	int max;
//	if (1)
//		max = MAX;//不能加;
//	else
//		max = 0;
//	return 0;
//}

//3.2.2 #define 定义宏
//#define SQUARE(X) X*X
//int main()
//{
//	int ret = SQUARE(5);	//5*5=25
//
//	int ret1 = SQUARE(5 + 1);//5+1*5+1=11	----	#define SQUARE(X) (X)*(X)	---	改进
//
//	printf("%d\n", ret);//25
//	printf("%d\n", ret1);//11
//
//	return 0;
//}

//#define SQUARE(X) X+X
//int main()
//{
//	int ret =10* SQUARE(5);	//10*5+5=55		----改进	#define SQUARE(X) ((X)+(X))		---10*(5+5)=100
//
//	
//	printf("%d\n", ret);//55
//
//	return 0;
//}

//2.2.3 #define 替换规则
/*
1. 在调用宏时，首先对参数进行检查，看看是否包含任何由#define定义的符号。如果是，它们首先
被替换。
2. 替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值所替换。
3. 最后，再次对结果文件进行扫描，看看它是否包含任何由#define定义的符号。如果是，就重复上
述处理过程。
注意：
1. 宏参数和#define 定义中可以出现其他#define定义的符号。但是对于宏，不能出现递归。
2. 当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索。
*/

//3.2.4 #和##
//void print(int a)
//{
//	printf("the value a is %d\n", a);
//}
//int main()
//{
//	int a = 10;
//	int b = 10;
//	print(a); //the value a is 10
//		
//	print(b);//the value a is 10
//	return 0;
//}

//#define PRINT(X) printf("the value "#X " is %d\n",X)
//
//int main()
//{
//	//printf("hello world\n");
//	//printf("hello ""world\n");
//	//printf("hel""lo " "world\n");
//	///*
//	//hello world
//	//hello world
//	//hello world
//	//*/
//
//	int a = 10;
//	int b = 10;
//	PRINT(a);//the value a is 10
//	PRINT(b);//the value a is 10
//	
//	/*
//	#define PRINT(X) printf("the value "#X " is %d\n",X)
//	使用 # ，把一个宏参数变成对应的字符串
//
//	the value a is 10
//	the value b is 10
//	*/
//
//	return 0;
//}

//## 的作用
/*
##可以把位于它两边的符号合成一个符号。
它允许宏定义从分离的文本片段创建标识符
*/

//#define CAT(X,Y) X##Y
//int main()
//{
//	int Class84 = 2023;
//	//printf("%d\n", Class84);//2023
//
//	printf("%d\n", CAT(Class, 84));//2023
//	//注：
//	//这样的连接必须产生一个合法的标识符。否则其结果就是未定义的。
//
//	return 0;
//}

//3.2.5 带副作用的宏参数
/*
x + 1;//不带副作用
x++;//带有副作用
*/
//#define MAX(a, b) ( (a) > (b) ? (a) : (b) )
//
//int main()
//{
//	int a = 10;
//	int b = 11;
//	//int z = MAX(a, b);
//	//printf("%d\n", z);//11
//
//
//	int z = MAX(a++, b++);//	---		( (a++) > (b++) ? (a++) : (b++) )	
//	printf("%d\n", z);//12
//	printf("%d\n", a);//11
//	printf("%d\n", b);//13
//
//	return 0;
//}

//3.2.6 宏和函数对比
/*
* 那为什么不用函数来完成这个任务？
  原因有二：

1. 用于调用函数和从函数返回的代码可能比实际执行这个小型计算工作所需要的时间更多。
所以宏比函数在程序的规模和速度方面更胜一筹。

2. 更为重要的是函数的参数必须声明为特定的类型。
所以函数只能在类型合适的表达式上使用。反之这个宏怎可以适用于整形、长整型、浮点型等可以用于>来比较的类型。
*/
/*
宏的缺点：当然和函数相比宏也有劣势的地方：

1. 每次使用宏的时候，一份宏定义的代码将插入到程序中。除非宏比较短，否则可能大幅度增加程序的长度。
2. 宏是没法调试的
3. 宏由于类型无关，也就不够严谨。
4. 宏可能会带来运算符优先级的问题，导致程容易出现错
*/

//#define MALLOC(num, type) (type*)malloc(num * sizeof(type))
//int main()
//{
//	//int* p = (int*)malloc(10 * sizeof(int));
//	// 
//	//宏有时候可以做函数做不到的事情。比如：宏的参数可以出现类型，但是函数做不到
//	int* p = MALLOC(10, int);
//
//	return 0;
//}

//3.2.7 命名约定
/*
一般来讲函数的宏的使用语法很相似。所以语言本身没法帮我们区分二者。

那我们平时的一个习惯是：

把宏名全部大写
函数名不要全部大写
*/

//3.3 #undef
//这条指令用于移除一个宏定义
//#undef NAME
//如果现存的一个名字需要被重新定义，那么它的旧名字首先要被移除
