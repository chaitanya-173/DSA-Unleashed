#include <iostream>
using namespace std;

int firstOcc(int arr[], int size, int key){

    int strt = 0, end = size-1;
    int mid = strt + (end-strt)/2;
    int ans = -1;

    while(strt <= end){

        if(arr[mid] == key){
        ans = mid;
        end = mid-1;
        }

        else if(arr[mid] < key){
        strt = mid+1;
        }

        else{
        end = mid-1;
        }

        mid = strt + (end-strt)/2;

    }
    return ans;
}

int lastOcc(int arr[], int size, int key){

    int strt = 0, end = size-1;
    int mid = strt + (end-strt)/2;
    int ans = -1;

    while(strt <= end){

        if(arr[mid] == key){
        ans = mid;
        strt = mid+1;
        }

    else if(arr[mid] < key){ // ryt mein jao
        strt = mid+1;
        }

    else{              // left mein jao
        end = mid-1;
        }

    mid = strt + (end-strt)/2;

    }
    return ans;
}

int main(){
    int arr[11] = {1,2,3,3,3,3,3,3,3,3,5};

    cout<< "The first occurence of 3 is at index: " << firstOcc(arr, 11, 3) <<endl;
    cout<< "The last occurence of 3 is at index: " << lastOcc(arr, 11, 3) <<endl;

    cout<< "Total no. of occurence of 3 are: " << (lastOcc(arr,11,3) - firstOcc(arr,11,3)) + 1 ;
}

