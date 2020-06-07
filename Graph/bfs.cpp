#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
    map<T,list<T> > l;   //It will store neighbours for eg.2->1,3
    
public:
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    void bfs(T src){
        //we will need two data structures i.e. a queue and a visited array.
        //visited array will store true if node is visited else false.
        map<T,int> visited;
        queue<T> q;
        
        //Now insert source node and mark it as visited.
        q.push(src);
        visited[src] = true;
        
        while(!q.empty()){
            //we also need to remove the node from the start for the condition in while.
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            //Now we also need to find neighbours of the node.
            for(int nbr:l[node]){    //l[node]: list of node.
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};
int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0);
    return 0;
}
