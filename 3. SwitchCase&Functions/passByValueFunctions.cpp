#include<iostream>
using namespace std;

void dummy(int n ) {
    n++;
    cout << " n is " << n <<endl;
}

int main() {

    int n;
    cin >> n;

    dummy(n);
    cout<<"number n is "<< n << endl;

}

// Here we can see that ‘n’ entered in the main section is not 
// incremented cuz both the n’s in ‘main’ and in the 
// ‘function dummy’ are different.
// The function dummy isn’t returning any value and just printing 
// something that doesn’t affect main.
