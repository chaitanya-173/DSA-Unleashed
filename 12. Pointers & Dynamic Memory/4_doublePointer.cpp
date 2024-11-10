#include <iostream>
using namespace std;

int update(int** p2){

    **p2 = **p2 + 1;

}

int main(){

    int i = 5;
    int* p1 = &i;  //1st pointer(p1) pointing to i's address
    int** p2 = &p1;  //double pointer(p2) pointing to p1's address

    //Methods to access i
    cout << i << endl;
    cout << *p1 << endl;
    cout << **p2 << endl;

    //Methods to access address of i i.e. value of p1
    cout << &i << endl;
    cout << p1 << endl;
    cout << *p2 << endl;

    //Methods to access address of p1 i.e. value of p2
    cout << &p1 << endl;
    cout << p2 << endl;

    //Methods to access address of p2
    cout << &p2 << endl;

    cout << endl << endl;
    cout << "Before : " << endl;
    cout << i << endl;
    cout << p1 << endl;
    cout << p2 << endl;

    update(p2);
    
    cout << "After : " << endl;
    cout << i << endl;
    cout << p1 << endl;
    cout << p2 << endl;

}