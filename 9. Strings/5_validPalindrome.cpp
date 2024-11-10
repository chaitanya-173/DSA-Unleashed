#include <iostream>
using namespace std;

bool valid(char ch){
    if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
    return 1;
    }
    return 0;
}

char toLowercase(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    } 
}

bool checkPalindrome(string str){

    int s=0, e=str.length()-1;
    while(s<=e){

        if(str[s] != str[e])
        return 0;

        else{
        s++;
        e--;
        }
    }
    return 1;
}

bool isValidPalindrome(string str){

    //faltu char htado
    string temp = "";
    for(int i=0; i<str.length(); i++){
        if(valid(str[i])){
            temp.push_back(str[i]);
        }
    }

    //lowercase mein kardo
    for(int i=0; i<temp.length(); i++){
        temp[i] = toLowercase(temp[i]);
    }

    //check palindrome
    return checkPalindrome(temp);
} 

int main(){

    string str = "A man, a plan, a canal: Panama";
    cout << isValidPalindrome(str);

}