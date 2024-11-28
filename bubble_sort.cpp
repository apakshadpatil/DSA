#include<iostream>
using namespace std;

void BubbleSort(int array[],int size)
{

}

int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int array[n];
    cout<<"Enter values for array:\n";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    BubbleSort(array,n);
}