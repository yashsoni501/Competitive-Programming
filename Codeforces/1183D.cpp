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

struct node
{
    ll ff,ss;
};

bool comp(node a,node b)
{
    if(a.ff!=b.ff)
    {
        return a.ff<b.ff;
    }
    return a.ss<b.ss;
}


ll q,n;
map<ll,pair<ll,ll> > mt;
vector<node> vc,vc2;
int main()
{
    IOS
    cin>>q;
    while(q--)
    {
        mt.clear();
        vc.clear();
        vc2.clear();
        cin>>n;
        REP(i,n)
        {
            ll a,b;
            cin>>a>>b;
            mt[a].ff++;
            if(b)
                mt[a].ss++;
        }
        
        for(map<ll,pair<ll,ll> >::iterator it=mt.begin();it!=mt.end();it++)
        {
            node tmp;
            tmp.ff = it->ss.ff;
            tmp.ss = it->ss.ss;
            vc.pb(tmp);
        }
        sort(all(vc),comp);
        //refining
        ll cnt2=vc[sz(vc)-1].ff;
        ll ind2=sz(vc)-2;
        vc2.pb(vc[ind2+1]);
        while(cnt2>0 && ind2>=0)
        {
            if(vc[ind2].ss==-1)
			{
				ind2--;
				continue;
			}
            cnt2=min(vc[ind2].ff,cnt2-1);
            ll tmp=ind2,tmp2=ind2;
            while(vc[tmp].ff>=cnt2 && tmp>=0)
            {
                if(vc[tmp2].ff==vc[ind2].ff)  tmp2--;
                tmp--;
            }
            ll useind=ind2,mile=vc[ind2].ss;
            for(int i=ind2;i>tmp;i--)
            {
                if(mile<vc[i].ss)
                {
                    mile=vc[i].ss;
                    useind=i;
                }
            }
            vc2.pb(vc[useind]);
            vc[useind].ss=-1;
            ind2=tmp2;
        }
        sort(all(vc2),comp);

        REP(i,sz(vc2))
            cout<<"pr "<<vc2[i].ff<<" "<<vc2[i].ss<<endl;
        ll cnt=1e9,ind=sz(vc2)-1;
        ll ans=0;
        ll ans2=0;
        while(cnt>0 && ind>=0)
        {
            cnt=min(vc2[ind].ff,cnt-1);
            ans+=cnt;
            ans2+=min(cnt,vc2[ind].ss);
            ind--;
        }
        cout<<ans<<" "<<ans2<<endl;
        
    }
}
