#include <iostream>
using namespace std;

void reverseString(string temp){

    int s=0, e = temp.length()-1;
    while(s<e){
        swap(temp[s++],temp[e--]);
    }
}

string reverseWords(string str){

    string temp = "";
    for(int i=0; i<str.length(); i++){

        if(str[i] == 32){
            reverseString(temp);  
            temp.push_back(' ');
        }

        else
        temp.push_back(str[i]);
        
    }
    return temp;
}

int main(){

    string str = "The sky is blue";
    cout << reverseWords(str);

}