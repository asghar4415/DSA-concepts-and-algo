#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int prim(vector<vector<pair<int, int>>>& adj, int vertices) {
    vector<int> distance(vertices, INT32_MAX);
    vector<bool> visited(vertices, false);
    vector<int> parent(vertices, -1);

    distance[0] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        int u = -1;
        for (int j = 0; j < vertices; j++) {
            if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                u = j;
            }
        }

        visited[u] = true;

        for (auto neig : adj[u]) {
            int v = neig.first;
            int w = neig.second;

            if (!visited[v] && w < distance[v]) {
                distance[v] = w;
                parent[v] = u;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < vertices; i++) {
        if (parent[i] != -1) {
            sum += distance[i];
        }
    }

    return sum;
}

int main() {

   

    int vertices, edges;
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    cout<<"Enter number of edges: ";
    cin>>edges;
     vector<vector<pair<int, int>>> adj(vertices);
    for(int i=0;i< edges; i++)
    {
        int u,v,w; 
        cout<<"Enter edge "<<i+1<<": ";
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }



    int sum = prim(adj, vertices);

    cout << "Sum of weights of the Minimum Spanning Tree: " << sum << endl;

    return 0;
}
