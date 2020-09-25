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

ll d,k;
string s;
ll dp[150][10050];

ll adderer(ll ind,ll rem)
{
    ll ans = 0;
    ll fst = s[ind]-'0';
    // trace(fst)

    if(ind==k-1)
    {
        REP(i,fst+1)
        {
            if(i%d==rem)
                ans = add(ans,1);
        }
        return ans;
    }

    REP(j,fst)
    {
        // if(ind==0 && j==0)    continue;
        ans = add(ans,dp[(rem-j+10*d)%d][k-ind-2]);
        // trace((rem-j+10*d)%d)
        // trace(k-ind-2)
        // trace(ans)
    }
    
    ans = add(ans,adderer(ind+1,(rem-fst+10*d)%d));
    return ans;
}

int main()
{
    IOS
    cin>>s;
    cin>>d;
    k = sz(s);

    REP(i,d)
    {
        dp[i][0]=0;
    }
    REP(i,10)
    {
        dp[i%d][0] = add(dp[i%d][0],1);
    }
    REP(j,k+1)
    {
        REP(i,d)
        {
            if(j==0)
            {
                continue;
            }
            else
            {
                ll sum=0;
                REP(x,10)
                {
                    sum = add(sum,dp[(i-x+10*d)%d][j-1]);
                }
                dp[i][j] = sum;
            }
        }
    }

    ll ans = MOD-1;  
    
    ans = add(ans,adderer(0,0));
    cout<<ans<<endl;
}