#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n,ar[1000000];

void swap(ll i,ll j)
{
    ll tmp=ar[i];
    ar[i]=ar[j];
    ar[j]=tmp;
}
int main()
{
    IOS
    cin>>n;
    FOR(i,1,n+1,1)
    {
        cin>>ar[i];
    }    
    ll ind=1;
    vector<pair <ll, ll> > vp;
    ll cnt=0;
    while(ind<n &&cnt<5*n)
    {
        cnt++;
        if(ar[ind]==ind)
        {
            ind++;
            continue;
        }
        
        if(ind<=n/2)
        {
            if(2*(ar[ind]-ind)>=n)
            {
                //cout<<ind<<" here"<<endl;
                vp.push_back(make_pair(ind,ar[ind]));
                swap(ind,ar[ind]);
                continue;
            }
            vp.push_back(make_pair(ind,n));
            swap(ind,n);

            if(2*(n-ar[n])>=n)
            {
                vp.push_back(make_pair(n,ar[n]));
                swap(n,ar[n]);
            }
            else
            {
                vp.push_back(make_pair(1,n));
                swap(1,n);
                vp.push_back(make_pair(1,ar[1]));
                swap(1,ar[1]);
                vp.push_back(make_pair(1,n));
                swap(1,n);
            }
        }
        else
        {
            vp.push_back(make_pair(ind,1));
            vp.push_back(make_pair(1,ar[ind]));
            vp.push_back(make_pair(ind,1));
            ll tmp=ar[ind];
            ar[ind]=ar[tmp];
            ar[tmp]=tmp;
        }
    }
    
    cout<<vp.size()<<endl;
    ll sz=vp.size();
    REP(i,sz)
    {
        cout<<vp[i].first<<" "<<vp[i].second<<endl;
    }
}