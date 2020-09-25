#include<bits/stdc++.h>
using namespace std;
 
#define ll int
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

ll k,n;
string s,t,a,b;
vpll stp;
ll cnt[26];
bool bo;
int ind,ind2;
char tmp,tmp2;
int main()
{
    IOS
    cin>>k;
    while(k--)
    {
        cin>>n;
        stp.clear();
        cin>>s>>t;
        REP(i,26)    cnt[i]=0;
        REP(i,n)
        {
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']++;
        }
        bo=1;
        REP(i,n)
        {
            if(cnt[i]%2)    bo=0;
        }
        if(!bo)
        {
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\n";

        ind=0;
        while(ind<n)
        {
            if(s[ind]==t[ind])
            {
                ind++;
                continue;
            }
            tmp=s[ind];
            ind2=-1;
            for(int i=ind+1;i<n;i++)
            {
                if(s[i]==tmp)
                {
                    ind2=i;
                    break;
                }
            }
            if(ind2==-1)
            {
                for(int i=ind+1;i<n;i++)
                {
                    if(t[i]==tmp)

                    {
                        ind2=i;
                        break;
                    }
                }
                stp.pb(mp(ind+2,ind2+1));
                // cout<<ind+2<<" "<<ind2+1<<endl;
                tmp2 = s[ind+1];
                s[ind+1] = t[ind2];
                t[ind2]=tmp2;

                stp.pb(mp(ind+2,ind+1));
                // cout<<ind+2<<" "<<ind+1<<endl;
                tmp2 = s[ind+1];
                s[ind+1] = t[ind];
                t[ind]=tmp2;
            }
            else
            {
                stp.pb(mp(ind2+1,ind+1));
                // cout<<ind2+1<<" "<<ind+1<<endl;
                tmp2 = s[ind2];
                s[ind2] = t[ind];
                t[ind]=tmp2;
                
            }
            
            // cout<<"pr "<<s<<" "<<t<<endl;
            

        }

        cout<<sz(stp)<<endl;
        REP(i,sz(stp))  cout<<stp[i].ff<<" "<<stp[i].ss<<endl;    
    }    
}