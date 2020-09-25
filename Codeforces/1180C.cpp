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

struct node
{
    ll x;
    node *next;
};
node *a=NULL,*lst=NULL;
vector<ll> b;
vector<pair<ll,ll> > pr;

void t2()
{
    b.pb(a->next->x);
    a->next=a->next->next;
}

void push(ll t)
{
	//cout<<"in push"<<endl;
    node *tmp=new node;
    tmp->x=t;
    tmp->next=NULL;
    if(!a)
    {
        a=tmp;
        lst=tmp;
    }
    else
    {
        lst->next=tmp;
        lst=lst->next;
    }
}
void operate()
{
    if(a->x < a->next->x)
    {
        pr.pb(make_pair(a->x,a->next->x));
        b.pb(a->x);
        node* tmp=a;
        a=a->next;
        lst->next=tmp;
        tmp->next=NULL;
        lst=lst->next;
    }
    else
    {
        pr.pb(make_pair(a->x,a->next->x));
        b.pb(a->next->x);
        node *tmp=a->next;
        a->next=a->next->next;
        tmp->next=NULL;
        lst->next=tmp;
        lst=lst->next;
    }
}

ll n,m;
int main()
{
    IOS
    cin>>n>>m;
    ll ma=-1e9,ind=-1;
    REP(i,n)
    {
        ll tmp;
        cin>>tmp;
        if(tmp>ma)
        {
            ma=tmp;
            ind=i;
        }
        push(tmp);
    }
    
    REP(i,ind)
    {
        //trace(A)
        operate();
    }
    
    for(int i=ind+1;i<n;i++)
    {
        t2();
    }
    /*REP(i,n-1)  cout<<b[i]<<" ";
    cout<<endl;
    cout<<ind<<endl; 
    REP(i,ind)  cout<<pr[i].ff<<" "<<pr[i].ss<<endl;*/

    ll x;
    REP(i,m)
    {
        cin>>x;
        x--;
        if(x<ind)
        {
            cout<<pr[x].ff<<" "<<pr[x].ss<<endl;
        }
        else
        {
            cout<<ma<<" "<<b[(x)%(n-1)]<<endl;
        }
    }
}