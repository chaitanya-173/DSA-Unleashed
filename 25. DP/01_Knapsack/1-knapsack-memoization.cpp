#include <iostream>
#include <vector>
using namespace std;

int knap(vector<int> &wt, vector<int> &val, int n, int W, vector<vector<int>> &dp) {
    // base case
    if(n == 0 || W == 0) return 0;
    
    // if value is already calculated
    if(dp[n][W] != -1) return dp[n][W];
    
    // if the caacity of current element is <= than the capacity left
    // 1. include -> val[n-1] + knap(wt, val, n-1, cap-wt[n-1], dp)
    // 2. exclude -> knap(wt, val, n-1, cap, dp)
    if(wt[n-1] <= W) return dp[n][W] = max(val[n-1] + knap(wt, val, n-1, W-wt[n-1], dp), knap(wt, val, n-1, W, dp));
    else return dp[n][W] = knap(wt, val, n-1, W, dp);
}

int main() {
    vector<int> wt = {1,2,3};
    vector<int> val = {4,5,1};
    int n = val.size();
    int capacity = 4;
    
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, -1));

    cout << knap(wt, val, n, capacity, dp);
}