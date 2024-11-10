#include <iostream>
using namespace std;

int power(int n){

    //base case
    if(n == 0)
    return 1;

    //recursive relation
    int smallProblem = power(n-1);
    int bigProblem = 2 * smallProblem;

    return bigProblem;

}

int main(){

    int n;
    cin >> n;

    cout << power(n);
    
}