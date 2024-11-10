#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> v){

    for(int i=0; i<v.size()/2; i++){
        swap(v[i], v[v.size()-i-1]);
    }
    return v;
}

void print(vector<int> v){

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}

int main(){
    
    vector<int> v;
    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(4);

    cout << "Original vector -> ";
    print(v);
    cout << endl;
    
    vector<int> ans = reverse(v);
    cout << "Reversed vector -> ";
    print(ans);

}