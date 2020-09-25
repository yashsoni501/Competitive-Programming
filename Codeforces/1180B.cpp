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
#define sz(a) (int)((a).size())
#define all(x) (x).begin(), (x).end()
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define prv(a) for(auto x : a) cout << x << ' ';cout << '\n';
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define OTP(s) cout<<s<<endl;
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)


ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}

ll n;
ll a[1000000];
int main()
{
    IOS
    cin>>n;
    ll pd=1;
    ll mi=1e9,ind=-1;
    REP(i,n)
    {
        ll t;
        cin>>t;
        if(t>=0)
        {
            t=-t-1;
        }
        if(t<mi)
        {
            mi=t;
            ind=i;
        }
        pd*=t;
        a[i] =t;
    }
    //sort(a,a+n);
    if(n%2)
    {
        a[ind]=-a[ind]-1;
    }
    //sort(a,a+n);
    REP(i,n)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

}