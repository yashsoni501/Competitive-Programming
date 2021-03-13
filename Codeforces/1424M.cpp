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

ll n,k,p;
string pages[1005][1005];
string ar[1000005];
bool ch[27];
vector<char> vch;

char st[26][26];
bool boo=1;
void reperm(vector<char> &vt)
{
    // cout<<"vt: ";
    // REP(i,sz(vt))   cout<<vt[i];
    // cout<<endl;
    REP(i,sz(vt))
    {
        FOR(j,i+1,sz(vt),1)
        {
            if(st[vt[i]-'a'][vt[j]-'a'] == vt[j])
            boo=0;
            st[vt[i]-'a'][vt[j]-'a'] = vt[i];
            if(st[vt[j]-'a'][vt[i]-'a'] == vt[j])
            boo=0;
            st[vt[j]-'a'][vt[i]-'a'] = vt[i];
        }
    }
}

void solve(ll s, ll e, ll x)
{
    // trace(s)    trace(e) trace(x)
    if(s>=e)    return;
    vector<char> vt;
    unordered_set<char> vtt;
    FOR(i,s,e,1)
    {
        if(sz(ar[i])>x)
        {
            if(vtt.count(ar[i][x])==0)
            {
                vt.pb(ar[i][x]);
                vtt.in(ar[i][x]);
            }
        }
    }
    
    
    reperm(vt);
    ll st = s, en = s;
    FOR(i,s+1,e,1)
    {
        if(sz(ar[i])>x && sz(ar[i-1])>x && ar[i][x]==ar[i-1][x])
        {
            en++;
        }
        else
        {
            solve(st,en,x+1);
            st=en;
        }
    }
}

bool comp(char a, char b)
{
    if(st[a-'a'][b-'a'] == 'A')
    {
        return 1;
    }
    if(st[a-'a'][b-'a'] == a)
    {
        return 1;
    }
    return 0;
}

bool comp2(string a, string b)
{
    if(a==b)    return 0;
    ll ind=0;
    while(ind<sz(a) && ind<sz(b))
    {
        if(a[ind]==b[ind])  ind++;
        else
        {
            if(st[a[ind]-'a'][b[ind]-'a'] == a[ind])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    if(sz(b)>sz(a)) return 1;
    return 0;
}

int main()
{
    IOS
    cin>>n>>k;
    REP(i,n)
    {
        cin>>p;
        REP(j,k)
        {
            cin>>pages[p][j];
            REP(z,sz(pages[p][j]))
            {
                ch[pages[p][j][z]-'a']=1;
            }
        }
    }
    REP(i,n)
    {
        REP(j,k)
        {
            ar[i*k+j] = pages[i][j];
        }
    }

    REP(i,26)
    {
        if(ch[i])   {vch.pb(i+'a');     }
    }
    REP(i,26)
    {
        REP(j,26)
        {
            st[i][j] = 'A';
        }
    }
    solve(0,n*k,0);
    // REP(i,8)
    // {
    //     REP(j,8)
    //     {
    //         cout<<st[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    REP(i,sz(vch))
    {
        REP(j,sz(vch)-1)
        {
            if(st[vch[j]][vch[j+1]]==vch[j+1])
            {
                char tmp = vch[j+1];
                vch[j+1]=vch[j];
                vch[j]=tmp;
            }
        }
    }
    // if(!boo)
    // {
    //     cout<<"IMPOSSIBLE\n";
    //     return 0;
    // }
    // REP(i,sz(vch))
    // {
    //     FOR(j,i+1,sz(vch),1)
    //     {
    //         if(st[vch[i]-'a'][vch[j]-'a'] == vch[j])
    //         {
    //             cout<<"IMPOSSIBLE\n";
    //             return 0;
    //         }
    //     }
    // }

    REP(i,n*k-1)
    {
        if(comp2(ar[i+1],ar[i]))
        {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }

    REP(i,sz(vch))  cout<<vch[i];
    cout<<endl;

}