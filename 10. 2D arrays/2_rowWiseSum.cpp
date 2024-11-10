#include <iostream>
using namespace std;

void printRowWiseSum(int arr[3][3], int row, int col){

    cout << "Printing sum: " << endl;
    for(int row=0; row<3; row++){
        int sum = 0;
        for(int col=0; col<3; col++){
            sum += arr[row][col];
        }
        cout << sum << endl;
    }
}

int main(){

    int arr[3][3];
    
    cout << "Enter array elements: " << endl;
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            cin >> arr[row][col];
        }
    }

    cout << "Printing array elements: " << endl;
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            cout << arr[row][col] << " ";
        }cout << endl;
    }

    printRowWiseSum(arr, 3, 3);

}