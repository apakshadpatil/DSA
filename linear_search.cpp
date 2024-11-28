#include<iostream>
using namespace std;

int recurs(int array[],int n, int key, int index=0)
{
    if (index==n)
    {
        return -1;
    }
    if(array[index]==key)
    {
        return 1;
    }
    return recurs(array,n,key,index+1);
    
}
int LS_recur(int array[],int n,int key)
{
    int result=recurs(array,n,key);
    if(result==1)
    {
        cout<<"Element found";
    }
    else
    {
        cout<<"Element out of bound";
    }
    return 0;
}
int LS_non_recur(int array[],int n,int key)
{
    bool status=false;
    int found_index;
    for(int i=0;i<n;i++)
    {
        if(array[i]==key)
        {
            status=true;
            found_index=i;
        }
    }
    if(status==true)
    {
        cout<<"Element found at index:"<<found_index;
    }
    else
    {
        cout<<"Element Out of bound";
    }
    return 0;
}
int main()
{
    int n,choice;
    cout<<"Enter the size of array:";
    cin>>n;
    int array[n];
    //TAKING ELEMENTS OF ARRAY
    cout<<"Enter the values:\n";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    int key;
    cout<<"Enter the element you want to search";
    cin>>key;
    cout<<"select algorithm to search:\n1.Linear Search Recursive\n2. Linear Search Non-recursive\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
        LS_recur(array,n,key);
        break;
    
    case 2:
        LS_non_recur(array,n,key);
        break;

    default:
        break;
    }
}