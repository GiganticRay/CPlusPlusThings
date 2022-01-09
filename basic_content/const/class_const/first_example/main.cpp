#include<iostream>
#include"apple.cpp"
using namespace std;

Apple::Apple(int i):apple_number(i), intership_numer(i+1)
{

}
int Apple::add(int num){
    take(num);
}
int Apple::add(int num) const{
    take(num);
}
void Apple::take(int num) const
{
    cout<<"take func "<<num<<endl;
}
int Apple::getCount() const
{
    take(1);
//    add(); //error
    return apple_number;
}

// 测试非常函数是否可以（操作）常变量
void Apple::non_const_func(){
    cout << apple_number;   // 输出是可以的
    intership_numer += 1;   // 可以赋值
}

// 测试常函数是否可以操作非常变量, 注意 const 的位置，这个位置不能放到最左边
void Apple::const_func() const{
    // intership_numer += 1;   // 不能赋值
    // apple_number += 1;      // 也不能赋值，因为 apple_numer 是常变量
    cout << intership_numer << endl;
}

int main(){
    Apple a(2);
    a.non_const_func();
    cout<<a.getCount()<<endl;
    a.add(10);
    const Apple b(3);
    b.add(100);
    return 0;
}
