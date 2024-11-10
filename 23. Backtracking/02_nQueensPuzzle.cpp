#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {

	vector<int> temp;

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			temp.push_back(board[i][j]);
		}
	}

	ans.push_back(temp);
}

/*   (we can use map for optimising T.C from O(n) to O(1) for isSafe functions)
unordered_map<int,bool> rowCheck;
unordered_map<int,bool> upperLeftDiagnolCheck;
unordered_map<int,bool> bottomLeftDiagnolCheck;

bool isSafe(vector<string> &board, int row, int col, int n) {

    if(rowCheck[row] == true )
        return false;
        
    if(upperLeftDiagnolCheck[n-1+col-row] == true)
        return false;
        
    if(bottomLeftDiagnolCheck[row+col] == true)
        return false;

    return true;
}
*/

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {

	int x = row;
	int y = col;
	//check for same row
	while(y>=0) {
		if(board[x][y] == 1) {
			return false;
		}
		y--;
	}

	x = row;
	y = col;
	//check for left upper diagonal
	while(x>=0 && y>=0) {
		if(board[x][y] == 1) {
			return false;
		}
		y--;
		x--;
	}

	x = row;
	y = col;
	//check for left lower diagonal
	while(x<n && y>=0) {
		if(board[x][y] == 1) {
			return false;
		}
		y--;
		x++;
	}

	return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
	//base case
	if(col == n) {
		addSolution(ans, board, n);
		return;
	}

	//solve 1 case aur baaki RECURSION sambhal lega

	for(int row=0; row<n; row++) {
		if(isSafe(row, col, board, n) ) {
			//if placing queen is safe
			board[row][col] = 1;
			solve(col+1, ans, board, n);
			//backtrack
			board[row][col] = 0;
		}
	}
}

vector<vector<int>> nQueens(int n) {
	vector<vector<int>> board(n, vector<int>(n,0));
	vector<vector<int>> ans;

	solve(0, ans, board, n);

	return ans;
}

void printSolution(vector<vector<int>> &solutions, int n) {
    for (int i = 0; i < solutions.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (int j = 0; j < n * n; j++) {
            cout << solutions[i][j] << " ";
            if ((j + 1) % n == 0)
                cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n (size of the chessboard): ";
    cin >> n;

    vector<vector<int>> solutions = nQueens(n);

    if (solutions.size() == 0) {
        cout << "No solutions exist for " << n << " queens.\n";
    } else {
        cout << "Total solutions: " << solutions.size() << "\n\n";
        printSolution(solutions, n);
    }

    return 0;
}