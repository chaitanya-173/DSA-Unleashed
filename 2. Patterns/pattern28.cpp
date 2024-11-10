#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int i=1;

    while(i<=n){

        int nos=1;
        while(nos<=(n-i+1)){
            cout << nos << " ";
            nos++;
        }

        int star=1;
        while(star<=(2*i-2)){
            cout << "* ";
            star++;
        }

        int j=1;
        while(j<=(n-i+1)){
            cout << (n-j-i+2) << " ";
            j++;
        }

        cout << endl;
        i++;

    }

    int k=2;

    while(k<=n){

        int l=1;
        while(l<=k){
            cout << l << " ";
            l++;
        }   

        int star2=1;
        while(star2<=(2*(n-k))){
            cout << "* ";
            star2++;
        }

        int nos2=1, count=k;
        while(nos2<=k){
            cout << count << " ";
            count--;
            nos2++;
        }

        cout << endl;
        k++;

    }
}
