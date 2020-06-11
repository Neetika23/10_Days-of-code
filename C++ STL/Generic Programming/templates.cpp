#include<iostream>
using namespace std;

template<typename T>
int search(T arr[],int n,T key){
    for(int pos=0;pos<n;pos++){
        if(arr[pos] == key){
            return pos;
        }
    }
    return n;
}
int main(){
    //Make algorithms generic
    //making linear search a generic function
    //we want to make linear search work on every type
    int arr[] = {1,4,3,2,5};
    int n = sizeof(arr)/sizeof(int);
    int key = 2;
    //cout<<search(arr,n,key)<<endl;
    
    float b[] = {1.1,1.2,1.3};
    float k = 1.2;
    cout<<search(b,3,k);
    
    return 0;
}
