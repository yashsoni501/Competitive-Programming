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

ll t;
string s;

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        ll h,w;
        h=w=0;
        cin>>s;
        ll minh,maxh,minw,maxw;
        maxh=maxw=0;
        minh=minw=0;
        REP(i,sz(s))
        {
            switch(s[i])
            {
                case 'W':
                    h++;
                    break;
                case 'S':
                    h--;
                    break;
                case 'D':
                    w++;
                    break;
                case 'A':
                    w--;
                    break;
            }
            maxh=max(maxh,h);
            maxw=max(maxw,w);
            minh=min(minh,h);
            minw=min(minw,w);
        }
        //trace(maxh) trace(minh) trace(maxw) trace(minw)
        ll minhc,minwc,maxhc,maxwc;
        minhc=maxhc=minwc=maxwc=0;
        h=w=0;

        string hor,ver;
        hor=ver="";
        REP(i,sz(s))
        {
            if(s[i]=='W' || s[i]=='S')
            {
                hor+=s[i];
            }
            else
            {
                ver=s[i];
            }
            
        }
        if(h==maxh) maxhc++;
        if(h==minh) minhc++;
        if(w==maxw) maxwc++;
        if(w==minw) minwc++;
        REP(i,sz(hor))
        {
            switch(hor[i])
            {
                case 'W':
                    h++;
                    break;
                case 'S':
                    h--;
                    break;

            }
            if(h==maxh) maxhc++;
            if(h==minh) minhc++;
        }
        REP(i,sz(ver))
        {
            switch(ver[i])
            {
                case 'D':
                    w++;
                    break;
                case 'A':
                    w--;
                    break;

            }
            if(w==maxw) maxwc++;
            if(w==minw) minwc++;
        }

        bool horm,verm;
        horm=verm=0;
        if((maxhc<2 && h!=minh) || (minhc<2 && h!=maxh))  horm=1;
        if((maxwc<2 && w!=minw) || (minwc<2 && w!=maxw))  verm=1;
        if(maxh-minh<2) horm=0;
        if(maxw-minw<2) verm=0;  
        //trace(maxhc)    trace(minhc)    trace(maxwc)    trace(minwc)    
        //trace(horm) trace(verm)
        if(!horm && !verm)  
        {
            cout<<(maxh-minh+1)*(maxw-minw+1)<<endl;
        }
        else if(horm && verm)
        {
            cout<<min((maxh-minh)*(maxw-minw+1),(maxh-minh+1)*(maxw-minw))<<endl;;
        }
        else if(horm)
        {
            cout<<(maxh-minh)*(maxw-minw+1)<<endl;
        }
        else
        {
            cout<<(maxh-minh+1)*(maxw-minw)<<endl;
        }
    }
}