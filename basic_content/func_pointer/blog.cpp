#include <stdio.h>

class MyClass 
{ 
public: 
    MyClass(float f) 
    { 
        factor=f; 
    } 

    float func1(float f,char a,char b)
    { 
        printf("MyClass::func1\n");
        return f*a/b*factor;      
    } 
    float func2(float f,char a,char b) const 
    { 
        printf("MyClass::func2\n"); 
        return f*a*b*factor; 
    } 
    static void func3(){
        printf("static one\n");
    }

private: 
    float factor;
}; 

int main(){
    float (MyClass::*pMemberFunction)(float, char, char) = NULL;
    void (*pStaticFunction)() = NULL;
    pMemberFunction = &MyClass::func1;
    MyClass c1(0.2);
    pStaticFunction = &MyClass::func3;
    (c1.*pMemberFunction)(0.1, 'a', 'b');
}