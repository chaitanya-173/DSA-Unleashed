#include <iostream>
using namespace std;

int main(){

    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    char op;
    cout << "Enter operation: ";
    cin >> op;

    switch( op ){

        case '+': cout << a+b << endl;
        break;

        case '-': cout << a-b << endl;
        break;

        case '*': cout << a*b << endl;
        break;

        case '/': cout << a/b << endl;
        break;

        case '%': cout << a%b << endl;
        break;

        default: cout << "Please enter a valid operation" << endl;

    }
}
