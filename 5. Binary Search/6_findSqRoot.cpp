#include <iostream>
using namespace std;

long long int sqRtint(int num){

    int s = 0, e = num;
    long long int m = s + (e-s)/2;
    long long int ans = -1;

    while(s<=e){

        long long int square = m*m;  // edge case (int limit can be exceeded)

        if(square == num)
        return m;

        else if(square < num){
        ans = m;
        s = m+1;
        }

        else
        e = m-1;

        m = s + (e-s)/2;
    }
    return ans;
}

double morePrecision(int n, int precision, int tempSol) {
    
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++) {
        factor = factor/10;

        for(double j=ans; j*j<n; j= j+factor ){
            ans = j;
        }
    }
    return ans;
}

int main(){

    int num;
    cin >> num;

    int tempSol = sqRtint(num);
    
    cout << "The square root of " << num << " is: " << sqRtint(num) << endl;
    cout <<"Answer is " << morePrecision(num, 3, tempSol) << endl;
}