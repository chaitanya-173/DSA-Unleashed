#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int i=1;

    while(i<=n){

        int sp=1;
        while(sp<=(i-1)){
            cout << " ";
            sp++;
        }

        int j=1;
        while(j<=(n-i+1)){
            cout << i;
            j++;
        }

        cout << endl;
        i++;

    }
}

// n=4

// 1111
//  222
//   33
//    4