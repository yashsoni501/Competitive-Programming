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

struct block
{
    ll ca1, ca2;
    ll cb1, cb2;
    bool toggled;
};

block blk[400];
bool ar[1000000];
ll sqt;

void updateBlk(ll i)
{
    ll st = sqt*i;
    ll en = st+sqt;
    ll ca1=1,ca2=0;
    ll cb2=1,cb1=0;

    FOR(j,st,en,1)
    {
        if(ar[j])
        {
            cb2 = add(cb2,ca2);
            cb1 = add(cb1,ca1);
        }
        else
        {
            ca2 = add(cb2,ca2);
            ca1 = add(cb1,ca1);
        }
    }
    blk[i].ca1 = ca1;
    blk[i].cb1 = cb1;
    blk[i].ca2 = ca2;
    blk[i].cb2 = cb2;
}

void preprocess(ll n, string s)
{
    sqt = sqrt(n)+1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A')
        {
            ar[i] = 0;
        }
        else
        {
            ar[i] = 1;
        }
    }
    REP(i,sqt)
    {
        blk[i].toggled = 0;
        ll st = sqt*i;
        ll en = st+sqt;
        ll ca1=1,ca2=0;
        ll cb2=1,cb1=0;

        FOR(j,st,en,1)
        {
            if(ar[j])
            {
                cb2 = add(cb2,ca2);
                cb1 = add(cb1,ca1);
            }
            else
            {
                ca2 = add(cb2,ca2);
                ca1 = add(cb1,ca1);
            }
        }
        blk[i].ca1 = ca1;
        blk[i].cb1 = cb1;
        blk[i].ca2 = ca2;
        blk[i].cb2 = cb2;
    }
}

void update(ll l, ll r)
{
    if(l>r)
    {
        return;
    }
    if(l%sqt==0)
    {
        if(l+sqt<=r)
        {
            blk[l/sqt].toggled ^= 1;
            update(l+sqt,r);
        }
        else
        {
            FOR(i,l,r+1,1)
            {
                ar[i] ^= 1;
            }
            updateBlk(l/sqt);
        }
    }
    else
    {
        while(l%sqt && l<=r)
        {
            ar[l] ^= 1;
            l++;
        }
        updateBlk(l/sqt-1);
        update(l,r);
    }
}

pll query(ll l, ll r, ll a, ll b)
{
    ll ansA=a;
    ll ansB=b;
    ll blkid = l/sqt;
    if(l%sqt==0)
    {
        if(l+sqt<=r)
        {
            if(blk[blkid].toggled == 0)
            {
                ll tmp = add(mul(ansA, blk[blkid].ca1), mul(ansB, blk[blkid].ca2));
                ansB = add(mul(ansA, blk[blkid].cb1), mul(ansB, blk[blkid].cb2));
                ansA = tmp;
            }
            else
            {
                ll tmp = add(mul(ansA, blk[blkid].cb1), mul(ansB, blk[blkid].cb2));
                ansB = add(mul(ansA, blk[blkid].ca1), mul(ansB, blk[blkid].ca2));
                ansA = tmp;
            }
            return query(l+sqt, r, ansA, ansB);
        }
        else
        {
            FOR(i,l,r+1,1)
            {
                if(blk[blkid].toggled == 0)
                {
                    if(ar[i] == 0)
                    {
                        ansA = add(ansA, ansB);
                    }
                    else
                    {
                        ansB = add(ansA, ansB);
                    }
                }
                else
                {
                    if(ar[i] == 1)
                    {
                        ansA = add(ansA, ansB);
                    }
                    else
                    {
                        ansB = add(ansA, ansB);
                    }
                }
            }
            return {ansA, ansB};
        }
    }
    else
    {
        while(l%sqt && l<=r)
        {
            if(blk[blkid].toggled == 0)
            {
                if(ar[l] == 0)
                {
                    ansA = add(ansA, ansB);
                }
                else
                {
                    ansB = add(ansA, ansB);
                }
            }
            else
            {
                if(ar[l] == 1)
                {
                    ansA = add(ansA, ansB);
                }
                else
                {
                    ansB = add(ansA, ansB);
                }
            }
            l++;
        }
        if(l>r)
        {
            return {ansA, ansB};
        }
        else
        {
            return query(l, r, ansA, ansB);
        }
    }
}

int main()
{
    // IOS
    ll n,q;
    cin>>n>>q;
    string s;
    ll t, l, r, a, b;
    cin>>s;
    preprocess(n, s);
    trace(sqt)
    REP(i,sqt)
    {
        cout<<blk[i].ca1<<" "<<blk[i].cb1<<" "<<blk[i].ca2<<" "<<blk[i].cb2<<endl;
        cout<<blk[i].toggled<<endl;
    }
    REP(i,q)
    {
        cin>>t;
        if(t==1)
        {
            cin>>l>>r;
            update(l-1,r-1);
        }
        else
        {
            cin>>l>>r>>a>>b;
            pll ans = query(l-1,r-1,a,b);
            cout<<"ans "<<ans.ff<<" "<<ans.ss<<endl;
        }
        cout<<"ar: ";
        REP(i,n)
        {
            cout<<(ar[i]^blk[i/sqt].toggled);
            cout<<" ";
        }
        cout<<endl;
    }
}