#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int i=1;

    while(i<=n){

        int sp=1;
        while(sp<=(n-i)){
            cout << " ";
            sp++;
        }

        int j=1;
        while(j<=i){
            cout << i;
            j++;
        }

        cout << endl;
        i++;

    }
}


// n=4

//    1 
//   22
//  333
// 4444