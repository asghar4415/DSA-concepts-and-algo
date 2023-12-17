#include<iostream>
using namespace std;

class Graph{
    int v;
    int **adj;

    public:
    Graph(int v)
    {
        this->v=v;
        adj=new int*[v];
        for(int i=0;i<v;i++)
        {
            adj[i]=new int[v];
            for(int j=0;j<v;j++)
            {
                adj[i][j]=0;
            }
        }
    }
    void addEdge(int u,int v)
    {
        adj[u][v]=1;
        adj[v][u]=1;
    }
    void display()
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void dfs(int s)
    {
        bool *visited=new bool[v];
        for(int i=0;i<v;i++)
        {
            visited[i]=false;
        }
        int *q=new int[v];
        int top=-1;
        q[++top]=s;
        visited[s]=true;
        while(top!=-1)
        {
            int u=q[top--];
            cout<<u<<" ";
            for(int i=0;i<v;i++)
            {
                if(adj[u][i]==1 && visited[i]==false)
                {
                    visited[i]=true;
                    q[++top]=i;
                }
            }
        }
    }

    void adjlist()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"->";
            for(int j=0;j<v;j++)
            {
                if(adj[i][j]==1)
                {
                    cout<<j<<" ";
                }
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,4);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);

   g.display();
    cout<<endl;

    cout<<"DFS: ";
   g.dfs(0);
    cout<<endl;

    g.adjlist();
    return 0;
}