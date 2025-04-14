#include<iostream>
using namespace std;

int main(){
//logic
int u;
int i=0;//i se start kar rahe hai traverse karna 
int visited[7]={0,0,0,0,0,0,0};
int a [7][7] ={
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};
visited[i]=1;
enqueue(&q,i);//&q yeh queue ka struct hai isiliye aisa likha hai nai toh apan array de denge
while(isEmpty(&q))
{
    int node=dequeue(&q);
    for(int j=0;j<7;j++)
    {
        if(a[node][j]==1 && visited[j]==0)
        {
            print("%d",j);
            visited[j]=1;
            enqueue(&q,j);
        }
    }
}
}