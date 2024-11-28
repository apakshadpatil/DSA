#include<iostream>
using namespace std;

int main()
{
    int a[2][2],b[2][2],c[2][2],sum=0;
    //taking input for values of matrix A
    cout<<"Enter values for matrix A:\n";
    for (int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>a[i][j];
        }
        cout<<"\n";
    }
    //taking input for values of matrix B
    cout<<"Enter values for matrix B:\n";
    for (int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>b[i][j];
        }
        cout<<"\n";
    }
    //multiplying matrix a and b
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            sum=0;
            for(int k=0;k<2;k++)
            {
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }
    //printing matrix c
    cout<<"The resultant matrix C is:\n";
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<c[i][j]<<"\t";
        }
        cout<<"\n";
    }
}