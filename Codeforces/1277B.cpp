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

ll t,n,ar[300000];
int main()
{
    IOS
    map<ll,ll> st;
    cin>>t;
    while(t--)
    {
        st.clear();
        cin>>n;
        REP(i,n)
        {
            cin>>ar[i];
        }
        REP(i,n)
        {
            ll cnt=0;
            while(ar[i]%2==0)
            {
                cnt++;
                ar[i]/=2;
            }
            if(st.find(ar[i])==st.end())
            {
                st[ar[i]]=cnt;
            }
            else
                st[ar[i]]=max(st[ar[i]],cnt);
        }
        ll ans=0;
        for(map<ll,ll>::iterator it=st.begin();it!=st.end();it++)
        {
            // cout<<it->ff<<" "<<it->ss<<endl;
            ans+=it->ss;
        }        
        cout<<ans<<endl;
    }
}