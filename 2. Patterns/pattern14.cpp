#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int i=1;

    while(i<=n){
        
        int j=1;
        
        while(j<=n){
            char ch = (i+j+'A'-2); 
            cout << ch << " ";
            j++;
        }

        cout << endl;
        i++;
        
    }
}

// Enter n: 4
// A B C D 
// B C D E 
// C D E F 
// D E F G 

// method->

// i+j-1 krke formula bnalo pehle 
// then mapp krana hai numbers ko alphabets ke sath 
// uske liye likho->
// i+j-1 = 1  (if i=1 & j=1)
// i+j-1 + 'A'-1 = 1+ 'A-1'   (Adding 'A'-1 both the sides)
// i+j+'A'-2 = 'A'     (ban gya formula)