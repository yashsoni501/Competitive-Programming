#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define d(x) cerr<<#x<<" "<<x<<endl;
#define f(n) for(ll i=0; i<n; i++)
 
typedef long long int ll;
ll M=1000000007;
void show(vector<ll> v)
{
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n";
}
void showarr(ll arr[],ll n)
{
    for(ll i=0; i<n; i++)
        cout<<arr[i];
    cout<<"\n";
}
int main()
{
    //IOS
    ll T = 1;
    cin>>T;
    while(T--)
    {
        ll n,a;   cin>>n;
        ll arr[10001];
        memset(arr,0,sizeof(arr));
        f(4*n)
        {
            cin>>a;
            arr[a]++;
        }
        vector<pair<ll,ll> > v;
        for(ll i=1; i<=10000; i++)
        {
            if(arr[i] == 0)
                continue;
            else
                v.pb(mp(i,arr[i]));
        }
        ll area = v[0].ff*v[v.size()-1].ff;
        ll ctr = 0;
        for(ll i=0; i<v.size()/2 ; i++)
        {
            ll j = v.size()-1-i;
            if(v[i].ff * v[j].ff != area or v[i].ss != v[j].ss)
            {
                ctr++;
                cout<<"NO\n";
                break;
            }
        }
        if(!ctr)
            cout<<"YES\n";
 
    }
    return 0;
}