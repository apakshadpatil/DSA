#include<iostream>
using namespace std;

void merge(int A[],int mid,int low, int high)
{
    int i,j,k,B[high-low+1];
    i=low;
    j=mid+1;
    k=low;
    while (i<=mid && j<=high)
    {
        if(A[i]<A[j])
        {
            B[k]=A[i];
            i++;
            k++;
        }
        else{
            B[k]=A[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        B[k]=A[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        B[k]=A[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++)
    {
        A[i]=B[i];
    }
}
void mergeSort(int A[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,mid,low,high); 
    }
}
void printArray(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
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
    
    //mergeSort();
    printArray(A,n);
    mergeSort(A,0,n-1);
    printArray(A,n);
    return 0;
}