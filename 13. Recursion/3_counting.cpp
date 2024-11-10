#include <iostream>
using namespace std;

void printCounting(int n){

    //base case
    if(n == 0)
    return;

    cout << n << " ";
    printCounting(n-1);  //for ...5 4 3 2 1
    
    //printCounting(n-1);
    //cout << n << " ";  for 1 2 3 4 5...
}

int main(){

    int n;
    cin >> n;

    printCounting(n);

}