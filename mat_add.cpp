#include<iostream>
using namespace std;

int main()
{
    int rows,columns;
    cout<<"Enter the number of rows:";
    cin>>rows;
    cout<<"\nEnter the number of columns:";
    cin>>columns;
    int a[rows][columns],b[rows][columns],c[rows][columns];
    //taking input for values of matrix A
    cout<<"Enter values for matrix A:\n";
    for (int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cin>>a[i][j];
        }
        cout<<"\n";
    }
    //taking input for values of matrix B
    cout<<"Enter values for matrix B:\n";
    for (int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cin>>b[i][j];
        }
        cout<<"\n";
    }
    //adding a and b
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    //printing resultant matrix 
    cout<<"\nThe resultant matrix of addition of A and B is :\n";
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout<<c[i][j]<<"\t";
        }
        cout<<"\n";
    }
}