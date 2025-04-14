#include<iostream>
using namespace std;

#define SIZE 100

char stack[SIZE];
int top=-1;

void push(char ch)
{
    stack[++top]=ch;
}
char pop()
{
    return stack[top--];
}

int main()
{
    string str;
    cout<<"Enter a string:";
    cin>>str;

    //push all character to stack
    for(int i=0;str[i]!='\0';i++)
    {
        push(str[i]);
    }
    //pop all characters to reverse
    for(int i=0;str[i]!='\0';i++)
    {
        str[i]=pop();
    }
    cout<<"Reversed String:"<<str<<endl;
    return 0;
}
