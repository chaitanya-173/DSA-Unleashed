//if string is not case sensitive
#include <iostream>
using namespace std;

int getLength(char name[]){
    int count = 0;
    for(int i=0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}

char toLowercase(char ch){
    if(ch >= 'a' && ch <= 'z')
    return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool check(char str[], int len){

    int s=0, e=len-1;
    while(s<=e){

        if(toLowercase(str[s]) != toLowercase(str[e]))
        return 0;

        else{
        s++;
        e--;
        }
    }
    return 1;
}

int main(){
    char str[] = "Malayalam";
    int len = getLength(str);
    cout << "Palindrome or not: " << check(str,len);
}