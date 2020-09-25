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
#define endl "\n"
#define sz(a) (int)((a).size())
#define all(x) (x).begin(), (x).end()
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define prv(a) for(auto x : a) cout << x << ' ';cout << '\n';
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
ll n,m;

int main()
{
    IOS
    cin>>n>>m;

    ll a[2]={1,1},b[2]={n,m};
    for(int i=0;i<n*m;i++)
    {
        if(i%2==0)
        {
            cout<<a[0]<<" "<<a[1]<<endl;
            if(a[1]==m)
            {
                a[0]++;
                a[1]=1;
            }
            else
            {
                a[1]++;
            }
        }
        else
        {
            cout<<b[0]<<" "<<b[1]<<endl;
            if(b[1]==1)
            {
                b[1]=m;
                b[0]--;
            }
            else
            {
                b[1]--;
            }
        }
    }
}
