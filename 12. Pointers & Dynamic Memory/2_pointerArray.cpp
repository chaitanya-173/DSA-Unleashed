#include <iostream>
using namespace std;

int main(){

    int arr[10] = {44,61,79};

    cout << "Address of 1st memory block : " << arr << endl;  //method-1
    cout << "Address of 1st memory block : " << &arr[0] << endl;  //method-2
    cout << "Value at 1st memory block : " << arr[0] << endl;
    cout << "Value at 1st memory block : " << *arr << endl;
    cout << "Value at 2nd memory block : " << *(arr + 1) << endl;

    cout << endl;

    //important point  
    int i = 2;
    cout << i[arr] << endl;
    //arr[i] = *(arr + i);   
    //i[arr] = *(i + arr);

    cout << endl;

    int *ptr = &arr[0];
    cout << "1st : " << sizeof(ptr) << endl;  //usually 8 bytes (size of pointer)
    cout << "2nd : " << sizeof(*ptr) << endl;
    cout << "3rd : " << sizeof(&ptr) << endl;
    cout << "4th : " << sizeof(arr) << endl;
    cout << "5th : " << sizeof(arr[0]) << endl; 
    cout << "6th : " << sizeof(*arr) << endl;

    cout << endl;

    int brr[20] = {1,3,5,7,9};

    cout << &brr[0] << endl;
    cout << &brr << endl;
    cout << brr << endl;

    int *p = &brr[0];

    cout << "Value of address stored in p : " << p << endl; 
    cout << "Value at p : " << *p << endl;
    cout << "Address of p : " << &p << endl;

    cout << endl;

    //character arrays
    
    int array[5] = {1,2,3,4,5};
    char ch[6] = "abcde";

    cout << array << endl;
    cout << ch << endl;  //different implementation for char arrays (prints entire string)

    int *p1 = &array[0];
    char *p2 = &ch[0];

    cout << p1 << endl;
    cout << p2 << endl;  //different implementation for char arrays (prints entire string)
    //jab tak null char nhi milta tb tk char array print hota rhta



}