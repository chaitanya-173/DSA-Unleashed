#include <iostream>
#include<stack>
using namespace std;

bool isValidParentheses(string str) {

    stack<char> s;

    for(int i=0; i<str.length(); i++) {

        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '[') {  //opening bracket hai toh stack mein push kardo
            s.push(ch);
        }
        else {  //close bracket hai toh stack ke top element se match krao aur usse pop krdo
            if(!s.empty()) {
                char top = s.top();
                if( (ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[') ) {
                    s.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }

    }

    if(s.empty()) 
        return true;
    else 
        return false;

}

int main() {

    string str = "[{()}]";

    cout << isValidParentheses(str) << endl;

}