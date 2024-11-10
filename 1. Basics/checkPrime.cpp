#include <iostream>
using namespace std;

// int main(){

//     int num;
//     cout << "Enter number: ";
//     cin >> num;

//     for (int i=2; i<num; i++){

//         if(num%i==0){
//             cout << num << " is not a prime number";
//             break;
//         }
//         else{
//             cout << num << " is a prime number";
//             break;
//         }
        
//     }

// }

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;

    bool isPrime = 1;

    for(int i=2; i<n; i++){

        if(n%i==0){
        isPrime=0;
        break;
        }
    }

    if(isPrime==0){
    cout << "Not a prime number" << endl;
    }
    else{
    cout << "Is a prime number" << endl;
    }
}

