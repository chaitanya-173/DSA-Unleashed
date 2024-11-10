#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solveKeypad(string digit, string output, int index, vector<string>& ans, string mapping[]){

    //base case
    if(index >= digit.length()){
        ans.push_back(output);
        return;
    }

    int number = digit[index] - '0';   //char -> int (typecasting)
    string value = mapping[number];

    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
        solveKeypad(digit, output, index+1, ans, mapping);
        output.pop_back();   //backtracking
    }

}

int main() {

    string digits = "89";
    vector<string> ans;

    // if(digits.length() == 0)
    // return ans;

    string output = "";
    int index = 0;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    solveKeypad(digits, output, index, ans, mapping);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

}