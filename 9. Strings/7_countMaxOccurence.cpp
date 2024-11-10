#include <iostream>
using namespace std;

char getMaxOccChar(string str){

    int arr[26] = {0};
    //create an array of count of integers
    for(int i=0; i<str.length(); i++){

        int ch = str[i];
        //lowercase
        int num = 0;
        if(ch >= 'a' && ch <= 'z'){
            num = ch - 'a';
        }
        else{ //uppercase
            num = ch - 'A';
        }
        arr[num]++;
    }

    //find max occurence char
    int maxi = -1 ,ans = 0;
    for(int i=0; i<26; i++){
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }
    
    char finalAns = 'a' + ans;
    return finalAns;
}

int main(){
    string str;
    cin >> str;
    cout << getMaxOccChar(str) << endl;
}