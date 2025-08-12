#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the shortest common supersequence of two strings
// The shortest common supersequence is the shortest string that has both s1 and s2 as subsequences.
int shortestCommonSupersequence(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return n + m - dp[n][m]; // the length of both strings minus the length of their longest common subsequence
}


int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << "Length of Shortest Common Supersequence: " << shortestCommonSupersequence(s1, s2) << endl; // Output: 9 (AGGXTXAYB)
}