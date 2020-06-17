#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(int);
    rotate(arr,arr+2,arr+n); //rotate from middle
   
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    //same can be applied oj vector

    //Next Permutation
    next_permutation(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

