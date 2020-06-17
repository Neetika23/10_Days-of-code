#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    int arr[] = {10,20,40,50,60,60,60,60,70};
    int n = sizeof(arr)/sizeof(int);

    //Search --> find

    int key = 60;
    /* auto it = find(arr,arr+n,key);
    int index = it - arr;
    if(index == n){
        cout<<"Not found";
    }
    else{
        cout<<index;
    } */

    //search  --> binary search
    bool present = binary_search(arr,arr+n,key);
    if(present){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not"<<endl;
    }

    //getting index
    //lower_bound(start,end,key) and upper_bound(start,end,key)

    auto it = lower_bound(arr,arr+n,60);
    cout<<(it-arr)<<endl;

    auto it1 = upper_bound(arr,arr+n,60);
    cout<<(it1-arr)<<endl;

    cout<<"Occurence of 60 are:"<<(it1 - it);

    return 0;
}
