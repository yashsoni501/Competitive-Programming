#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define MOD 1000000007
#define endl "\n"
#define sz(a) (int)((a).size())
#define all(x) (x).begin(), (x).end()
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define prv(a) for(auto x : a) cout << x << ' ';cout << '\n';
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define OTP(s) cout<<s<<endl;
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
inline ll add(ll a, ll b){a += b; if(a >= MOD)a -= MOD; return a;}
inline ll sub(ll a, ll b){a -= b; if(a < 0)a += MOD; return a;}
inline ll mul(ll a, ll b){return (ll)((ll) a * b %MOD);}
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}

ll t;
ll n, ar[300005];
ll df[300005];
int main()
{
    IOS
    cin>>t;
    REP(te,t)
    {
        cin>>n;
        REP(i,n )   cin>>ar[i];
        REP(i,n-1)  df[i] = ar[i+1]-ar[i];
        if(n==2)    {
            cout<< "Case #"<<te+1<<": "<<2<<endl;
            continue;
        }
        if(n==3)
        {
            if(ar[0]%2 == ar[2]%2)
            {
                cout<<"Case #"<<te+1<<": "<<3<<endl;
            }
            else
            {
                cout<<"Case #"<<te+1<<": "<<2<<endl;
            }
            continue;
        }
        ll ans=2;
        REP(i,n-1)
        {
            ll dif = ar[i+1]-ar[i];
            ll j = i;
            while(j<n-1 && dif == ar[j+1]-ar[j])
            {
                j++;
            }
            if(j>=n-2)  {ans = max(ans,n-1+1-i); break;}
            ll k=j;
            if(ar[j+2]-ar[j]==2*dif)
            {
                j+=2;
            }
            while(j<n-1 && dif == ar[j+1]-ar[j])
            {
                j++;
            }
            ans = max(ans, j+1-i);
            if(k-i>10)   i=k-3;
        }
        REP(i,n-2)
        {
            ll j=i;
            ll dif;
            if((ar[i+2]-ar[i])%2==0)
            {
                dif = (ar[i+2]-ar[i])/2;
                if(ar[i+1]-ar[i]==dif)  continue;
            }
            else
            {
                continue;
            }
            j=i+2;
            while(j<n-1 && dif == ar[j+1]-ar[j])
            {
                j++;
            }
            ans = max(ans, j+1-i);
            if(j-i>10)   i=j-3;
        }
        REP(i,n-2)
        {
            ll dif =  ar[i+2]-ar[i+1];
            if(ar[i+1]-ar[i]==dif)  continue;
            ll j=i+2;
            while(j<n-1 && dif == ar[j+1]-ar[j])
            {
                j++;
            }
            ans = max(ans, j+1-i);
            if(j-i>10)   i=j-3;
        }
        cout<<"Case #"<<te+1<<": "<<ans<<endl;
    }
}