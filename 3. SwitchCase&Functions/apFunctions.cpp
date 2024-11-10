#include <iostream>
using namespace std;

int apFunc(int n){
    int ans = ((3*n)+7);
    return ans;
}

int main(){

    int n;
    cout << "Enter which term you want: ";
    cin >> n;

    cout << "The " << n << "th term of the A.P is: " << apFunc(n);

}