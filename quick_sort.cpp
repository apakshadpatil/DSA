#include<iostream>
using namespace std;
int partition(int A[],int low, int high)
{
    int pivot=A[low];
    int i=low+1;
    int j=high;
    
    do{
        while(A[i]<=pivot)
        {
            i++;
        }   
        while(A[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<j);
    int temp = A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
}
void QuickSort(int A[],int low,int high)
{
    int partitionIndex;//index of pivot after partition
    if(low<high){
        partitionIndex=partition(A,low,high);
        QuickSort(A,low,partitionIndex-1);//sort left sub array
        QuickSort(A,partitionIndex+1,high);//sort right sub array
    }
}
void printArray(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int A[n];
    cout<<"Enter the values of array:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    printArray(A,n);
    QuickSort(A,0,n-1);
    printArray(A,n);
}