#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define OTP(s) cout<<s<<endl;
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n,t,m;
bool visited[1000000];

ll linear_count(bool *a, bool *b, ll find_this)
{
    bool *linear_count_x;
    ll linear_count_cnt=0;
    for(linear_count_x=a;linear_count_x!=b;linear_count_x++)
    {
        if(*linear_count_x==find_this)  linear_count_cnt++;
    }
    return linear_count_cnt;
}


int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<ll> adj[n];
        REP(i,m)
        {
            ll x,y;
            cin>>x>>y;
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }
        //cout<<"input taken"<<endl;
        vector<ll> pts;
        REP(i,n)    visited[i]=0;
        queue<ll> st;
        bool dst[n]={};
        st.push(0);
        visited[0]=1;
        while(!st.empty())
        {
            ll x=st.front();
            st.pop();
            REP(i,(ll)adj[x].size())
            {
                if(visited[adj[x][i]])  continue;
                visited[adj[x][i]]=1;
                st.push(adj[x][i]);
                dst[adj[x][i]]=(dst[x]+1)%2;
            }
        }
        if(linear_count(dst,dst+n,1)<=n/2)
        {
            REP(i,n)
            {
                if(dst[i])
                    pts.push_back(i);
            }
        }
        else
        {
            REP(i,n)
            {
                if(!dst[i])
                    pts.push_back(i);
            }
        }
        //REP(i,n)    cout<<visited[i]<<" ";
        //cout<<endl;
        cout<<pts.size()<<endl;
        REP(i,(ll)pts.size())   cout<<pts[i]+1<<" ";
        cout<<endl;
    }
}