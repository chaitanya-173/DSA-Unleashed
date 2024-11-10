#include <iostream>
using namespace std;

int main() {
    cout << "Basic Knowledge about arrays: " << endl;
}

/*

Comparison between the following declarations:

int ans[n];
vector<int> ans(n);
vector<int> ans[n];
vector<vector<int>> ans(n);

1. int ans[n];
This declares a fixed-size array of integers with n elements.

Type: A static array of n integers.
Fixed size: The size of the array is determined at compile-time 
and cannot be changed at runtime. Once the array is declared, its size is fixed.
Memory allocation: Memory is allocated on the stack (in most cases).

Example: 
int n = 5;
int ans[n];  // Creates an array of size 5

ans[0] = 10;  // Access the elements like a normal array
ans[1] = 20;

2. vector<int> ans(n);
This declares a dynamic vector of integers with n elements, 
all initialized to 0 by default.

Type: A dynamic 1D array (vector) of integers.
Dynamic size: The size of the vector can change at runtime. It is 
initialized with n elements, but you can add or remove elements dynamically.
Memory allocation: Memory is allocated on the heap.

Example: 
int n = 5;
vector<int> ans(n);  // Creates a vector of size 5, all initialized to 0

ans[0] = 10;  // You can access and modify elements like an array
ans.push_back(20);  // Add a new element to the vector

3. vector<int> ans[n];
This declares a fixed-size array of vectors of integers. The array size 
is n, but each vector can be dynamically resized.

Type: A static array of n vectors of integers.
Fixed size: The array ans has a fixed size of n, but each individual 
vector<int> in the array can be dynamically resized.
Memory allocation: The array is allocated on the stack, but the individual 
vectors are allocated on the heap.

Example:
int n = 3;
vector<int> ans[n];  // Creates an array of 3 vectors

ans[0].push_back(1);  // Add elements to the first vector
ans[1].push_back(2);  // Add elements to the second vector
ans[2].push_back(3);  // Add elements to the third vector

4. vector<vector<int>> ans(n);
This declares a dynamic vector of vectors, with n inner vectors (each vector of integers).

Type: A dynamic 2D vector (a vector of n vectors, each of type vector<int>).
Dynamic size: Both the outer vector (number of rows) and the inner 
vectors (number of columns) can be resized dynamically.
Memory allocation: Both the outer vector and the inner vectors are allocated on the heap.

Example:
int n = 3;
vector<vector<int>> ans(n);  // Creates a vector of 3 empty vectors

ans[0].push_back(1);  // Add elements to the first inner vector
ans[1].push_back(2);  // Add elements to the second inner vector
ans[2].push_back(3);  // Add elements to the third inner vector


Which one is like a 2D matrix?

vector<vector<int>> ans(n) is closest to a dynamic 2D matrix because both 
dimensions (rows and columns) can be resized at runtime.

vector<int> ans[n] can also act like a 2D matrix, but the number of rows (n) 
is fixed at compile-time, making it less flexible than vector<vector<int>> ans(n).

*/