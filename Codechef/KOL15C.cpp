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

#define int long long
map<int, int> updates[100000 + 5];
int val[100000 + 5];
int n;
long long read_int(){
	char r;
	bool start=false,neg=false;
	long long ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}

signed main()
{
   IOS int u;
   n=read_int();
   u=read_int();
   int k=sqrt(n);
   while (u--)
   {
       int a, b;
       a=read_int();
       b=read_int();
       b--;
       if(a==0) val[a]++;
       else if(a>k)
       {
           while(b<n)
            val[b]++,b+=a;
       }
       else
       {
       updates[b][a]++;
        
       }
       

   }
   REP(i, n)
   for (auto u : updates[i])
   {
       val[i] += u.second;
       if(i+u.first < 100000 + 5)
           updates[i + u.first][u.first] += u.second;
   }
   REP(i, n)
   printf("%lld ",val[i]);
}