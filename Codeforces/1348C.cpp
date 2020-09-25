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
ll n,k;
map<char,ll> ma;
string s,ar[200000];
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        ma.clear();
        cin>>n>>k;
        cin>>s;
        sort(all(s));
        ll ind=0;
        if(k==1)
        {
            cout<<s<<endl;
            continue;
        }
        if(n==k)
        {
            cout<<s[n-1]<<endl;
            continue;
        }
        if(count(all(s),s[0]) == sz(s))
        {
            REP(i,(sz(s)+k-1)/k)
            {
                cout<<s[0];
            }
            cout<<endl;
            continue;
        }
        REP(i,k)
        {
            ar[i] = s[ind++];
        }
        if(ar[k-1] != ar[0])
        {
            cout<<max(ar[0],ar[k-1])<<endl;
            continue;
        }
        FOR(i,ind,n,1)
        {
            ma[s[i]]++;
        }
        string st = ar[0];
        if(sz(ma)==1)
        {
            for(int i=0;i<(ma[s[ind]]+k-1)/k;i++)
            {
                st+=s[ind];
            }
        }
        else
        {
            st+=s.substr(ind,n-ind);
        }
        cout<<st<<endl;
        
        
    }
}