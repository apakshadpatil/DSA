#include<iostream>
using namespace std;

const int MAX_V=5;
int graph[MAX_V][MAX_V];

void addEdge(int u, int v)
{
    graph[u][v]=1;
    graph[v][u]=1;
}
void printGraph()
{
    for(int i=0;i<MAX_V;i++)
    {
        for(int j=0;j<MAX_V;j++)
        {
            cout<< graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);
    addEdge(3,4);

    cout<<"Adjacency matrix:\n";
    printGraph();

    return 0;
}