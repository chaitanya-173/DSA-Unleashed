#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int solve(vector<char> v) {
    stack<int> s;
    for(int i=0; i<v.size(); i++) {

        if(v[i] >= '0' && v[i] <= '9') {  //number hai: push krdo stack mein 
            int num = v[i] - '0';
            s.push(num);
        }
        else {    //operator hai: top 2 elements pe implement krke unko pop krdo
            int top1 = s.top();
            s.pop();
            int top2 = s.top();
            s.pop();
            if(v[i] == '+') {
                s.push(top1 + top2);
            }
            else if(v[i] == '-') {
                s.push(top1 - top2);
            }
            else if(v[i] == '*') {
                s.push(top1 * top2);
            }
            else if(v[i] == '/') {
                s.push(top1 / top2);
            }
            else if(v[i] == '^') {
                s.push(top1 ^ top2);
            }
        }

    }
    return s.top();
}

int main() {

    vector<char> postfix{'5','6','3','*','+','5','6','+','3','*','+'};
    cout << solve(postfix);


}