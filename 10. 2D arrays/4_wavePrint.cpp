#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(int arr[][3], int nRows, int mCols){

    vector<int> ans;

    for(int col=0; col<mCols; col++){

        if(col & 1){  //odd index -> bottom to top
            for(int row=nRows-1; row>=0; row--){
                ans.push_back(arr[row][col]);
            }
        }

        else{  //even index -> top to bottom
            for(int row=0; row<nRows; row++){
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

void print(vector<int> v){

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
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

    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            cout << arr[row][col] << " ";
        }cout << endl;
    }

    cout << "Wave print: " << endl;
    print(wavePrint(arr, 3, 3));
    
}
