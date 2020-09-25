#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n,m,t;
ll a[1000000]={};
ll b[1000000]={};
ll vis[1000000]={};
ll ans[1000000]={};

ll root(ll j)
{
    if(a[j]!=j)
    {
        ll tmp = root(a[j]);
        a[j]=tmp;
        return tmp;
    }
    return j;
}

void connect(ll x,ll y)
{
    a[root(x)]=root(y);
}

void print()
{
    REP(i,n)
    {
        cout<<a[i+1]<<" ";
    }
    cout<<endl;
}

int main()
{
    IOS
    cin>>n>>m;
    REP(i,n)
    {
        a[i+1]=i+1;
    }
    //print();
    REP(i,m)
    {
        cin>>t;
        REP(j,t)
        {
            cin>>b[j];
        }
        REP(j,t-1)
        {
            connect(b[j],b[j+1]);
        }
        //print();
    }
/*
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(i);
        }
    }
*/
    for(int i=1;i<=n;i++)
    {
        vis[root(i)]++;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<vis[root(i)]<<" ";
    }
    cout<<endl;
    
}