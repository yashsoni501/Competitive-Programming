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
// #define endl "\n"
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

ll t,n;
bool b[200];
bool f00 = 0, f01 = 0;
ll i00 = 1, i01 = 1;
char c;
int cnt = 0;
bool rev = 0;
bool comp = 0;

void prt(ll ind)
{
    cout<<ind<<endl;
}

void updatevars()
{
    // cout<<"updating"<<endl;
    bool tmp1,tmp2;
    prt(i00);
    cin>>tmp1;
    prt(i01);
    cin>>tmp2;
    
    if(f00)
    {
        if(tmp1==b[i00] && comp)
        {
            comp = 0;
        }
        else if(tmp1!=b[i00] && !comp)
        {
            comp = 1;
        }
    }
    if(f01)
    {
        if(!comp)
        {
            if(b[i01]==tmp2 && rev)  rev = 0;
            else if(b[i01]!=tmp2 && !rev)    rev=1;
        }
        else
        {
            if(b[i01]==tmp2 && !rev)  rev = 1;
            else if(b[i01]!=tmp2 && rev)    rev=0;
        }
    }
    // cout<<"updated"<<endl;
}

void update(ll ind, bool val)
{
    if(rev) ind = n-ind+1;
    if(comp)    val = !val;
    b[ind] = val;
}

void updatef(ll ind)
{
    if(b[ind]==b[n-ind+1])
    {
        f00=1;
        i00=ind;
    }
    else
    {
        f01=1;
        i01=ind;
    }
}

void printar()
{
    if(!rev)
    {
        for(int i=1;i<=n;i++)
        {
            if(comp)   
            {
                if(b[i])    cout<<0;
                else        cout<<1;
            }
            else        cout<<b[i];
        }
        cout<<endl;
    }
    else
    {
        for(int i=n;i>0;i--)
        {
            if(comp)    
            {
                if(b[i])    cout<<0;
                else        cout<<1;
            }
            else        cout<<b[i];
        }
        cout<<endl;
    }
}

int main()
{
    // IOS
    cin>>t>>n;
    // return n;
    while(t--)
    {
        // cin>>n;
        f00 = 0, f01 = 0;
        i00 = n, i01 = n;
        rev = 0;
        comp = 0;
        if(n<=10)
        {
            REP(i,n)
            {
                cout<<i+1<<endl;
                cin>>b[i];
            }
            REP(i,n)
            {
                cout<<b[i];
            }
            cout<<endl;
            cin>>c;
            if(c=='Y')
            {
                continue;
            }
            else
            {
                return 0;
            }
        }

        REP(i,5)
        {
            cout<<i+1<<endl;
            cin>>b[i+1];
        }
        REP(i,5)
        {
            cout<<n-i<<endl;
            cin>>b[n-i];
        }
        REP(i,5)
        {
            if(b[i+1]==b[n-i])
            {
                f00 = 1;
                i00 = i+1;
            }
            else
            {
                f01 = 1;
                i01 = i+1;
            }
        }
        cnt = 10;
        int upd = 10;
        int ind = n-4;
        while(1)
        {
            if(upd==n)  break;
            if(cnt%10==0)
            {
                updatevars();
                cnt+=2;
            }
            if(ind>n/2)     ind = n-ind+2;
            else            ind = n-ind+1;
            prt(ind);
            bool tmp;
            cin>>tmp;
            update(ind,tmp);
            cnt++;
            upd++;

            if(upd%2==0)
            {
                updatef(ind);
            }
        }
        printar();
        cin>>c;
        if(c!='Y')  return 10;  
    }
}