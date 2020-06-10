#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int> >
#define mk(arr,n,type) type *arr = new type(n);
#define w(x) int x; cin>>x; while(x--)
using namespace std;
int main(){
    w(t){
        int n;
        cin>>n;
        mk(arr,n,int);
        
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        int cnt[2] = {};
        for(int i=1;i<=n;i++){
            cnt[arr[i]%2]++;
        }
        if(cnt[0] & cnt[1]){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    return 0;
}
