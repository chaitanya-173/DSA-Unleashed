#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int i=1;

    while(i<=n){

        int j=n;

        while(j>=1){
            cout << j << " ";
            j--;
        }

        cout << endl;
        i++;
        
    }
}

// Enter n: 4
// 4 3 2 1 
// 4 3 2 1 
// 4 3 2 1 
// 4 3 2 1 