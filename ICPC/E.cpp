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
#define MOD 998244353
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



ll t,n,k,r,c,ar[1005][1005],ar2[1005][1005],tmp[1005][1005];
void multiply(ll mat1[][1005],  
              ll mat2[][1005],  
              ll res[][1005],ll N) 
{ 
    ll i, j, k; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < N; k++) 
                res[i][j] = (res[i][j]+(mat1[i][k] *mat2[k][j])%MOD)%MOD; 
        } 
    } 
} 

void power(ll x[][1005], ll y)
{
    REP(i,n)
            REP(j,n)
                ar2[i][j]=0;
    ar2[0][0]=1;
    while (y > 0)
    {
        if (y & 1)
        {
            multiply(ar2,x,tmp,n);
            REP(i,n)
            {
                REP(j,n)
                {
                    ar2[i][j] = tmp[i][j];
                }
            }
            y--;
            continue;
        }
        y=y/2;
        multiply(ar2,ar2,tmp,n);
        REP(i,n)
            {
                REP(j,n)
                {
                    ar2[i][j] = tmp[i][j];
                }
            }
    }
  // return res% MOD;
}
ll power2(ll x, ll y)
{
   x = x% MOD;
    ll res = 1;
   while (y > 0)
   {
       if (y & 1)
           res = (res*x)% MOD;
       y = y/2;
       x = (x*x) % MOD;
   }
   return res% MOD;
}
ll anscal(ll p, ll q){
    ll ainv = power2(q,MOD-2);
    ll ans = p*ainv%MOD;
    return ans;
}

int main()
{
    IOS
    cin>>t;
        
    while(t--)
    {
        // REP(i,n)
        //     REP(j,n)
        //         ar2[i][j]=0;
        // ar2[0][0]=1;
        cin>>n>>k>>r>>c;
        REP(i,n)
            REP(j,n)
                ar[i][j]=0;
        //cout<<ar[0][0]<<endl;
        REP(i,n)
        {
            ar[i][0] = ar[0][i] = 1;
        }
        ar[0][0] = add(sub(mul(n,n),n),1);
        power(ar,k);
        ll xx = power2(n,2*k);
        cout<<ar2[0][0]<<endl;
        cout<<xx<<endl;
        cout<<anscal(ar[0][0],xx)<<endl;
    }
}