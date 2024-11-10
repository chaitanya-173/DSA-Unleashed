#include <iostream>
using namespace std;

int main(){

    int a=4;
    int b=6;

    cout << "a&b: " << (a&b) << endl;  // Bitwise AND operator
    cout << "a|b: " << (a|b) << endl;  // Bitwise OR operator
    cout << "~a: " << (~a) << endl;  // Bitwise NOT operator
    cout << "a^b: " << (a^b) << endl;  // Bitwise XOR operator

    cout << (17>>1) << endl;  // Right shift operator
    cout << (17>>2) << endl;
    cout << (19<<1) << endl;  // Left shift operator
    cout << (21<<2) << endl;

    int i=7;

    cout << (++i) << endl;  // Pre increment operator
    cout << (i++) << endl;  // Post increment operator
    cout << (i--) << endl;  // Post decrement operator
    cout << (--i) << endl;  // Pre decrement operator

}

// a=4 -> 100
// b=6 -> 110
// a&b -> 100 -> 4
// a|b -> 110 -> 6
// a^b -> 010 -> 2

// a ->   000000...100
// ~a ->  111111...011     (1 in the end states -ve number)
// 1s' -> 000000...100
// 2s' ->           +1 
// ~a  ->          101 ->  -5


// (17>>1) -> 17/2 = 8
// (17>>2) -> 17/(2*2) = 4
// (19<<1) -> 19*2 = 38
// (21<<2) -> 21*(2*2) = 84


// i=7
// (++i) -> 8
// (i++) -> 8  (i=9)
// (i--) -> 9  (i=8)
// (--i) -> 7
