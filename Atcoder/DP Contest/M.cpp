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

ll n,k;
ll ar[200];
ll postf[200];
ll cnt=0;
ll arr[100005][102];
ll pre[100005][102];

// ll initializedp(ll i,ll ke)
// {
//     if(arr[i][ke]!=-1)   return arr[i][ke];
//     cnt++;
//     if(i==n)
//     {
//         arr[i][ke]=1;
//         return 1;
//     }
//     ll sum=0;
//     for(int j=ar[i];j>=0;j--)
//     {
//         if(ke-j<=postf[i+1])
//         {
//             sum = (sum+solve(i+1,k-j))%MOD;
//         }
//         else
//         {
//             break;
//         }
//     }
//     // trace(i)
//     // trace(ke)
//     // trace(sum)
//     arr[i][ke] = sum;
//     return sum;
// }

int main()
{
    IOS
    cin>>n>>k;
    REP(i,n)
    {
        REP(j,k+1)
        {
            arr[i][j] = -1;
        }
    }
    ll sum=0;
    REP(i,n)
    {
        cin>>ar[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        sum = add(sum,ar[i]);
        postf[i]=sum;
    }
    if(k>postf[0])
    {
        cout<<0<<endl;
        return 0;
    }   
    
    FOR(i,0,k+1,1)
    {
        if(i<=ar[n-1])
        {
            // cout<<"here\n";
            arr[i][n-1] = 1;
        }
        else
        {
            arr[i][n-1] = 0;
        }
    }
    sum=arr[0][n-1];
    pre[0][n-1]=arr[0][n-1];

    FOR(i,1,k+1,1)
    {
        sum = (sum+arr[i][n-1])%MOD;
        pre[i][n-1] = sum;
    }
    for(int i=n-2;i>=0;i--)
    {   
        ll sum=0;
        for(int j=0;j<=k;j++)
        {
            if(j>ar[i])
                arr[j][i] = sub(pre[j][i+1], pre[j-ar[i]-1][i+1]);
            else
            {
                arr[j][i] = pre[j][i+1];
            }
            
            sum = add(sum,arr[j][i]);
            pre[j][i]=sum;
        }
    }
    /*
    REP(i,k+1)
    {
        REP(j,n)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    REP(i,k+1)
    {
        REP(j,n)
        {
            cout<<pre[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    */
    cout<<arr[k][0]<<endl;
    
}
