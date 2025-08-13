#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
  int n = s.size();
  int m = t.size();

  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
          if(s[i-1] == t[j-1]) {
              dp[i][j] = 1 + dp[i-1][j-1];
          } else {
              dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
      }
  }

  string lcs = "";
  int i = n, j = m;
  while(i > 0 && j > 0) {
      if(s[i-1] == t[j-1]) {
          lcs += s[i-1];
          i--;
          j--;
      } else if(dp[i-1][j] > dp[i][j-1]) {
          i--;
      } else {
          j--;
      }
  }

  reverse(lcs.begin(), lcs.end());

  return (lcs == s);
}

// this question can also be solved using a simple two-pointer technique
// which is more efficient in terms of space complexity and time complexity
// but the above method is useful for understanding the relationship with LCS
bool isSubsequenceSimple(string s, string t) {
  int i = 0;
  for(int j=0; j<t.size(); j++) {
      if(t[j] == s[i]) {
          i++;
      } 
  }
  if(i == s.size()) {
      return true;
  }
  return false;
}

int main() {
  string s = "abc";
  string t = "ahbgdc";
  
  if(isSubsequence(s, t)) {
      cout << "Yes, '" << s << "' is a subsequence of '" << t << "'" << endl;
  } else {
      cout << "No, '" << s << "' is not a subsequence of '" << t << "'" << endl;
  }

  if(isSubsequenceSimple(s, t)) {
      cout << "Yes, '" << s << "' is a subsequence of '" << t << "' (simple check)" << endl;
  } else {
      cout << "No, '" << s << "' is not a subsequence of '" << t << "' (simple check)" << endl;
  }
}
