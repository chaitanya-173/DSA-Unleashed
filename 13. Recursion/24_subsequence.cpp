#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solveSubsequence(string str, string output, int index, vector<string>& ans){

    //base case
    if(index >= str.length()){
        if(output.length() > 0){  //not want to include empty string
            ans.push_back(output);
        }
        return;
    }

    //exclude
    solveSubsequence(str, output, index+1, ans);

    //include
    output.push_back(str[index]);
    solveSubsequence(str, output, index+1, ans);

}

int main() {

    string str = "abc";
    string output = "";
    vector<string> ans;
    int index = 0;
    solveSubsequence(str, output, index, ans);

    for(int i=0; i<ans.size(); i++){
        cout << "'" << ans[i] << "'" << " ";
    }

}