#include<bits/stdc++.h>
using namespace std;

int partition(int *a, int s, int e){
    int i = s-1;
    int j = s;
    int p = a[e];
    for(;j<=e-1;){
        if(a[j]<=p){
            i = i + 1;
            swap(a[i],a[j]);
        }
        j++;
    }
    //place pivot in correct index
    swap(a[i+1],a[e]);
    return i+1;
}
void quicksort(int *a, int s, int e){
    //base case
    if(s>=e){
        return;
    }
    
    
    //recursive case
    int p = partition(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}
int main(){
    /*int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }*/
    int a[] = {3,2,5,6};
    int n = sizeof(a) / sizeof(int);
    quicksort(a,0,n-1);
    for(int i=0;i<=n-1;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
