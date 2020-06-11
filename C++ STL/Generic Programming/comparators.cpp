#include<bits/stdc++.h>
using namespace std;

//compartors -> searching on any kind of data (we have to define some comparison)
//we got freedom from datatype whether its list or vector or anything else.
//we got freedom from custom comaprisons
//and also from underlying container.
class Book{
    public:
        string name;
        int price;
    Book(){   //default constructor


    }

    Book(string name, int price){  //Parameterized constructor
        this->name = name;
        this->price = price;
    }
};

class BookCompare{
    public:
        bool operator()(Book a, Book b){  //overloaded () operator with the object of BookCompare
                            //if obj name is cmp then we use cmp(), this looks lika func call but cmp is actually obj.
                            //its a functional obj.
            
            if(a.name == b.name){
                return true;
            }
            return false;
        }
};

//this is how stl classes/functions are implemented.
template<class ForwardIterator,class T, class Compare> 
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp){
    while(start!=end){
        if(cmp(*start,key)){
            return start;
        }
        start++;
    }
    return end;
} 
int main(){
    
    Book b1("C++",100);  //old edition of c++
    Book b2("Python",120);
    Book b3("Java",130);
    

    //list<Book> l;
    vector<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);
    
    Book key("C",110);  //new edition of c++
    BookCompare cmp;

    auto it = search(l.begin(),l.end(),key, cmp);
    if(it!=l.end()){
        cout<<"Book Found";
    }
    else{
        cout<<"Not found";
    }
    /*
    if(cmp(b1,key)){
        cout<<"SameBooks";
    }
    */

    return 0;
}
