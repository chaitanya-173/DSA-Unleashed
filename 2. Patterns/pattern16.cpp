#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int i=1;
    char value='A';

    while(i<=n){

        int j=1;

        while(j<=i){
            cout << value << " ";
            value++;
            j++;
        }

        cout << endl;
        i++;
        
    }
}

// Enter n: 4
// A 
// B C 
// D E F 
// G H I J 
