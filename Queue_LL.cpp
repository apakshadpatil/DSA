#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* front=nullptr;
node* rear=nullptr;
void enqueue(int value){
    node* temp = new node;
    temp->data=value;
    temp->next=nullptr;

    if(rear==nullptr)
    {
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}
void dequeue()
{
    if(front==nullptr)
    {
        cout<<"Queue UnderFlow\n";
        return;
    }
    node* temp=front;
    front=front->next;
    cout<<temp->data<<"->dequeued\n";
    delete temp;

    if(front==nullptr)
        rear=nullptr;
}
void display()
{
    node* temp=front;
    if(temp==nullptr)
    {
        cout<<"Queue is empty\n";
        return;
    }
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
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