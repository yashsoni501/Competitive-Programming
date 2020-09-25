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

set<ll> st;

string convertToBinary(ll k,ll l)
{
    string s(l,'0');
    ll ind=l-1;
    while(k)
    {
        if(k%2)
            s[ind]='1';
        ind--;
        k/=2;
    }
    return s;
}

int main()
{
    IOS
    st.in(1000000000);
    ll n;
    cin>>n;
    ll cnt=0;
    REP(i,10)
    {
        REP(j,10)
        {
            REP(l,10)
            {
                REP(k,pow(2,l))
                {
                    string s=convertToBinary(k,l);
                    ll num=0;
                    REP(x,sz(s))
                    {
                        num*=10;
                        if(s[x]=='0')
                        {
                            num+=i;
                        }
                        else
                        {
                            num+=j;
                        }
                    }
                    st.in(num);
                }
            }
        }
    }

    for(set<ll>::iterator it=st.begin();it!=st.end();it++)
    {
        if(*it<=n)  cnt++;
    }
    cout<<cnt-1<<endl;
}