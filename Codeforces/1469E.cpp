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
string s;
ll pow2[1000004];
bool match(string &s, string &ans, ll ind, ll k)
{
    REP(i,k)
    {
        if(ans[i]==s[ind+i])
        {
            return 1;
        }
    }

    return 0;
}
void update(string &ans, ll &cnt1, ll &sum)
{
    for(int i=sz(ans)-1;i>=0;i--)
    {
        if(ans[i]=='0')
        {
            ans[i] = '1';
            cnt1++;
            sum = add(sum,pow2[i]);
            break;
        }
        else
        {
            ans[i] = '0';
            cnt1--;
            sum = sub(sum,pow2[i]);
        }
    }
}
bool boom(string &st)
{
    REP(i,sz(st))
    {
        if(st[i]=='0')
        return 0;
    }
    return 1;
}

unordered_map<ll, vector<ll>> hashtable;

int main()
{
    IOS
    cin>>t;
    pow2[0]=1;
    REP(i,1000001)
    {
        pow2[i+1] = mul(2,pow2[i]);
    }
    while(t--)
    {
        hashtable.clear();
        cin>>n>>k;
        string s;
        cin>>s;
        for(auto &ch:s) ch = (ch=='0')?'1':'0';
        ll sum = 0;
        ll p2 = 1;
        REP(i,k)
        {
            sum = mul(sum,2ll);
            if(s[i] == '1')
            {
                sum = add(sum,1ll);
            }
            p2 = mul(p2,2ll);
        }
        hashtable[sum].pb(0);
        REP(i,n-k+1)
        {
            if(!i)  continue;
            if(s[i-1]=='1')
            {
                sum = sub(sum,pow2[k-1]);
            }
            sum = mul(sum,2);
            if(s[i+k-1]=='1')
            {
                sum = add(sum,1ll);
            }
            hashtable[sum].pb(i);
        }
        string ans = "";
        REP(i,k)
        {
            ans+='0';
        }
        sum=0;
        bool boo=0;
        ll cnt1=0;
        while(!boo)
        {
            if(hashtable.count(sum)==0)
            {
                boo=1;
                break;
            }
            else
            {
                bool bt=1;
                for(auto it:hashtable[sum])
                {
                    if(match(s,ans,it,k))
                    {
                        bt=0;
                        break;
                    }
                }
                if(bt)
                {
                    boo=1;
                    break;
                }
            }
            if(cnt1==k)
            {
                break;
            }
            update(ans, cnt1, sum);
        }
        if(!boo)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
            cout<<ans<<endl;
        }
    }
}