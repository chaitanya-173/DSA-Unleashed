#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack <string> s; //last in first out concept

    s.push("Chaudhary");
    s.push("Chandra");
    s.push("Chaitanya");

    cout << "Top element -> " << s.top() <<endl;

    s.pop();

    cout << "Top element -> " << s.top() <<endl;
    cout << "Size -> " << s.size() <<endl;
    cout << "Empty or not -> " << s.empty() <<endl;




    

}