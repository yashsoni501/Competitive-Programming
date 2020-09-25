#include<bits/stdc++.h>
#include<tuple>
using namespace std;

typedef long long int ll;

ll a[200005];
vector< pair <ll,ll> > c(200005);
ll fre[200005]={};
ll szcost=0;
ll m,n,k;

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        fre[x]=max(fre[x],y);
    }
    for(int i=1;i<=n;i++)
    {
        if(fre[i])
        {
            c.push_back(make_pair(i,fre[i]));
        }
    }
    //sort(c.begin(),c.end());
    for(vector<pair<ll,ll> > ::iterator i=c.begin();i!=c.end();i++)
    {
        cout<<(*i).first<<" "<<(*i).second<<endl;
    }

}
