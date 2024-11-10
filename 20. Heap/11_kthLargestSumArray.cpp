#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int getKthLargest(vector<int> &arr, int k) {

    vector<int> sumStore;
    int n = arr.size();

    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    for(int i=0; i<sumStore.size(); i++) {
        cout << sumStore[i] << " ";
    } cout << endl;

    sort(sumStore.begin(), sumStore.end());
    return sumStore[sumStore.size()-k];

}

int main() {

    vector<int> arr{1,2,6,4,3};

    cout << endl << getKthLargest(arr, 2);


}