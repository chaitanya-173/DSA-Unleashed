#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

vector<int> reverse(vector<int> v){
    int s = 0;
    int e = v.size()-1;

    while(s<e){
        swap(v[s++], v[e--]);
    }
    return v;
}

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
    int summ = sum;

    int countDigits = 0;
    while (summ != 0) {
        summ /= 10;
        countDigits++;
    }

    int number;
    vector<int> ans;
    for(int i=0; i<countDigits; i++){
        number = sum % 10;
        ans.push_back(number);
        sum = sum / 10;
    }

    return reverse(ans);

}

