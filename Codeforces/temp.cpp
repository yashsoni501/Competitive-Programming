#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void add_matrix(int add[][3], int a[][3], int b[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            add[i][j] = a[i][j] + b[i][j]; 
        }
    }
}
void mul_matrix(int mul[][3], int a[][3], int b[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            mul[i][j] = 0;
            for(int k=0;k<3;k++)
            {
                mul[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

int main()
{
    int a[3][3], b[3][3], add[3][3], mul[3][3];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>b[i][j];
        }
    }

    add_matrix(add, a, b);
    cout<<"Sum: "<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<add[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    mul_matrix(mul, a, b);
    cout<<"Multiplication:\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<mul[i][j]<<" ";
        }
        cout<<endl;
    }    
}