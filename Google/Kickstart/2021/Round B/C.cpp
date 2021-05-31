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

vl p2;
vl primes;
ll t;

 
const int MAXPR = (int)2e9;
void calcPrimes() {
    auto sum = 2LL;
    int cnt = 1;
 
    const ll S = round(sqrt(MAXPR));
    vector<char> sieve(S + 1, true);
    vector<array<ll, 2>> cp;
    for (ll i = 3; i < S; i += 2) {
        if (!sieve[i])
            continue;
        cp.push_back({i, (i * i - 1) / 2});
        for (ll j = i * i; j <= S; j += 2 * i)
            sieve[j] = false;
    }
    vector<char> block(S);
    ll high = (MAXPR - 1) / 2;
    for (ll low = 0; low <= high; low += S) {
        fill(block.begin(), block.end(), true);
        for (auto &i : cp) {
            ll p = i[0], idx = i[1];
            for (; idx < S; idx += p)
                block[idx] = false;
            i[1] = idx - S;
        }
        if (low == 0)
            block[0] = false;
        for (ll i = 0; i < S && low + i <= high; i++)
            if (block[i])
                primes.pb((low + i) * 2ll + 1);
    };
}

int main()
{
    IOS
    primes.pb(2);
    calcPrimes();
    // cout<<sz(primes);
    FOR(i,0,sz(primes)-1,1)
    {
        p2.pb(primes[i]*primes[i+1]);
    }
    // cout<<p2[sz(p2)-1]<<endl;
    // REP(i,10)   cout<<primes[i]<<" ";
    // return 0;
    cin>>t;
    ll z;
    REP(te,t)
    {
        cin>>z;
        ll ind = upper_bound(all(p2), z)-p2.begin()-1;
        cout<<"Case #"<<te+1<<": "<<p2[ind]<<endl;
    }
}