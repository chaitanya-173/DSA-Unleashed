#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int i=1;

    while(i<=n){

        // printing spaces first
        int sp=1;

        while(sp<=n-i){
            cout << " ";
            sp++;
        }

        // printing stars next
        int j=1;
        while(j<=i){
            cout << "*";
            j++;
        }

        cout << endl;
        i++;
    }
}

// Enter n: 4
//    *
//   **
//  ***
// ****

// Method2-> (only cuz i and j form relation of small 
// & big sum for spaces and stars differently)

// while(i<=n){

    //     int j=1;

    //     while(j<=n){
    //         if ((i+j)<=5)
    //         cout << " ";
    //         else
    //         cout << "*";
    //         j++;
    //     }

    //     cout << endl;
    //     i++;

    // }
