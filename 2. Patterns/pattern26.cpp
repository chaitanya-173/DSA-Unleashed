#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int i=1;

    while(i<=n){

        // printing 1st triangle(spaces)
        int sp=1;
        while(sp<=n-i){
            cout << "  ";
            sp++;
        }

        // printing 2nd triangle
        int j=1;
        while(j<=i){
            cout << j << " ";
            j++;
        }

        // printing 3rd triangle
        int start=i-1;
        while(start){
            cout << start << " ";
            start--;
        }

        cout << endl;
        i++;

    }
}


// n=4

//    1
//   121
//  12321
// 1234321