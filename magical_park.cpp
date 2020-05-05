#include<iostream>
using namespace std;
void path(char arr[][100], int m, int n , int k, int s){
	bool get_out = true;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			char ch = arr[i][j];
			if(s<k){
				get_out = false;
				break;
			}
			if(ch=='*'){
				s+=5;
			}
			else if(ch=='.'){
				s-=2;
			}
			else{
				break;
			}
			if(j!=n-1){
				s--;
			}
		}
	}
	if(get_out){
		cout<<"Yes"<<endl;
		cout<<s<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}
int main() {
	int m,n,k,s;
	char park[100][100];
	cin>>m>>n>>k>>s;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>park[i][j];
		}
	}
	path(park,m,n,k,s);
	return 0;
}