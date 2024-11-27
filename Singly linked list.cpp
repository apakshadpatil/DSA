#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
struct node *head =NULL;
//insert at begining
void InsertAtBegining(int data)
{
    node* newNode = new node();
    newNode->data=data;
    newNode->next=head;
    head=newNode;
    cout<<"Inserted at begining";
}

//insert at end
void InsertAtEnd(int data)
{
    node* newNode = new node();
    newNode->data=data;
    newNode->next=NULL;
    if(head==nullptr)
    {
        head=newNode;
    }
    else
    {
        node* temp=head;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    cout<<"Inserted at the end:"<<data<<endl;
}
//inserting at a specific position
void insertAtPosition(int data,int position)
{
    node* newNode = new node();
    newNode->data=data;

    if(position==1)
    {
        newNode->next=head;
        head=newNode;
    }
    else
    {
        node* temp=head;
        for(int i=0;i<position-1 && temp != nullptr;i++)
        {
            temp=temp->next;
        }
        if(temp==nullptr)
        {
            cout<<"Position out of bounds!"<<endl;
            return;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    cout<<"Inserted at position"<<position<<":"<<data<<endl;
}
//delete from begining
void deleteFromBegining()
{
    if(head==nullptr)
    {
        cout<<"Error: List is empty"<<endl;
        return;
    }
    node* temp=head;
    head=temp->next;
    delete temp;
    cout<<"Delete from begining"<<endl;
}
//delete form end
void deleteFromEnd()
{
    if(head==nullptr)
    {
        cout<<"Error:List is empty!"<<endl;
        return;
    }
    if(head->next==nullptr)
    {
        delete head;
        head=nullptr;
    }
    else
    {
        node* temp = head;
        while(temp->next->next!=nullptr)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;
    }
    cout<<"Delete from the end"<<endl;
}
//Traversing the list
void traverseList()
{
    node* temp =head;
    if(temp==nullptr)
    {
        cout<<"Error:List is empty"<<endl;
        return;
    }
    while(temp->next!=nullptr)
    {
        cout<<temp->data<<";"<<endl;
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
//searching for a value
void SearchInList(int value)
{
    node* temp=head;
    while(temp!=nullptr)
    {
        if(temp->data==value)
        {
            cout<<"Value found"<<value<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"Value no found\n";
}
int main()
{
InsertAtBegining(10);
InsertAtEnd(20);
insertAtPosition(15,2);
traverseList();
deleteFromBegining();
traverseList();
deleteFromEnd();
traverseList();
SearchInList(20);
SearchInList(15);
return 0;
}
