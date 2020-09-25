#include<bits/stdc++.h>
#include <stdio.h> 
#include <stdlib.h> 
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

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    res = (res*res) % MOD;
    if (b % 2)
        return (res * (a%MOD))%MOD;
    else
        return res%MOD;
}

ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}

ll lp[200000];
ll t,n,ar[200000];
vector<ll> pr;

ll gcdar(vl arr)
{
    if(sz(arr)==1)  return arr[0];
    ll gc = __gcd(arr[0],arr[1]);
    REP(i,sz(arr))  gc = __gcd(gc,arr[i]);
    return gc;
}

int main()
{
    //IOS
    srand(time(0));
    for (int i=2; i<=100000; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=100000; ++j)
        lp[i * pr[j]] = pr[j];
    }
    ll prcnt[sz(pr)][20];
    //cin>>t;
    while(1)
    {
        REP(i,20)
        {
            REP(j,sz(pr))
            {
                prcnt[j][i]=0;
            }
        }
        //cin>>n;
        n=15;
        //REP(i,n)    cin>>ar[i];
        //cout<<"here"<<endl;
        REP(i,n)    ar[i] = rand()%100000+1;
        //cout<<"here "<<endl;
        REP(i,n)    cout<<ar[i]<<" ";
        cout<<endl;
        REP(i,n)
        {
            if(ar[i]==1)   continue;
            ll tmp=ar[i];
            ll prev=lp[tmp],cnt=0;
            while(tmp>1)
            {
                if(prev!=lp[tmp])
                {
                    prcnt[lower_bound(all(pr),prev)-pr.begin()][cnt]++;
                    cnt=0;
                    prev=lp[tmp];
                }
                tmp/=prev;
                cnt++;
            }
            prcnt[lower_bound(all(pr),prev)-pr.begin()][cnt]++;
        }
        ll prod=1;
        REP(i,sz(pr))
        {
            ll sum = 0;
            REP(j,20)   sum+=prcnt[i][j];
            REP(j,20)
            {
                if(prcnt[i][j]>0)
                {
                    cout<<"prime "<<pr[i]<<endl;
                    cout<<"power "<<j<<endl;
                    cout<<"no "<<prcnt[i][j]<<endl;
                    cout<<endl;
                }
            }
            if(sum>0)
            {
                // trace(pr[i]) trace(sum)
            }  
            else 
                continue;
            REP(j,20)
            {
                if(prcnt[i][j]==0)  continue;
                sum-=prcnt[i][j];
                //trace(sum)  trace(j)
                ll possi = mul(sub(binpow(2,prcnt[i][j]),1),binpow(2,sum));
                //trace(possi)
                prod = mul(prod,binpow(binpow(pr[i],j),possi));
                //trace(prod)
            }
        }
        cout<<"sol "<<prod<<endl;
        ll p2 = prod;
            prod=1;
        REP(i,binpow(2,n)-1)
        {
            vl arr;
            ll tmp=i+1;
            REP(j,n)
            {
                if((tmp)%2==1) arr.pb(ar[j]);
                tmp/=2;
            }
            //trace(gcdar(arr));
            prod = (prod*gcdar(arr))%MOD;
            //trace(prod)
        }
        if(p2!=prod)break;
        cout<<"brf "<<prod<<endl;
        // trace(prod)
    }    
}