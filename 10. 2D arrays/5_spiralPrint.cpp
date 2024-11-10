#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralPrint(int matrix[3][3],int row, int col){

    vector<int> ans;

    int count = 0;
    int total = row * col;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;

    while(count < total){

        //print starting row
        for(int index = startingCol; count < total && index<endingCol; index++){
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        //print ending column
        for(int index = startingRow; count < total && index<endingRow; index++){
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        //print ending row
        for(int index = endingCol; count < total && index>=startingCol; index++){
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        //print starting column
        for(int index = endingRow; count < total && index>=startingRow; index++){
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;

    }
    return ans;
}

void print(vector<int> v){

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}

int main(){

    int matrix[3][3] = {1,2,3,4,5,6,7,8,9};
    cout << "Enter array elements: " << endl;

    // for(int row=0; row<4; row++){
    //     for(int col=0; col<4; col++){
    //         cin >> matrix[row][col];
    //     }
    // }

    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            cout << matrix[row][col] << " ";
        }cout << endl;
    }

    cout << "Spiral print: " << endl;
    print(spiralPrint(matrix, 3, 3));

}