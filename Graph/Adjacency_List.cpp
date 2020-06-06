#include<iostream>
#include<list>
using namespace std;
class Graph{
    int V;
    //Array of list
    list<int> *l; //we kept pointer to array of list because initially we 
                    //dont know about number of vertices.
public:
    Graph(int V){
        this->V = V; //This tells we have V vertices in a graph
        //l is pointer to array in which each element of array is a list.
        l = new list<int>[V];
        //means l[0] = 1,2 | l[1] = 2,0 and so on.
    }
    void addEdge(int x,int y){ //Assuming its a bidirectional edge
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printList(){
        //iterate over all vertices
        for(int i=0;i<V;i++){
            cout<<"Vertex"<<i<<"->";
            for(int x:l[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g(4); //Graph with 4 vertices
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.printList();
    
    return 0;
}
