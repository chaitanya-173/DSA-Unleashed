#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int num;
    cout << "Enter a decimal number: ";
    cin >> num;

    float ans=0, i=0;

    while(num != 0){  // or num > 0 

        int bit = num & 1;  // or num % 2 (reading bit of no)
        ans = (bit * pow(10,i)) + ans;  // store bits or reverse
        num = num>>1;  // binary ke ryt se ek no hatega
        i++;

    }
    cout << "The converted binary number is: " << ans << endl;

}

// to do -> negative decimal to binary 