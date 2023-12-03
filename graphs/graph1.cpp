#include <iostream>
#include <map>
#include <unordered_map>
#include <list>

using namespace std;

template< typename T>
class graph
{
    public:

    unordered_map< T, list<T> > adj;

    void insertedge(T u, T v, bool direction)
    {
        //direction = 0 means undirected graph
        //direction = 1 means directed graph

        adj[u].push_back(v);
        if(direction == 0)
        {
            adj[v].push_back(u); //if undirected graph
        }

    }
    void printAdjlist()
    {
        for(auto i: adj)
        {
            cout<<i.first<<"->";
            for(auto j: i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int vertex, edge;
    cout<<"Enter number of vertices: ";
    cin>>vertex;
    cout<<"Enter number of edges: ";
    cin>>edge;
    graph<int>g;
    for(int i=0;i< edge; i++)
    {
        int u,v; 
        cout<<"Enter edge "<<i+1<<": ";
        cin>>u>>v;
        g.insertedge(u,v,0);
    }
    g.printAdjlist();
}