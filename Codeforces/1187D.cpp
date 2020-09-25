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
bool pos;
ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}
ll t,n,a[1000000],b[1000000],index[1000000];
 
struct node
{
    ll ind,data;
};
 
node ar[1000000],ac[1000000];
bool used[1000000];
 
bool comp1(node x, node y)
{
    if(x.data!=y.data)
        return x.data<y.data;
    else
        return x.ind<y.ind;
}
 
ll bs(ll fnd)
{
    ll h=n-1;
    ll l=0;
    ll mid=(h+l)/2;
    while(h-l>0)
    {
        //cout<<"mid fnd "<<mid<<" "<<fnd<<endl;
        if(ac[mid].data<fnd || (ac[mid].data==fnd && used[ac[mid].ind]))
        {
            l=mid+1;
            //cout<<"l = "<<l<<endl;
        }
        else
        {
            h=mid;
            //cout<<"h = "<<h<<endl;
        }
        mid=(h+l)/2;
    }
    if(ac[mid].data!=fnd)   return -1;
    return ac[mid].ind;
}
 
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        ll till=0;
        priority_queue<ll,vector<ll>, greater<ll> > pq;
    
        pos=1;
        cin>>n;
        REP(i,n)
        {
            cin>>a[i];
            used[i]=0;
        }
        REP(i,n)    cin>>b[i];
        REP(i,n)
        {
            ac[i].data=a[i];
            ac[i].ind=i;
        }
        sort(ac,ac+n,comp1);

        REP(i,n)
        {
            ll tmp=bs(b[i]);
            if(tmp==-1)  
            {
                pos=0;
                break;
            }
            used[tmp]=1;
            index[i]=tmp;
        }
        
        if(!pos)
        {
            cout<<"NO"<<endl;
            continue;
        }
        
        ll sizee=0;
        while(till<n)
        {
            for(;sizee<=index[till];sizee++)    pq.push(a[sizee]);
            if(pq.top()!=b[till])
            {
                pos=0;
                break;
            }
            pq.pop();
            till++;
        }

        if(pos) cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
}