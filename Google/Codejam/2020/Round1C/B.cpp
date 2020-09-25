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

ll t,u;
pair<ll,string> ar[20000];
set<char> ch;
set<char> ch2;
map<char,set<int>> ma;
map<int, set<char>> ans;
map<int,vector<char>> ans2;
map<char,int> vc;

bool chk = 1;
bool comp(pair<ll,string> a, pair<ll,string> b)
{
    return a.ff<b.ff;
}

ll gen(vl prm, string sr)
{
    ll num=0;
    for(auto i:sr)
    {
        num = 10*num+prm[vc[i]];
    }
    return num;
}

void check(vl prm)
{
    REP(i,10000)
    {
        ll num = gen(prm,ar[i].ss);
        if(num>ar[i].ff)
        {
            return;
        }
    }
    chk=0;
}

int main()
{
    // IOS
    cin>>t;
    REP(te,t)
    {
        ma.clear();
        ch.clear();
        ans.clear();
        ans2.clear();
        vc.clear();
        chk = 1;
        string s = "";
        char z;
        cin>>u;
        
        REP(i,10000)
        {
            cin>>ar[i].ff>>ar[i].ss;
            ch2.insert(ar[i].ss[0]);
            for(auto j:ar[i].ss)
            {
                ch.insert(j);
            }
        }
        for(auto i:ch)
        {
            if(ch2.find(i)==ch2.end())
            {
                z = i;
                break;
            }
        }
        
        vc[z] = 0;
        ll ind=1;
        for(auto i:ch2)
        {
            vc[i] = ind++;
        }
        vl prm;
        for(int i=0;i<=9;i++)
        {
            prm.pb(i);
        }
        check(prm);
        while(chk)
        {
            next_permutation(prm.begin()+1,prm.end());
            check(prm);
        }
        s = "          ";
        for(auto i:vc)
        {
            s[prm[i.ss]] = i.ff;
        }
        cout<<"Case #"<<te+1<<": "<<s<<endl;
    }    
}