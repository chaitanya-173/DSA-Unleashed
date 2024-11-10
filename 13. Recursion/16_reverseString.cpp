#include <iostream>
using namespace std;

void reverse(string& str, int i, int j){

    //base case
    if(i>j)
    return;

    swap(str[i], str[j]);
    // i++;
    // j--;
    reverse(str, ++i, --j);  //Recursive call

}

int main(){

    string str = "chaitanya";
    reverse(str, 0, str.length()-1);

    cout << str << endl;

}