#include<iostream>
using namespace std;

typedef long long int ll;

int main()
{
    ll t,n,m;
    cin>>t;
    ll temp[4][4]={1,1,3,3,
                   2,4,4,2,
                   3,3,1,1,
                   4,2,2,4};
    while(t--)
    {
        cin>>n>>m;
        int arr[n][m];
        if(n*m==1)
        {
            cout<<1<<endl<<1<<endl;
        }
        else if(n*m==2)
        {
            cout<<1<<endl;
            if(n>m)
            {
                cout<<1<<endl<<1<<endl;
            }
            else
            {
                cout<<"1 1"<<endl;
            }
        }
        else if(n==1)
        {
            cout<<2<<endl;
            for(int i=0;i<m;i++)
            {
                cout<<(i/2)%2+1<<" ";
            }
            cout<<endl;
        }
        else if(m==1)
        {
            cout<<2<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<(i/2)%2+1<<endl;
            }
        }
        else if(n==2&&m==2)
        {
            cout<<2<<endl;
            cout<<"1 1"<<endl;
            cout<<"2 2"<<endl;
        }
        else if(n==2&&m!=2)
        {
            cout<<3<<endl;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout<<j%3+1<<" ";
                }
                cout<<endl;
            }
        }
        else if(n!=2&&m==2)
        {
            cout<<3<<endl;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout<<i%3+1<<" ";
                }
                cout<<endl;
            }
        }
        else
        {
            cout<<4<<endl;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout<<temp[i%4][j%4]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
