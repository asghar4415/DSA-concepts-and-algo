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

void preparedAdjList(unordered_map<int, vector<int>> adjlist, vector<pair<int, int>> & edges)
{
    for(int i = 0; i < edges.size(); i++ )
    {
       int u = edges[i].first;
         int v = edges[i].second;

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
    }
}

void bfs(unordered_map<int, vector<int>> & adjList, unordered_map<int, bool> & visited, vector<int> & ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto neighbour: adjList[node])
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
    for(auto node: adjlist)
    {
        cout << node.first << "->";
        for(auto neighbour: node.second)
        {
            cout << neighbour << ",";
        }
        cout << endl;
    }
}

vector<int> BFS(int vertex, vector<pair <int, int>>edges)
{
    unordered_map<int, vector<int>> adjlist;
    vector<int> ans;
    unordered_map<int, bool> visited;

    preparedAdjList(adjlist, edges);

    printadjList(adjlist);
    cout<<endl;
//traverse all components of the graph
for(int i = 0; i < vertex; i++)
{
    if(visited[i] == false)
    {
        bfs(adjlist, visited, ans, i);
    }

}
return ans;
}


int main()
{
    int vertex = 4;
    vector<pair<int, int>> edges = {{4, 4}, {0, 1}, {0, 3}, {1, 2}, {2, 3}};
    vector<int> ans = BFS(vertex, edges);


    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}