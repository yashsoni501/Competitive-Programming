#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
#define MOD 1000000007
#define pb push_back
typedef long long int ll;
ll n;

struct node
{
    set<ll> link;
};

node ar[100010];
bool stat[100010];
ll cnt=0;
void join(ll x,ll y)
{
    ar[x].link.insert(y);
    ar[y].link.insert(x);
}

void break_bond(ll x,ll y)
{
	cnt++;
    ar[x].link.erase(y);
    ar[y].link.erase(x);
}

int main()
{
    IOS
    cin>>n;
    if(n==1)
    {
    	cout<<1<<endl;
    	return 0;
	}
    REP(i,n)	stat[i]=1;
    REP(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        join(x,y);
    }
    set<ll> qu;
    for(ll i=1;i<=n;i++)
    {
        if(ar[i].link.size()==1)
        {
            qu.insert(i);
        }
    }
    ll ans=-1;
    while(!qu.empty() && ans==-1)
    {
        set<ll> qu2;
        set<ll>::iterator xy;
        /*cout<<"qu.size "<<qu.size()<<endl;
        REP(i,qu.size())	cout<<qu[i]<<" ";
        cout<<endl;*/
        for(xy=qu.begin();xy!=qu.end();xy++)
        {
        	node* it=&ar[*xy];
        	if(it->link.empty())	continue;
        	set<ll>::iterator itr=it->link.begin();
            qu2.insert(*itr);
            //break_bond(qu[i],*itr);
            stat[*xy]=0;
        }
        for(xy=qu.begin();xy!=qu.end();xy++)
        {
        	node* it=&ar[*xy];
        	if(it->link.empty())	continue;
        	set<ll>::iterator itr=it->link.begin();
            break_bond(*xy,*itr);
		}
        qu.clear();
        
        for(xy=qu2.begin();xy!=qu2.end();xy++)
        {
            if(ar[*xy].link.size()==0 && stat[*xy])
            {
                ans=*xy;
                break;
            }
            else if(ar[*xy].link.size()==1)
            {
                qu.insert(*xy);
            }
        }
        qu2.clear();
        //cout<<"cnt "<<cnt<<endl;
    }
    cout<<ans<<endl;
    //cout<<cnt<<endl;
}
