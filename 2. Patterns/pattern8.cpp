#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int i=1, count=1;

    while(i<=n){

        int j=1;

        while(j<=i){
            cout << count << " ";
            count++;
            j++;
        }

        cout << endl;
        i++;

    }
}

// Enter n: 4
// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 