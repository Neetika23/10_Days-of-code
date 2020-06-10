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
#define mk(arr,n,type) type *arr = new type[n];
#define w(x) int x; cin>>x; while(x--)
using namespace std;
int main(){
    //There will be two types of palindrome of atleast length 3.
    //1. x x x
    //2. x y x
    //Our ans will YES in the case, if thers is onw element whose freq is >= 3,
    //and also in the case where the two X are not adjacent to each other, there is some Y between them.
    w(t){
        int n;
        cin>>n;
        mk(arr,n+1,int);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        string ans ="NO";
        
        map<int,vi> idv;  //store ele with its indices where it occurs.
        for(int i=1;i<=n;i++){
            idv[arr[i]].pb(i);
        }
        
        //check for freq >=3 
        for(auto el: idv){  //iterating over map
            if(el.ss.size()>=3){
                ans = "YES";
                break;
            }
        }
        
        //and ele non adj to each other
        for(auto el : idv){
            if(el.ss.size()==2 && el.ss[0]!=el.ss[1]-1){
                ans = "YES";
                break;
            }
        }
        cout<<ans<<'\n';
        
    }
    return 0;
}
