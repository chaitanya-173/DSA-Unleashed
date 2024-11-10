#include <iostream>
using namespace std;

int main(){

    int num = 5; //Method 1 - without pointer
    cout << "Value of num : " << num << endl;
    cout << "Address of num : " << &num << endl;

    int *ptr = &num; //Method 2 - with pointer
    cout << "Address of num : " << ptr << endl;
    cout << "Value of num : " << *ptr << endl;
    cout << "Size of integer : " << sizeof(num) << endl;
    cout << "Size of pointer : " << sizeof(ptr) << endl; //usually 8 bytes

    cout << endl; 

    double d = 4.2;
    double *p2 = &d;
    cout << "Address of d : " << p2 << endl;
    cout << "Value of d : " << *p2 << endl;
    cout << "Size of integer : " << sizeof(d) << endl;
    cout << "Size of pointer : " << sizeof(p2) << endl; //usually 8 bytes

    cout << endl;

    int i = 7;
    int *p = 0; //null pointer
    p = &i;
    cout << "Address of i : " << p << endl;
    cout << "Value of i : " << *p << endl;

    cout << endl;

    int h = 8;
    int copy = h;
    cout << "h before : " << h << endl;
    copy++;
    cout << "h after : " << h << endl;

    //pointers change the actual the value (not make a copy)
    int j = 8;
    int *p3 = &j;
    cout << "j before : " << j << endl;
    (*p3)++;  //value at pointer(p3) i.e. j ko increment krdo
    cout << "j after : " << j << endl;

    cout << endl;

    //copying a pointer
    int *q = p;
    cout << "p value: " << *p << ", q value: " << *q << endl;
    cout << "p address: " << p << ", q address: " << q << endl;

    cout << endl;

    //important concept
    int k = 3;
    int *t = &k;
    *t = *t + 1;
    cout << "value of k incremented : " << *t << endl;
    cout << "address of t before : " << t << endl;
    t = t + 1;
    cout << "address of t after : " << t << endl; //incremented by 4 bytes







}