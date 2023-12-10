#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>

using namespace std;

//shortest path undirected graph


vector<int> shortestpath(vector <pair<int,int>>edges, int n , int m , int s, int t )
{
    unordered_map<int, list<int>>adj;
    for(auto edge: edges)
    {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    unordered_map<int, bool>visited;
    unordered_map<int, int>parent;
    queue<int>q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto i: adj[curr])
        {
            if(!visited[i])
            {
                visited[i] = true;
                parent[i] = curr;
                q.push(i);
            }
        }
    }
    //prepare shortest path
vector<int>path;
int curr = t;
path.push_back(curr);

while(curr != s)
{
    curr = parent[curr];
    path.push_back(curr);
    

}

return path;

}

int main()
{
    int v= 5, e=6;
    vector<pair<int,int>>edges;
    edges.push_back({0,1});
    edges.push_back({0,2});
    edges.push_back({1,3});
    edges.push_back({3,4});
    edges.push_back({1,4});
    edges.push_back({2,4});
    
    vector<int>path = shortestpath(edges, v, e, 0, 4);
    for(int i=path.size()-1; i>=0; i--)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
