#include <iostream>
using namespace std;

void update(int& m){
    m += 3;
}

int main(){

    int i = 5;
    int& j = i;  //j is the reference variable of i

    cout << i << " " << j << endl;
    i++;
    j++;
    cout << i << " " << j << endl;

    int n = 10;
    cout << "Before : " << n << endl;
    update(n);
    cout << "After : " << n << endl;

}