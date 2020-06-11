#include<bits/stdc++.h>
using namespace std;


template<class ForwardIterator,class T> //<container,data>
//it accept starting and ending point of container
//this iterator can work on different containers also, instead of list we can also use any other container.
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key){
    while(start!=end){
        if(*start == key){
            return start;
        }
        start++;
    }
    return end;
} 
int main(){
    
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    //l.begin here is an iterator
    auto it = search(l.begin(),l.end(),30);
    if(it == l.end()){
        cout<<"Not found";
    }
    else{
    cout<<*it;
    }
    
    return 0;
}
