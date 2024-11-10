#include <iostream>
using namespace std;

bool isPrime(int n){
    for(int i=2; i<n; i++){
        if(n%i==0){
            return 0; //Not a prime number
        }
    }
    return 1;
}

int main(){
    int num;
    cout << "Enter number: ";
    cin >> num;

    if(isPrime(num)){
        cout << num << " is a prime number";
    }
    else{
        cout << num << " is not a prime number";
    }
}
