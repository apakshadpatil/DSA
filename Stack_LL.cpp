#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
void pop(node* &top)
{
    if(top==nullptr)
    {
        cout<<"Stack underflow";
    }
    else
    {
        node* temp=top;
        top=top->next;
        delete temp;
    }
}
void push(node* &top,int data)
{
    node* newnode = new node;
    newnode->data=data;
    newnode->next=top;
    top=newnode;
}
void display(node* &top)
{
    node* temp=top;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";

}
int main()
{
    node* top = nullptr;

    push(top, 10);
    push(top, 20);
    push(top, 30);
    display(top);

    pop(top);
    display(top);

    return 0;
}