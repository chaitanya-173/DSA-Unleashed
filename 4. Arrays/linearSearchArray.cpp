#include <iostream>
using namespace std;

bool search(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}

int main(){

    int arr[10] = {5, 7, -2, 18, 9, 11, 7, 3, -6, 1};

    int key;
    cout << "Enter the element to search for: ";
    cin >> key;

    bool found = search(arr, 10, key);

    if(found){
        cout << "Key is present" << endl;
    }
    else{
        cout << "Key is absent" << endl;
    }
    
}