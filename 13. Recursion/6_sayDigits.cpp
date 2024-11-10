#include <iostream>
using namespace std;

void sayDigits(int n, string* arr){

    //base case
    if(n == 0)
    return ;

    //processing
    int digit = n % 10;
    n = n / 10;
    //cout << arr[digit] << " "; (for->  three two one..)
    
    //recursive call
    sayDigits(n, arr);
 
    cout << arr[digit] << " ";

}

int main(){

    int n;
    cin >> n;

    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    sayDigits(n, arr);

}