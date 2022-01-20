#include <iostream>
using namespace std;

// 左值引用与右值引用：https://zhuanlan.zhihu.com/p/97128024

class Stack
{
public:
    // 构造
    Stack(int size = 1000) :msize(size), mtop(0)
    {
		cout << "Stack(int)" << endl;
		mpstack = new int[size];
    }
	
    // 析构
    ~Stack()
    {
		cout << "~Stack()" << endl;
		delete[]mpstack;
		mpstack = nullptr;
    }
	
    // 拷贝构造
    Stack(const Stack &src)
	:msize(src.msize), mtop(src.mtop)
    {
		cout << "Stack(const Stack&)" << endl;
		mpstack = new int[src.msize];
		for (int i = 0; i < mtop; ++i) {
			mpstack[i] = src.mpstack[i];
		}
    }
	
    // 赋值重载
    Stack& operator=(const Stack &src)
    {
		cout << "operator=" << endl;
		if (this == &src)
				return *this;

		delete[]mpstack;

		msize = src.msize;
		mtop = src.mtop;
		mpstack = new int[src.msize];
		for (int i = 0; i < mtop; ++i) {
			mpstack[i] = src.mpstack[i];
		}
		return *this;
    }

    int getSize() 
    {
		return msize;
    }
private:
    int *mpstack;
    int mtop;
    int msize;
};

// 这个函数又有什么用呢？ 为什么传入一个 stack, 又要传出一个 stack 呢?
Stack GetStack(Stack &stack)
{
    Stack tmp(stack.getSize());
    return tmp;
}

int main()
{
    Stack s;
    s = GetStack(s);
    return 0;
}
