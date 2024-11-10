#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int i=1;

    while(i<=n){

        int nos=1;
        while(nos<=(n-i+1)){
            cout << nos << " ";
            nos++;
        }

        int star=1;
        while(star<=(2*i-2)){
            cout << "* ";
            star++;
        }

        int j=1;
        while(j<=(n-i+1)){
            cout << (n-j-i+2) << " ";
            j++;
        }

        cout << endl;
        i++;

    }
}

// Enter n: 5
// 1 2 3 4 5 5 4 3 2 1 
// 1 2 3 4 * * 4 3 2 1 
// 1 2 3 * * * * 3 2 1 
// 1 2 * * * * * * 2 1 
// 1 * * * * * * * * 1 
