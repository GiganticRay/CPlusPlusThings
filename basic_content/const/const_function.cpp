#include<iostream>
using namespace std;

void f(const int i){
    // i=10; // error: assignment of read-only parameter ‘i’
    cout<<i<<endl;
}

// this is for the conflict over the dalao, he said stl source code use the format below, but the doc said this is nonsense.
const int f1(int i){
    i += 2;
    return i;
}

int main(){
    cout << f1(1) << endl;
}
