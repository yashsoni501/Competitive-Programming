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

struct streets
{
    ll b,e,l;
    string name;
};

struct path
{
    ll p;
    vector<string> str;
};
ll cov(string s)
{
    ll id=0;
    REP(i,sz(s))
    {
        id= 10*id;
        id+=s[i]-'a';
    }
    return id;
}

string conv(ll it)
{
    if(it==0)
        return "a";
    string s="";
    while(it)
    {
        s+=it%10+'a';
        it/=10;
    }
    reverse(all(s));
    return s;
}
ll dd,ii,ss,vv,ff;
streets street[100003];
path car[1003];
map<ll,vector<string> > inp;
map<ll,vector<string> > otp;
map<string,ll > begotp[600];
map<ll,ll> center;
map<string,ll> cost;
map<ll,ll> sc;
// bool comp(pair<ll,string)
int main()
{
    // IOS
    srand(time(0));
    cin>>dd>>ii>>ss>>vv>>ff;
    REP(i,ss)
    {
        cin>>street[i].b>>street[i].e;
        cin>>street[i].name>>street[i].l;
        otp[street[i].b].pb(street[i].name);
        inp[street[i].e].pb(street[i].name);
        cost[street[i].name] = street[i].l;
    }

    ll cnt=0;
    REP(i,vv)
    {
        cin>>car[i].p;
        car[i].str.resize(car[i].p);
        ll ct=0;
        REP(j,car[i].p)
        {
            cin>>car[i].str[j];
            ct+=cost[car[i].str[j]];
            if(j != 0 && car[i].str[j].substr(0,3) == "ejj"){
                center[cov(car[i].str[j-1].substr(0,sz(car[i].str[j-1])-4))]++;
                if(sc.count(cov(car[i].str[j-1].substr(0,sz(car[i].str[j-1])-4))))
                {
                    sc[cov(car[i].str[j-1].substr(0,sz(car[i].str[j-1])-4))] = min(sc[cov(car[i].str[j-1].substr(0,sz(car[i].str[j-1])-4))],ct);
                }
                else
                {
                    sc[cov(car[i].str[j-1].substr(0,sz(car[i].str[j-1])-4))]=ct;
                }
                
            }
        }
        if(car[i].str[0].substr(0,3) == "ejj")
        {
            cnt++;
            begotp[cov(car[i].str[0].substr(4,sz(car[i].str[0])-4))][car[i].str[0]]++;;
        }
    }
    // cout<<sz(center)<<endl;
    // for(auto it:center)
    // {
    //     cout<<it.ff<<" "<<it.ss<<endl;
    // }
    cout<<500<<endl;
    for(auto it:inp)
    {
        if(it.ff != 499)
        {
            cout<<it.ff<<endl;
            cout<<sz(it.ss)<<endl;
            REP(i,sz(it.ss))
            {
                cout<<it.ss[i]<<" ";
                if(it.ss[i][0]=='e')
                {
                    cout<<"1\n";
                }
                else
                {
                    cout<<3<<endl;
                }
            }
        }
    }
    cout<<499<<endl;
    // REP(i,499)
    // {
    //     if(center.count(i)==1 && center[i]==1)
    //     {
    //         center.erase(i);
    //     }
    // }
    vpll pp;
    for(auto it:center)
    {
        if(sc[it.ff] < 200 && ( it.ss > 1 || rand()%2))
        pp.pb({it.ss,it.ff});
    }
    sort(all(pp),greater<pair<ll,ll>>());
    for(auto it:center)
    {
        if(sc[it.ff] >= 200)
        {
            pp.pb({it.ss,it.ff});
        }
    }
    cout<<sz(pp)<<endl;
    for(auto it:pp)
    {
        cout<<conv(it.ss)+'-'+conv(499)<<" ";
        if(it.ff>3)
        {
            cout<<2<<endl;
        }
        else
            cout<<1<<endl;
    }
}