// http://www.cplusplus.com/forum/general/168292/

struct foo
{
    foo() {} //Cannot be called for implicit conversion
    foo(int) {} //Can be called for implicit conversion
    explicit foo(double) {}//Cannot be called for implicit conversion
    foo(int, int) {} //Not explicit, cannot be called for implicit conversion 
};

void bar(foo a){

}

int main()
{
    bar(foo()); //legal
    bar(10); //legal
    bar(2.0); //Legal foo(double) is not explicit
	bar(2, 3);	// Illegal
}