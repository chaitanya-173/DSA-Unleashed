#include <iostream>
using namespace std;

int main(){

    int amt;
    cout << "Enter the amount: ";
    cin >> amt;
    int rs100, rs50, rs20, rs1;


    switch(1){

        case 1: rs100 = amt/100;
        amt = amt % 100;
        cout << "No. of 100 rs notes required are: " << rs100 <<endl;

        case 2: rs50 = amt/50;
        amt = amt % 50;
        cout << "No. of 50 rs notes required are: " << rs50 <<endl;
        
        case 3: rs20 = amt/20;
        amt = amt % 20;
        cout << "No. of 20 rs notes required are: " << rs20 <<endl;

        case 4: rs1 = amt;
        cout << "No. of 1 rs notes required are: " << rs1 <<endl;

    }
}
