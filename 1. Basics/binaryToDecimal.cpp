#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int num;
    cout << "Enter a binary number: ";
    cin >> num;

    int i=0, ans=0;

    while(num != 0){

        int bit = num % 10;  // bit ke digit nikalo
        
        if (bit == 1){
            ans = ans + pow(2,i);  // bit ke digit ko convert krdo 2 ki powers mein
        }

        num = num / 10; // entered binary ke ryt se ek no hatega
        i++;

    }
    cout << "Converted decimal number is: " << ans << endl;
}

