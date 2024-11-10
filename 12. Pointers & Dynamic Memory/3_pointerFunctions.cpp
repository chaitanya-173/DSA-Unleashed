#include <iostream>
using namespace std;

void print(int *p){

    cout << "Address : " << p << endl;
    cout << "Value : " << *p << endl;

}

void update(int *p){

    // p = p + 1;
    *p = *p + 1;

}

int getSum(int *arr, int n){    //arr[] and *arr are exactly same (dono mein pointer he pass hore hain)

    cout << "Size : " << sizeof(arr) << endl;

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;

}

int main(){

    int value = 5;
    int *p = &value;

    print(p);

    cout << "Value before : " << *p << endl;
    update(p);
    cout << "Value after : " << *p << endl;

    cout << p << endl; //address before and after will be the same
    cout << endl;

    int arr[5] = {1,2,3,4,5};
    cout << "Sum is : " << getSum(arr+2, 3) << endl; //calling a part of array

}