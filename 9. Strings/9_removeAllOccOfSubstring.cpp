#include <iostream>
#include  <bits/stdc++.h>
using namespace std;

string removeSubstringOcc(string str, string part){

    while((str.length() != 0) && (str.find(part) < str.length())){
        str.erase(str.find(), part.length());
    }
    return str;

}
int main(){
    string str, part;
    cin >> str;
    cin >> part;
    cout << removeSubstringOcc(str, part);
}