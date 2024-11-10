#include <iostream>
using namespace std;

#define PI 3.14  //(macro)- piece of code in a program that is replaced by value of macro
//macros doesn't take any space

//int score = 10; (global variable)- shouldn't be used as it can be updated from any function

//inline function body replaces its function call (should be used for single line body only)
//benefit- no extra memory usage
inline int getMax(int& a, int& b){  
    return (a>b)? a : b;
}

int main(){

    int r = 5;
    // double pi = 3.14;
    double area = PI * r * r;
    cout << "Area : " << area << endl;

    int a = 1, b = 2;
    int ans = 0;

    ans = getMax(a,b);
    cout << ans << endl;

    a += 3;
    b += 1;

    ans = getMax(a,b);
    cout << ans << endl;
    
}