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
    void bfs(int s)
    {
        bool *visited=new bool[v];
        for(int i=0;i<v;i++)
        {
            visited[i]=false;
        }
        visited[s]=true;
        int *q=new int[v];
        int front=0,rear=0;
        q[rear]=s;
        while(front<=rear)
        {
            int u=q[front];
            cout<<u<<" ";
            front++;
            for(int i=0;i<v;i++)
            {
                if(adj[u][i]==1 && visited[i]==false)
                {
                    visited[i]=true;
                    rear++;
                    q[rear]=i;
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
    cout<<"BFS: ";
    g.bfs(0);
    cout<<endl;

    

    g.adjlist();
    return 0;
}