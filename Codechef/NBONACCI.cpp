#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,q;
    cin>>n>>q;
    ll arr[n+1],ar[n+1];
    ll t=0,tmp;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        t^=arr[i];
    }
    arr[n]=t;
    int s[n+1];
    t=0;
    for(int i=0;i<=n;i++)
    {
        t^=arr[i];
        ar[i]=t;
    }
    while(q--)
    {
        cin>>t;
        cout<<ar[(t-1)%(n+1)]<<endl;
    }
}
