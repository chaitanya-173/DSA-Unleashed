// Give a signed 32-bit integer x, return x with its digits 
// reversed. If reversing x causes the value to go outside the
// 32-bit integer range [-2^31, 2^31-1], then return 0.

#include <iostream>
#include <climits>
using namespace std;

int main(){

    int x;
    cout << "Enter x: ";
    cin >> x;

    int ans = 0;

    while(x != 0){

        if ((ans > INT_MAX/10) || (ans < INT_MIN/10)){
            cout << "0";
        }

        int digit = x % 10;
        ans = (ans * 10) + digit;
        x = x/10;          
            
    }
    
    cout << ans;
   
}