#include <iostream>
using namespace std;

int main(){
    
    int n;
    cout << "Enter n: ";
    cin >> n;
    int i=1;

    while(i<=n){
        int j=1;

        while(j<=n){
            cout << i;
            j++;
        }

        cout << endl;
        i++;

    }
}

// Enter n: 4
// 1111
// 2222
// 3333
// 4444