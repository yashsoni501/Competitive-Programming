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

map<ll,ll> ma;
map<ll,ll>::iterator it,st,en;

void pro()
{
    it=ma.begin();
    st=it;
    it=ma.end();
    it--;
    en=it;
}

int main()
{
    IOS
    ll t,n;
    cin>>t;
    while(t--)
    {
        ma.clear();
        cin>>n;
        REP(i,4*n)
        {
            ll tmp;
            cin>>tmp;
            ma[tmp]++;
        }
        pro();
        ll area = st->ff*en->ff;
        
        bool b=1;
        while(!ma.empty() && b)
        {
            pro();
            //trace(st->ff)   trace(st->ss)   trace(en->ff)   trace(en->ss)
            if(st->ff*en->ff!=area || st->ss<2 || en->ss<2)
            {
                b=0;
                break;
            }
            st->ss-=2;
            en->ss-=2;
            bool x=1;
            if(st->ss==0)
            {
                if(st==en)
                    x=0;
                ma.erase(st);
            }
            else if(st->ss<2)    b=0;
            if(x && en->ss==0)    ma.erase(en);
            else if(x && en->ss<2)    b=0;
        }
        if(b)
            cout<<"YES\n";
        else    cout<<"NO\n";
    }
}