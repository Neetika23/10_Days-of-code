#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	//loops for first component
	cout<<"*";
	for(int i=1;i<=(n-3)/2;i++){
		cout<<" ";
	}
	for(int i=1;i<=(n+1)/2;i++){
		cout<<"*";
	}
	cout<<endl;
	//loops for second component
	for(int i=1;i<=(n-3)/2;i++){
		cout<<"*";
		for(int j=1;j<=(n-3)/2;j++){
			cout<<" ";
		}
		cout<<"*";
		cout<<endl;
	}
	//loops for third component
	for(int i=1;i<=n;i++){
		cout<<"*";
	}
	cout<<endl;
	//loops for fourth component
	for(int i=1;i<=(n-3)/2;i++){
		for(int j=1;j<=(n-3)/2+1;j++){
			cout<<" ";
		}
		cout<<"*";
		for(int k=1;k<=(n-3)/2;k++){
			cout<<" ";
		}
		cout<<"*";
		cout<<endl;
	}
	//loops for fifth component
	for(int i=1;i<=(n+1)/2;i++){
		cout<<"*";
	}
	for(int i=1;i<=(n-3)/2;i++){
		cout<<" ";
	}
	cout<<"*";
	return 0;
}