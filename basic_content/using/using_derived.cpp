/**
 * @file using_derived.cpp
 * @brief 函数重装
 * @author 光城
 * @version v1
 * @date 2019-08-07
 */

#include <iostream>
using namespace std;

class Base{
    public:
        void f(){ cout<<"f()"<<endl;
        }
        void f(int n){
            cout<<"Base::f(int)"<<endl;
        }
};

class Derived : private Base {
    public:
        // using Base::f;
        void f(int n){
            cout<<"Derived::f(int)"<<endl;
        }
};

int main()
{
    Base b;
    Derived d;
    // d.f(); error: 就算 derived 继承了 Base, 但是 Derived 类中实现的一个函数重载会覆盖掉其他函数重载，所以要使用 using Base::f 使其可见
    d.f(1);
    return 0;
}
