#include <iostream>
using namespace std;

int main(){
    
    int n;
    cout << "Enter n: ";
    cin >> n;

    int i=1;

    while(i<=n){
        
        int j=1;
        char value = ('A'+n-i);

        while(j<=i){
            
            cout << value << " ";
            value++;
            j++;
        }

        cout << endl;
        i++;

    }
}


// Enter n: 4
// D 
// C D 
// B C D 
// A B C D 