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

ll t,n,k,a[100];
vector<ll> vt;

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        vt.clear();
        cin>>n>>k;
        REP(i,n)    cin>>a[i];
        sort(a,a+n);
        REP(i,n-1)
        {
            if(a[i]>k)
                vt.pb(a[i]);
        }
        // cout<<"jere\n";
        //cout<<sz(vt);
        if(sz(vt)==0)
        {
            ll sum=0;
            REP(i,n)
            {
                sum+=a[i];
            }
            cout<<sum<<endl;
            continue;
        }
        for(int i=0;i<sz(vt)-1;i++)
        {
            //cout<<"jerre\n";
            // trace(i)
            // REP(i,sz(vt))    cout<<vt[i]<<" ";
            // cout<<"\n";
            ll tmp = vt[i]-k;
            vt[i]=k;
            ll sm = 0,cnt=1;
            for(int j=sz(vt)-1;j>i;j--)
            {
                sm += vt[j];
                ll here = sm - vt[j-1]*cnt;
                // trace(here) trace(tmp) trace(j)
                if(here == tmp)
                {
                    for(int l=j;l<sz(vt);l++)
                    {
                        vt[l]=vt[j-1];
                        // cout<<"inside ";
                        // REP(iss,sz(vt)) cout<<vt[iss]<<" ";
                        // cout<<endl;
                    }
                    break;
                }
                else if(here>tmp)
                {
                    ll here1,sm1,cnt1;
                    sm1=sm-vt[j];
                    cnt1=cnt-1;
                    here1 = sm1-vt[j]*cnt1;
                    // trace(here1)    trace(j)  
                    ll left = tmp-here1;
                    // trace(left)
                    ll ttmp = vt[j]-(left/(sz(vt)-j));
                    for(int l=j;l<sz(vt);l++)
                    {
                        vt[l] = ttmp;
                    }
                    left -= (sz(vt)-j)*(left/(sz(vt)-j));
                    // cout<<"after left ";trace(left)
                    // REP(i,sz(vt))   cout<<vt[i]<<" ";
                    // cout<<endl;
                    for(int l=j;l<j+left;l++)
                    {
                        vt[l]--;
                    }
                    /*
                    ll tmp2 = vt[j];
                    ll left = tmp-(sm-cnt*tmp2);
                    for(int l=j;l<sz(vt);l++)
                    {
                        if(left)
                        {
                            left--;
                            vt[l] = tmp2-1;
                        }
                        else
                        {
                            vt[l] = tmp2;
                        }
                    }*/
                    break;
                }
                cnt++;
            }
        }
        ll sum = 0;
        REP(i,n)
        {
            if(a[i]<=k) sum+=a[i];
        }
        // REP(i,sz(vt))   cout<<vt[i]<<" ";
        // cout<<endl;
        sum+=sz(vt)*k;
        sum+=a[n-1]-vt[sz(vt)-1]+k;
        cout<<sum<<endl;
    }
}