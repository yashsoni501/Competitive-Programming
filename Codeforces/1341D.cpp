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

ll n,k;
string s[3000];
vl pos[3000];
string key[10];
set<ll> st[3000];
ll lend[10];
ll lens[3000];
ll le(string a)
{
    ll c = 0;
    REP(i,7)
    {
        if(a[i]=='1')c++;
    }
    return c;
}

bool poss(string a, string b)
{
    bool p =  1;
    REP(i,7)
    {
        if(a[i]=='0' && b[i]=='1')  return 0;
    }
    return 1;
}

int main()
{
    IOS
    cin>>n>>k;
    key[0] = "1110111";
    key[1] = "0010010";
    key[2] = "1011101";
    key[3] = "1011011";
    key[4] = "0111010";
    key[5] = "1101011";
    key[6] = "1101111";
    key[7] = "1010010";
    key[8] = "1111111";
    key[9] = "1111011";

    REP(i,n)
    {
        cin>>s[i];
    }
    REP(i,n)
    {
        lens[i] = le(s[i]);
    }
    REP(i,10)
    {
        lend[i] = le(key[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        REP(j,10)
        {
            if(poss(key[j],s[i]))
            {
                pos[i].pb(j);
            }
        }
    }
    // REP(i,n)
    // {
    //     for(auto j:pos[i])
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"\n";
    for(auto i:pos[n-1])
    {
        st[n-1].in(lend[i]-lens[n-1]);
    }
    for(int i=n-2;i>=0;i--)
    {
        for(auto j:pos[i])
        {
            for(auto kt:st[i+1])
            {
                if(lend[j]-lens[i]+kt>2000)    break;
                st[i].in(lend[j]-lens[i]+kt);
            }
        }
    }
    // REP(i,n)
    // {
    //     for(auto s:st[i])
    //     {
    //         cout<<s<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"\n";
    if(st[0].find(k)==st[0].end())
    {
        cout<<-1<<endl;
        return 0;
    }
    string ans="";
    for(int i=0;i<n-1;i++)
    {
        for(int j=sz(pos[i])-1;j>=0;j--)
        {
            ll tmp = lend[pos[i][j]]-lens[i];
            // trace(i) trace(pos[i][j]) trace(tmp)
            if(st[i+1].find(k-tmp)!=st[i+1].end())
            {
                k-=tmp;
                ans += '0'+pos[i][j];
                // trace(ans)
                break;
            }
        }
    }
    // trace(k)
    for(int j=sz(pos[n-1])-1;j>=0;j--)
    {
        if(lend[pos[n-1][j]]-lens[n-1] == k)
        {
            k-=lend[pos[n-1][j]]-lens[n-1];
            ans+='0'+pos[n-1][j];
            break;
        }
    }
    cout<<ans<<endl;

}