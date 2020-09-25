#include<bits/stdc++.h>
using namespace std;

#define ll int
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
#define prv(a) for(auto x : a) cout << x.ff << ' ' <<x.ss<<endl; cout << '\n';
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

vpll::iterator searche(vpll::iterator a, vpll::iterator b, pair<ll,ll> searche_this)
{
    vpll::iterator linear_count_x;
    
    for(linear_count_x=a;linear_count_x!=b;linear_count_x++)
    {
        if(*(linear_count_x)==searche_this)  return linear_count_x;
    }
    return b;
}

ll t,R,C;
vpll u,d,r,l;
ll cnt,meet;
set<pair<ll,ll> > aeat;
void change()
{
    REP(i,sz(u))
    {
        u[i].ff--;
        if(u[i].ff<0 || aeat.find(u[i])!=aeat.end())
        {
            u.erase(u.begin()+i);
            i--;
            cnt--;
        }
    }
    REP(i,sz(d))
    {
        d[i].ff++;
        if(d[i].ff>=R || aeat.find(d[i])!=aeat.end())
        {
            d.erase(d.begin()+i);
            i--;
            cnt--;
        }
    }
    REP(i,sz(r))
    {
        r[i].ss++;
        if(r[i].ss>=C || aeat.find(r[i])!=aeat.end())
        {
            r.erase(r.begin()+i);
            i--;
            cnt--;
        }
    }
    REP(i,sz(l))
    {
        l[i].ss--;
        if(l[i].ss<0 || aeat.find(l[i])!=aeat.end())
        {
            l.erase(l.begin()+i);

            i--;
            cnt--;
        }
    }
}

int main()
{
    IOS
    cin>>t;
    
    while(t--)
    {
        aeat.clear();
        cnt=0;
        meet=0;
        cin>>R>>C;
        REP(i,R)
        {
            REP(j,C)
            {
                char ch;
                cin>>ch;
                if(ch=='#') aeat.insert(mp(i,j));
                else if(ch=='U')
                {
                    u.pb(mp(i,j));
                    cnt++;
                }
                else if(ch=='D')    d.pb(mp(i,j)),cnt++;
                else if(ch=='R')    r.pb(mp(i,j)),cnt++;
                else if(ch=='L')    l.pb(mp(i,j)),cnt++;
            }
        }
        while(cnt>0)
        {
            change();
            map<pll, ll> m;
            //trace(cnt);
            REP(i,sz(u))
            {
                m[u[i]]++;
            }
            REP(i,sz(d))
            {
                m[d[i]]++;
            }
            REP(i,sz(r))
            {
                m[r[i]]++;
            }
            REP(i,sz(l))
            {
                m[l[i]]++;
            }
                //cout<<"printing all indices"<<endl;
            for(map<pll,ll>::iterator i= m.begin();i!=m.end();i++)
            {
                //cout<<i->ff.ff<<" "<<i->ff.ss<<endl;
                ll tmp = i->ss;
                //if(tmp>1)
                  //  cout<<i->ff.ff<<" "<<i->ff.ss<<endl;
                meet+=tmp*(tmp-1)/2;
            }
            m.clear();
            //trace(cnt);
        }
        //trace(meet);
        cout<<meet<<endl;
    }
}