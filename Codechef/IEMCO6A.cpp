#include<iostream>
using namespace std;

typedef long long int ll;
ll t,n,k,m,kl,ml,a[1000005];

int main()
{
    cin>>t;
    while(t--)
    {
        kl=0;
        ml=0;
        cin>>n>>k>>m;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==k)
                kl++;
            if(a[i]==m)
                ml++;
        }
        for(int i=0;i<kl;i++)
            cout<<k<<" ";
        for(int i=0;i<n;i++)
            if(a[i]!=k&&a[i]!=m)
                cout<<a[i]<<" ";
        for(int i=0;i<ml;i++)
            cout<<m<<" ";
        cout<<endl;
    }
}
