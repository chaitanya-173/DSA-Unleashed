#include <bits/stdc++.h> 

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	
	int num1 = 0;
    for(int i=0; i<n; i++){
        num1 = (num1 * 10) + a[i];
    }

    int num2 = 0;
    for(int j=0; j<m; j++){
        num2 = (num2 * 10) + b[j];
    }

    int sum = num1 + num2;

    vector<int> ans;
    while(sum != 0){
        int digit = sum % 10;
        ans.push_back(digit);
        sum = sum / 10;
    }

    reverse(ans.begin(),ans.end());
    return ans;

}