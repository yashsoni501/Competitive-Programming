#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long int ll;
ll a[500][500],b[500][500];
ll c[500],d[500];

bool compare(ll a[],ll b[],int sz)
{
    //  cout<<"sz "<<sz<<endl;
    for(int i=0;i<sz;i++)
    {
        if(a[i]!=b[i])
            return 1;
    }
    return 0;
}

void print(ll a[],ll b[],int sz)
{
    for(int i=0;i<sz;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<sz;i++)
        cout<<b[i]<<" ";
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    if(n<m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>b[i][j];
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>a[j][i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>b[j][i];
        }
    }

    int tmp=n;
    n=m;
    m=tmp;
    for(int i=0;i<n;i++)
    {
        int ind=0;
        while(ind<=i)
        {
            c[ind]=a[ind][i-ind];
            d[ind]=b[ind][i-ind];
            ind++;
        }
        sort(c,c+ind);
        sort(d,d+ind);
        if(compare(c,d,ind))
        {
            cout<<"NO"<<endl;
            //print(c,d,ind);
            return 0;
        }
    }
    for(int i=n;i<m;i++)
    {
        int ind=0;
        while(ind<n)
        {
            c[ind]=a[ind][i-ind];
            d[ind]=b[ind][i-ind];
            ind++;
        }
        sort(c,c+ind);
        sort(d,d+ind);
        if(compare(c,d,ind))
        {
            cout<<"NO"<<endl;
            //print(c,d,ind);
            return 0;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        int ind=0;
        while(ind<=i)
        {
            c[ind]=a[n-i-1+ind][m-ind-1];
            d[ind]=b[n-i-1+ind][m-ind-1];
            ind++;
        }
        sort(c,c+ind);
        sort(d,d+ind);
        if(compare(c,d,ind))
        {
            cout<<"NO"<<endl;
            //print(c,d,ind);
            return 0;
        }
    }
    cout<<"YES"<<endl;
}
