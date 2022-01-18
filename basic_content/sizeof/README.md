# 类大小计算

首先来个总结，然后下面给出实际例子，实战！

- 空类的大小为1字节
- 一个类中，虚函数本身、成员函数（包括静态与非静态）和静态数据成员都是不占用类对象的存储空间。
- 对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针,vptr的大小。
- 普通继承，派生类继承了所有基类的函数与成员，要按照字节对齐来计算大小
- 虚函数继承，不管是单继承还是多继承，都是继承了基类的vptr。(32位操作系统4字节，64位操作系统 8字节)！
- 虚继承,继承基类的vptr。

## 0.sizeof Baisc
```c++
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    cout << "sizeof(int)" << sizeof(int) << endl;
    cout << "sizeof(char)" << sizeof(char) << endl;
    cout << "sizeof(float)" << sizeof(float) << endl;
    cout << "sizeof(double)" << sizeof(double) << endl;
    cout << "sizeof(short)" << sizeof(short) << endl;
    cout << "sizeof(long)" << sizeof(long) << endl;
    int* a;
    double* b;
    char* c;
    cout << "sizeof(char*)" << sizeof(c) << endl;
    cout << "sizeof(int*)" << sizeof(a) << endl;
    cout << "sizeof(char*)" << sizeof(c) << endl;
}

result:
sizeof(int)4
sizeof(char)1
sizeof(float)4
sizeof(double)8
sizeof(short)2
sizeof(long)8
sizeof(char*)8
sizeof(int*)8
sizeof(char*)8
```

### 字节对齐的原则（64位操作系统）
+ https://blog.csdn.net/liukun321/article/details/6974282
+ 结构体中元素是按照定义顺序一个一个放到内存中去的，但并不是紧密排列的。从结构体存储的首地址开始，每一个元素放置到内存中时，它都会认为内存是以它自己的大小来划分的，因此元素放置的位置一定会在自己宽度的整数倍上开始（以结构体变量首地址为0计算）。
+ 原则二：在经过第一原则分析后，检查计算出的存储单元是否为所有元素中最宽的元素的长度的整数倍，是，则结束；若不是，则补齐为它的整数倍。

## 1.原则1

```c++
/**
 * @file blackclass.cpp
 * @brief 空类的大小为1字节
 * @author 光城
 * @version v1
 * @date 2019-07-21
 */
#include<iostream>
using namespace std;
class A{};
int main()
{
    cout<<sizeof(A)<<endl;
    return 0;
}
```

## 2.原则2

```c++
/**
 * @file static.cpp
 * @brief 静态数据成员
 * 静态数据成员被编译器放在程序的一个global data members中，它是类的一个数据成员，但不影响类的大小。不管这个类产生了多少个实例，还是派生了多少新的类，静态数据成员只有一个实例。静态数据成员，一旦被声明，就已经存在。 
 * @author 光城
 * @version v1
 * @date 2019-07-21
 */
#include<iostream>
using namespace std;
class A
{
    public:
        char b; // 1字节
        virtual void fun() {};  // 8字节
        virtual void fun2() {};
        static int c;
        static int d;
        static int f;
};

int main()
{
    /**
     * @brief 16  字节对齐、静态变量不影响类的大小、vptr指针=8
     */
    cout<<sizeof(A)<<endl; 
    return 0;
}
```

## 3.原则3

```c++
/**
 * @file morevir.cpp
 * @brief 对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针,vptr的大小。
 * @author 光城
 * @version v1
 * @date 2019-07-21
 */
#include<iostream>
using namespace std;
class A{
    virtual void fun();
    virtual void fun1();
    virtual void fun2();
    virtual void fun3();
};
int main()
{
    cout<<sizeof(A)<<endl; // 8
    return 0;
}
```

## 4.原则4与5

```c++
/**
 * @file geninhe.cpp
 * @brief 1.普通单继承,继承就是基类+派生类自身的大小(注意字节对齐)
 * 注意：类的数据成员按其声明顺序加入内存，与访问权限无关，只看声明顺序。
 * 2.虚单继承，派生类继承基类vptr
 * @author 光城
 * @version v1
 * @date 2019-07-21
 */

#include<iostream>

using namespace std;

class A
{
    public:
        char a;
        int b;
};

/**
 * @brief 此时B按照顺序：
 * char a   1
 * int b    4
 * short a  2
 * long b   8
 * 根据字节对齐: 1(3) + 4 + 2(6) + 8 = 24
 */
class B:A
{
    public:
        short a;
        long b;
};
class C // self: 为什么这里不是 8 + 1(7) = 16吗，为啥是12呢。答：当下面有类对象时，C++底层再存储时不会将这个类对象看作类的一个元素，其还是会将这个类对象分解开来，即 char, int, char. 所以是 1(3) + 4 + 1(3) = 12
{
    A a;
    char c;
};
class A1
{
    virtual void fun(){}
};
class C1:public A1
{
};

int main()
{
    cout<<sizeof(A)<<endl; // 8
    cout<<sizeof(B)<<endl; // 24
    cout<<sizeof(C)<<endl; // 12
    /**
     * @brief 对于虚单函数继承，派生类也继承了基类的vptr，所以是8字节
     */
    cout<<sizeof(C1)<<endl; // 8 
    return 0;
}
```

## 5.原则6

```c++
/**
 * @file virnhe.cpp
 * @brief 虚继承
 * @author 光城
 * @version v1
 * @date 2019-07-21
 */

#include<iostream>
using namespace std;
class A
{
    virtual void fun() {}
};
class B
{
    virtual void fun2() {}
};
class C : virtual public  A, virtual public B
{
    public:
        virtual void fun3() {}
};

int main()
{
    /**
     * @brief 8 8 16  派生类虚继承多个虚函数，会继承所有虚函数的vptr
     */
    cout<<sizeof(A)<<" "<<sizeof(B)<<" "<<sizeof(C);

    return 0;
}
```

