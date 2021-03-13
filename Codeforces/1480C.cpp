#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

ll ar[200000];
int main()
{
    srand(time(0));
    ll n;
    cin>>n;
    ar[0] = 10000000;
    ar[n+1] = 10000000;
    REP(i,n)
    {
        ar[i+1] = -1;
    }
    ll turn = 96;
    set<ll> st;
    ll ind=0;
    st.in(0);
    cout<<"? 1"<<endl;
    cin>>ar[1];
    cout<<"? 2"<<endl;
    cin>>ar[2];
    cout<<"? "<<n<<endl;
    cin>>ar[n];
    cout<<"? "<<n-1<<endl;
    cin>>ar[n-1];

    st.in(1);
    st.in(2);
    st.in(n-1);
    st.in(n);
    while(turn && st.size()<n+1)
    {
        while(st.count(ind))
        {
            ind = rand()%(n);
            // trace(ind)
        }
        st.insert(ind);
        REP(i,3)
        {
            if(ind+i<=n && ar[ind+i]==-1 && turn>0)
            {
                cout<<"? "<<ind+i<<endl;
                cin>>ar[ind+i];
                // ar[ind+i] = n-ind-i;
                turn--;
            }
        }
        if(ar[ind]>ar[ind+1] && ar[ind+1]<ar[ind+2])
        {
            cout<<"! "<<ind+1<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(ar[i] != -1 && ar[i] < ar[i-1] && ar[i] < ar[i+1])
        {
            cout<<"! "<<i<<endl;
            return 0;
        }
    }
    while(st.count(ind))
        ind = rand()%(n)+1;
    cout<<"! "<<ind<<endl;
}