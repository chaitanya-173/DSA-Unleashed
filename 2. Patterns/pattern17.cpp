#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int i=1;

    while(i<=n){

        int j=1;

        while(j<=i){
            char ch = i+j+'A'-2;
            cout << ch << " ";
            j++;
        }

        cout << endl;
        i++;

    }
}

// Enter n: 4
// A 
// B C 
// C D E 
// D E F G 

//Method-> similar formula derivation like pattern14