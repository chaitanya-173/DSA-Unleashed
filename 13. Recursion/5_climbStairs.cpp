//number of ways to climb a stair if one can climb 1 or 2 at a time
#include <iostream>
using namespace std;

int climbStairs(int nStairs){

    //base case
    if(nStairs < 0)
    return 0;

    if(nStairs == 0)
    return 1;

    //Recursive call
    int ans = climbStairs(nStairs-1) + climbStairs(nStairs-2);

    return ans;
    
}

int main(){

    int stairNumber;
    cin >> stairNumber;

    cout << climbStairs(stairNumber);

}