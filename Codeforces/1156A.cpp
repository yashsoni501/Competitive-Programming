#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n,a[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll sum=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]+a[i+1]==5)
        {
            cout<<"Infinite"<<endl;
            return 0;
        }
        if(a[i]==1 && a[i+1]==2)
            sum+=3;
        if(a[i]==1 && a[i+1]==3)
            sum+=4;
        if(a[i]==2 && a[i+1]==1)
            sum+=3;
        if(a[i]==2 && a[i+1]==3)
            sum+=4;
        if(a[i]==3 && a[i+1]==1)
            sum+=4;

        if(i && a[i]==1 && a[i-1]==3 && a[i+1]==2)
            sum-=1;
    }
    cout<<"Finite"<<endl;
    cout<<sum<<endl;
}
