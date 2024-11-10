#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateMatrix(int mat[3][3], int row, int col){

    vector<int> ans;

    for(int col=0, i=0; col<3, i=3; col++, i++){
        for(int row=2, j=0; row>=0, j<3; row--, j++){
            ans.push_back(mat[row][col]);
        }
    }

    return ans;

}

void print(vector<int> v){
    for(int i=0; i<3; i++){ 
        for(int j=0; j<3; j++){ 
            cout << v[i][j] << " "; 
        }     
        cout << endl; 
    } 
}

int main(){

    int mat[3][3] = {1,2,3,4,5,6,7,8,9};
    

    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            cout << mat[row][col] << " ";
        }cout << endl;
    }

    print(rotateMatrix(mat, 3, 3));

}