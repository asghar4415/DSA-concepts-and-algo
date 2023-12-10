#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

//Breadth First Search: (BFS)  
//BFS is a traversing algorithm where you should start traversing from a selected node (source or starting node) 
//and traverse the graph layerwise thus exploring the neighbour nodes (nodes which are directly connected to source node).
//You must then move towards the next-level neighbour nodes.
//As the name BFS suggests, you are required to traverse the graph breadthwise as follows:
//1. First move horizontally and visit all the nodes of the current layer
//2. Move to the next layer

//BFS uses a queue data structure for storing the nodes.
//Whenever a node is visited, all its neighbours are added to the queue.


void preparedAdjList(unordered_map<int, vector<int>> & adjlist, vector<pair<int, int>> edges)
{
    for(auto edge: edges)
    {
        adjlist[edge.first].push_back(edge.second);
        adjlist[edge.second].push_back(edge.first);
    }
}


void bfs(unordered_map<int, vector<int>> adjlist, unordered_map<int, bool> & visited, vector<int> & ans, int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto neighbour: adjlist[node])
        {
            if(visited[neighbour] == false)
            {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}


void printadjList(unordered_map<int, vector<int>> adjlist)
{
    for(auto i: adjlist)
    {
        cout<<i.first<<"->";
        for(auto j: i.second)
        {
            cout<<j<<",";
        }
        cout<<endl;
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, bool> visited;
    vector<int> ans;

    preparedAdjList(adjList, edges);
    // printadjList(adjList);

    for(int i = 1; i <=vertex; i++)
    {
        visited[i] = false;
    }

    for(int i = 1; i <=vertex; i++)
    {
        if(visited[i] == false)
        {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}


int main()
{
    int vertex, edge;
    cout<<"Enter number of vertices: ";
    cin>>vertex;
    cout<<"Enter number of edges: ";
    cin>>edge;
    vector<pair<int, int>> edges;
    for(int i=1;i<=edge; i++)
    {
        int u,v; 
        cout<<"Enter edge "<<i<<": ";
        cin>>u>>v;
        edges.push_back({u,v});
    }
    vector<int> ans = BFS(vertex, edges);
    for(auto i: ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}