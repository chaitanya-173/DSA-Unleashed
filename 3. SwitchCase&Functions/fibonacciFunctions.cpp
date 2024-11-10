#include <iostream>
using namespace std;

int fibo(int n){
    int a=0, b=1;
    for(int i=1; i<=(n-2); i++){
        int nxtNum = a+b;
        a=b;
        b=nxtNum;
    }
    return b;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "The " << n << "th term of the series is " << fibo(n);
}
