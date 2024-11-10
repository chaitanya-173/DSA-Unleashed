#include <iostream>
using namespace std;

bool checkPalindrome(string& str, int i){

    //base case
    if(i> (str.length()-i-1))
    return true;

    if(str[i] != str[str.length()-i-1])
    return false;

    else
    return checkPalindrome(str, ++i);  //recursive call

}

int main(){

    string str = "naman";
    cout << checkPalindrome(str, 0) << endl;

}