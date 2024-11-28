#include<iostream>
using namespace std;

int main()
{
    int r,c;
    cout<<"Enter the number of rows of matrix:";
    cin>>r;
    cout<<"\nEnter the number of columns of matrix:";
    cin>>c;
    int a[r][c],transpose[r][c];
    cout<<"Enter the elements of the matrix:\n";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
        cout<<"\n";
    }
    //transposing the matrix
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            transpose[i][j]=a[j][i];
        }
    }
    //printing the transpose matrix
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<transpose[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}