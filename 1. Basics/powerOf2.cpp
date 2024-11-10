#include <iostream>
#include <math.h>
using namespace std;

// int main(){

//     int n;
//     cout << "Enter n: ";
//     cin >> n;

//     for (int i=0; i<=30; i++){

//         int ans = pow(2,i);
//         if(ans == n){
//             cout << "true";
//         }
        
//     }
        
// }
int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;
    int ans = 1;
    for(int i=0; i<=30; i++){
        if(ans == n){
            cout << "true";
        }
        if(ans < (pow(2,31)-1)/2)
        ans = ans * 2;   // 2 ki power 30 * 2 = 2^31 (range ke bahar)
    }
    cout << "false";
}
