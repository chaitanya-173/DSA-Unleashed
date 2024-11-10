#include <iostream>
using namespace std;

char getMaxOccChar(string str){

    int arr[26] = {0};

    for(int i=0; i<str.length(); i++){

       int num = str[i] - 'a';
       arr[num]++;

    }
    
    for(int i=0; i<26; i++){
        cout << arr[i];
    }cout << endl;

    int maxi = -1, ans= 0;
    for(int i=0; i<26; i++){
        if(maxi < arr[i]){
        maxi = arr[i];
        ans = i;
        }
    }

    return (ans + 'a');
}

int main(){

    string str = {};
    cin >> str;

    cout << getMaxOccChar(str);

}