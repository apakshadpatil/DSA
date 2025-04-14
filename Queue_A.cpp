#include<iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front=-1,rear=-1;

void enqueue(int value){
    if(rear==SIZE-1)
    {
        cout<<"Queue Overflow\n";
    }
    else
    {
        if(front==-1) front=0;
        rear++;
        queue[rear]=value;
    }
}
void dequeue()
{
    if(front==-1 || front>rear)
    {
        cout<<"Queue Underflow\n";
    }
    else
    {
        cout<<queue[front]<<" popped\n";
        front++;
    }
}
void display(){
    if(front==-1 || front>rear)
    {
        cout<<"No Elements in Queue";
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    return 0;
}