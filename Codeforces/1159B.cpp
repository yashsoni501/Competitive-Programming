#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n,armin[300005];
ll armax[300005];

struct node
{
    ll data,ind;
};
node a[300002];

bool comp(node a,node b)
{
    return a.data<b.data;
}

int main()
{
    IOS
    cin>>n;
    REP(i,n)
    {
        cin>>a[i].data;
        a[i].ind=i;
    }
    sort(a,a+n,comp);
    ll k=1e9;
    ll maxi=-1;
    ll mini=1e9;
    
    for(int i=n-1;i>=0;i--)
    {
        mini=min(mini,a[i].ind);
        maxi=max(maxi,a[i].ind);
        armax[i]=maxi;
        armin[i]=mini;
    }

    REP(i,n-1)
    {
        ll tmp=max(abs(a[i].ind-armax[i]),abs(a[i].ind-armin[i]));
        k=min(k,a[i].data/tmp);
    }
    cout<<k<<endl;
}