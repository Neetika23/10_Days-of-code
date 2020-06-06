#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
//A -> (B,20),(D,50),(C,10)   i.e. (neighbour, weight)
//B -> (A,20), (D,30)
//C-> (A,10), (D,40)
//D-> (B,30), (C,40)
class Graph{
   
   //Adj list
   //list of of unordered_map type and it contain string (Key) with he value
   //as the list of pair of string and int.
   unordered_map<string,list<pair<string,int> > > l;
   
public:
    void addEdge(string x, string y, bool bidir, int wt){
        l[x].push_back(make_pair(y,wt)); // l[A] will have (B,20)
        if(bidir){
            l[y].push_back(make_pair(x,wt));
        }
    }
    void printList(){
        //iterate over all key in map.
        for(auto p :l){  //string and pairs are clubed into the pair.
            string city = p.first;
            list<pair<string,int> > neighbours = p.second;
            
            cout<<city<<"->";
            for(auto n:neighbours){ //for pair of string and int (B,20)
                string dest = n.first;
                int dist = n.second;
                
                cout<<dest<<" "<<dist<<",";
            }
            cout<<endl;
        }   
    }
};
int main(){
    
    Graph g; 
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,30);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);
    g.printList();
    
    return 0;
}
