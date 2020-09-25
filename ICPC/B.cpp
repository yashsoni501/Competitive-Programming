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

ll t,n,k;
map<string,int> m0,m1;
string s;
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        ll cnt=0;
        m0.clear();
        m1.clear();
        cin>>n;
        REP(i,n)
        {
            cin>>s>>k;
            if(k==0)
                m0[s]++;
            else
            {
                m1[s]++;
            }
        }
        for(auto itr=m1.begin();itr!=m1.end();itr++)
        {
            //cout<<"jer\n";
            if(m0.find(itr->ff)!=m0.end() && m0[itr->ff]>itr->ss)
                continue;
            cnt+=itr->ss;
        }
        for(auto itr=m0.begin();itr!=m0.end();itr++)
        {
            if(m1.find(itr->ff)!=m1.end() && m1[itr->ff]>=itr->ss)
                continue;
            cnt+=itr->ss;
        }
        cout<<cnt<<endl;
    }   
}