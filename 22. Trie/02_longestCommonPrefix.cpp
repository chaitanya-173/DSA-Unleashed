#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n) {
    string ans = "";

    //for traversing all characters of first string
    for(int i=0; i<arr[0].length(); i++) {

        char ch = arr[0][i];
        bool match = true;

        //for comparing ch with rest of the strings
        for(int j=1; j<n; j++) {
            //not match
            if(arr[j].size() < i || ch != arr[j][i]) {
                match = false;
                break;
            }
        }

        if(match == false) 
            break;
        else 
            ans.push_back(ch);
    }
    return ans;
}

//TC - O(m*n);
//SC - O(1);

int main() {

    vector<string> arr{"coding", "codezen", "coders", "codingninja"};

    string ans = longestCommonPrefix(arr, 4);

    for(int i=0; i<ans.length(); i++) {
        cout << ans[i];
    }

}