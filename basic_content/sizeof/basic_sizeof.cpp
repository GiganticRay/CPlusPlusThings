#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    cout << "sizeof(int)" << sizeof(int) << endl;
    cout << "sizeof(chat)" << sizeof(char) << endl;
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
