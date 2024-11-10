#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//safe function for conditions to check the path
bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> arr){
    if( (x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y] == 0) && (arr[x][y] == 1) ){
        return true;
    }
    return false;
}

void solve(vector<vector<int>> &arr, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path){

    //you have reached x,y here

    //base case
    if( x == n-1 && y == n-1 ){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;  

    //4 choices - D,R,L,U

    //down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, n, visited, arr)){
        path.push_back('D');
        solve(arr, 4, ans, newx, newy, visited, path);
        path.pop_back(); //backtrack
    }

    //left
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, n, visited, arr)){
        path.push_back('L');
        solve(arr, 4, ans, newx, newy, visited, path);
        path.pop_back(); //backtrack
    }

    //right
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, n, visited, arr)){
        path.push_back('R');
        solve(arr, 4, ans, newx, newy, visited, path);
        path.pop_back(); //backtrack
    }

    //up
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, n, visited, arr)){
        path.push_back('U');
        solve(arr, 4, ans, newx, newy, visited, path);
        path.pop_back(); //backtrack
    }

    visited[x][y] = 0; //backtrack  

}

int main() {

    vector<vector<int>> arr = {{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << arr[i][j] << " ";
        } cout << endl;
    }

    /* if(arr[0][0] == 0){ //if the 1st index is (0,0)
        return ans;
    }*/

    vector<string> ans;
    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited = arr;  //initialise with 0
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            visited[i][j] = 0;
        }
    }

    string path = "";
    solve(arr, 4, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
    } 

}