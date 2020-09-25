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
vector<ll> prefix_function(string s) {
    ll n = (int)s.length();
    vector<ll> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

ll t = 1;
int main()
{
    IOS
    // cin>>t;
    while(t--)
    {
        string s,t,l;
        cin>>s>>t;
        if(sz(s)<sz(t))
        {
            cout<<s<<endl;
            return 0;
        }
        l = t;
        ll c1 = count(all(s), '1');
        ll c0 = count(all(s), '0');
        vl pre = prefix_function(t);
        ll t1 = count(all(t), '1');
        ll t0 = count(all(t), '0');
        c1 -= t1;
        c0 -= t0;
        if(c1<0 || c0 < 0)
        {
            cout<<s<<endl;
            return 0;
        }
        ll n = sz(t);
        vl prefix1,prefix0;
        prefix0.pb(0);
        prefix1.pb(0);
        ll cnt0=0,cnt1=0;
        REP(i,n)
        {
            if(!i)  continue;
            if(s[i]=='0')
            {
                prefix0.pb(++cnt0);
                prefix1.pb(cnt1);
            }
            else
            {
                prefix1.pb(++cnt1);
                prefix0.pb(cnt0);
            }
        }
        ll ans=0,ind=-1;
        REP(i,n)
        {
            if(pre[i] == n-i)
            {
                ll tmp = min(c0/(prefix0[n]-prefix0[n-i]), c1/(prefix1[n]-prefix1[n-i]));
                if(tmp>ans)
                {
                    ans = tmp;
                    ind=i;
                }
            }
        }
        if(ans == 0)
        {
            ans = min(c0/max(0.0001,(double)t0), c1/max(0.0001,(double)t1));
            ind = 0;
        }
        REP(i,ans)
        {
            l+=t.substr(ind,n-ind);
        }
        cnt1 = count(all(s), '1');
        cnt0 = count(all(s), '0');
        ll cn1 = count(all(l),'1');
        ll cn0 = count(all(l),'0');
        REP(i,cnt1-cn1)
        {
            l+='1';
        }
        REP(i,cnt0-cn0)
        {
            l+='0';
        }
        cout<<l<<endl;
    }
}