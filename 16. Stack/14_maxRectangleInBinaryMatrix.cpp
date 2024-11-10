#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

    vector<int> nextSmallerElement(int* arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(int* arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }

int largestRectangleArea(int* heights, int n) {
    //int n = heights.size();
        
    vector<int> next(n); 
    next = nextSmallerElement(heights, n);
            
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);
        
    int area = INT_MIN;

    for(int i=0; i<n; i++) {
        int len = heights[i];
            
        if(next[i] == -1) {
            next[i] = n;
        }
        int bred = next[i] - prev[i] - 1;
        int newArea = len * bred;
        area = max(area, newArea);
    }
    return area;
}

int main() {

    int n=4, m=4;
    int mat[4][4] = {0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0};

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    //compute area of first row
    int area = largestRectangleArea(mat[0], m);

    //row update: by adding previous rows values
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] != 0)
            mat[i][j] = mat[i][j] + mat[i-1][j];
        }
        //entire row is updated now
        int newArea = largestRectangleArea(mat[i], m);
        area = max(area, newArea);
    }

    cout << area << endl;

}