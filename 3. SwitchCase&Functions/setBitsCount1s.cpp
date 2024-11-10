#include <iostream>
using namespace std;

int count1bits(int n){
    int count = 0;
    while(n!=0){
        if(n&1){
            count++;
        }
        n = n>>1;
    }
    return count;
}

int main(){
    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    cout << "No. of 1's bits in (a+b) are: " << (count1bits(a) + count1bits(b));
}