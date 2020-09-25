#include<bits/stdc++.h>
using namespace std;

#define ll long long
//#define int ll
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
int V;
ll graph[60][60];
ll minDistance(ll dist[], bool sptSet[]) 
{ 
   // Initialize min value 
   ll min = INT_MAX, min_index; 
   
   for (ll v = 1; v <= V; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
} 
int printSolution(ll dist[]) 
{ 
   printf("Vertex   Distance from Source\n"); 
   for (int i = 1; i <= V; i++) 
      printf("%d tt %d\n", i, dist[i]); 
} 
void dijkstra(ll src,ll dist[]) 
{ 
     //int dist[V];     // The output array.  dist[i] will hold the shortest 
                      // distance from src to i 
   
     bool sptSet[V+1]; // sptSet[i] will be true if vertex i is included in shortest 
                     // path tree or shortest distance from src to i is finalized 
   
     // Initialize all distances as INFINITE and stpSet[] as false 
     for (int i = 1; i <= V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
   
     // Distance of source vertex from itself is always 0 
     dist[src] = 0; 
   
     // Find shortest path for all vertices 
     for (int count = 0; count < V-1; count++) 
     { 
       // Pick the minimum distance vertex from the set of vertices not 
       // yet processed. u is always equal to src in the first iteration. 
       ll u = minDistance(dist, sptSet); 
   
       // Mark the picked vertex as processed 
       sptSet[u] = true; 
   
       // Update dist value of the adjacent vertices of the picked vertex. 
       for (int v = 1; v <= V; v++) 
   
         // Update dist[v] only if is not in sptSet, there is an edge from  
         // u to v, and total weight of path from src to  v through u is  
         // smaller than current value of dist[v] 
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX  
                                       && dist[u]+graph[u][v] < dist[v]) 
            dist[v] = dist[u] + graph[u][v]; 
     } 
     printSolution(dist);
} 
pll ma(ll x,ll y)
{
    return make_pair(min(x,y),max(x,y));
}
ll t,n,m;

int main()
{
    IOS
    cin>>t;
    map<pll,ll> weig;
    REP(te,t)
    {
        cin>>n>>m;
     	V=n;
	    ll graph[n+1][n+1]={};
	    REP(i,n)
	    {
	    	REP(j,n)
	    	{
	    		graph[i+1][j+1]=INT_MAX;
			}
		}
        REP(i,m)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            graph[x][y]=z;
            graph[y][x]=z;
            weig[ma(x,y)]=z;
        }
        map<pll,ll>::iterator it=weig.begin();
        ll prev=-1;
        bool f=1;
        while(it!=weig.end() && f)
        {
            prev=it->ff.ff;
            ll dist[n+1];
            dijkstra(it->ff.ff,dist);
            while(it!=weig.end() && it->ff.ff==prev)
            {
                if(dist[it->ff.ss]==it->ss)
                {
					f=0;
					break;
				}    
            }
        }
        if(f)
        {
            cout<<"Case #"<<te+1<<": "<<m<<endl;
            for(it=weig.begin();it!=weig.end();it++)
            {
                cout<<it->ff.ff<<" "<<it->ff.ss<<endl;
            }
        }
        else
        {
            cout<<"Case #"<<te+1<<": Impossible"<<endl;
        }
    }
    return 0;
}
