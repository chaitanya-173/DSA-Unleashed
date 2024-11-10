#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int a=0;
    int b=1;
    cout << a << " " << b << " ";

    for(int i=1; i<=(n-2); i++){

        int nxtNum = a+b;
        cout << nxtNum<< " ";
        a=b;
        b=nxtNum;

    }
}

