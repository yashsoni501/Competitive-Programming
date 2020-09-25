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

string s,t;

bool check(string str1,string str2,int m,int n) 
{ 
    // Base Cases 
    if (m == 0) return true; 
    if (n == 0) return false; 
  
    // If last characters of two strings are matching 
    if (str1[m-1] == str2[n-1]) 
        return check(str1, str2, m-1, n-1); 
  
    // If last characters are not matching 
    return check(str1, str2, m, n-1); 
} 

int main()
{
    IOS
    cin>>s>>t;
    ll maxi=0;
    ll n=sz(s);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            string x = s.substr(0,i)+s.substr(j,n-j);
            //cout<<x<<endl;
            if(check(t,x,sz(t),sz(x)))
            {
                maxi=max(maxi,sz(s)-sz(x));
            }            
        }
    }
    cout<<maxi<<endl;
}