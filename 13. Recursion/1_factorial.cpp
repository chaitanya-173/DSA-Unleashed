#include <iostream>
using namespace std;

int fact(int n){

    //base case
    if(n == 0)
    return 1;

    //recursive relation
    //int smallProblem = fact(n-1);
    //int bigProblem = n * smallProblem;

    return (n * fact(n-1));  //return bigProblem

}

int main(){

    int n;
    cin >> n;

    int ans = fact(n);
    cout << ans << endl;

}

