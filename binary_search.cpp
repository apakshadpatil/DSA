#include<iostream>
using namespace std;
int recurs(int array[],int left,int right,int key)
{
    if(left<=right)
    {
        int mid=left+(right-left)/2;

        if(array[mid]==key)
        {
            return 1;
        }
        if(array[mid]>key)
        {
            return recurs(array,left,mid-1,key);
        }
        else{
            return recurs(array,mid+1,right,key);
        }
    }
    return 0;
}
int BS_recursive(int array[],int n, int key)
{
    int result=recurs(array,0,n-1,key);
    if(result==1)
    {
        cout<<"Element found";
    }
    else{
        cout<<"Element out of bound";
    }
    return 0;
}
int BS_non_recursive(int array[],int n, int key)
{
    int left=0,right=n-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;

        if(array[mid]==key)
        {
            cout<<"Element Found at index:"<<mid;
            break;
        }
        if(key<array[mid])
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return 0;
}

int main()
{
    int n,key;
    cout<<"Enter the number of elements:";
    cin>>n;
    int array[n];
    //taking array values
    cout<<"Enter the values of array:\n";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    //asking key
    cout<<"\nEnter the element you want to search:";
    cin>>key;
    int choice;
    cout<<"Select algorithm to search:\n1.Recursive\n2.Non-recursive\n--->";
    cin>>choice;
    switch (choice)
    {
    case 1:
        BS_recursive(array,n,key);
        break;
    
    case 2:
        BS_non_recursive(array,n,key);
        break;

    default:
        break;
    }
}