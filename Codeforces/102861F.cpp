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

void output(int sc[], int masc[],bool ser)
{
    string ans = to_string(masc[0])+" ";
    if(masc[0]>=2 || masc[1]>=2)
    {
        if(masc[0]>=2)
        {
            ans+="(winner) - ";
        }
        else
        {
            ans+=" - ";
        }
        ans+=to_string(masc[1]);
        if(masc[1]>=2)
        {
            ans+=" (winner)";
        }
    }
    else
    {
        ans+="("+to_string(sc[0])+((!ser)?"*":"")+") - "+to_string(masc[1])+" ("+to_string(sc[1])+(ser?"*":"")+")";
    }
    cout<<ans<<endl;
}

int main()
{
    IOS
    string s;
    cin>>s;
    bool ser = 0;
    int score[2]={};
    int mascore[2]={};
    REP(i,sz(s))
    {
        if(s[i]=='S')
        {
            score[ser]++;
        }
        else if(s[i]=='R')
        {
            ser = !ser;
            score[ser]++;
        }
        else
        {
            output(score, mascore,ser);
        }
        if(score[0]==10 || score[0]-score[1]>1 && score[0]>=5)
        {
            mascore[0]++;
            score[0]=score[1]=0;
        }
        else if(score[1]==10 || score[1]-score[0]>1 && score[1]>=5)
        {
            mascore[1]++;
            score[0]=score[1]=0;
        }
    }
}