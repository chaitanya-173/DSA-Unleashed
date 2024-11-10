#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(1){
        switch (n){
            case 1: cout <<"bla"<< endl;
            break;
            case 2: cout << "int" << endl;
            break;
            default: cout << "default" << endl;
        }
        exit(0);
    }
}
