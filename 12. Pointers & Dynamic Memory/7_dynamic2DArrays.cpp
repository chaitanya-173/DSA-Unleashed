#include <iostream>
using namespace std;

int main(){

    int row, col;
    cin >> row >> col;

    int** arr = new int*[row];

    for(int i=0; i<row; i++){
        arr[i] = new int[row];
    }
    //2D array creation done

    //taking input
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }
    //taking output
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }

    //releasing memory from HEAP manually
    for(int i=0; i<row; i++){  //deleting rows
        delete [] arr[i];
    }

    delete []arr;  //deleting column

}