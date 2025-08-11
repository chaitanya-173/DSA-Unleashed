#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price) {
  int n = price.size();
  int dp[n+1][n+1];
  
  for(int i=0;i<n+1;i++){
      for(int j=0;j<n+1;j++){
          if(i == 0 || j == 0) {
              dp[i][j] = 0;
          } else {
              if(i <= j){
                  dp[i][j] = max(price[i-1]+dp[i][j-i], dp[i-1][j]);
              }
              else{
                  dp[i][j] = dp[i-1][j];
              }
          }
          
      }
  }
  
  return dp[n][n];
}

int main() {
  vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
  int n = price.size();
  
  cout << "Maximum obtainable value is " << cutRod(price) << endl;
}