#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef long int li;
bool prime[1000050];
#define FIXED_FLOAT(x) std::fixed <<std::setprecision(10)<<(x)
struct node
{
    int x;
    lli y;
};
bool compare(node a,node b)
{
    return a.x > b.x;
}
// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
}

void DFSUtil(int u, vector<int> adj[],
                    vector<bool> &visited)
{
    visited[u] = true;
    //cout<<u+1<<" ";
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i], adj, visited);
}
void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
        if (visited[u] == false)
            DFSUtil(u, adj, visited);
}
void PG(vector<int> adj[], int V)
{
    for(int i = 0; i<V; i++)
    {
        cout<<i+1<<": ";
        for(int j = 0; j<adj[i].size(); j++)
        {
            cout<<adj[i][j]+1<<" ";
        }
        cout<<endl;
    }
}
bool isPerfectSquare( double x)
{
  double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
lli sumofdigits(lli n)
{
    lli sum = 0;
    while(n > 0)
    {
        sum++;
        n /= 10;
    }
    return sum;
}
void bfs(vector <int> adj[], lli u, vector <int> &distances)
{
    queue <int> q;
    q.push(u);
    lli ans;
    lli neighbor;
    while(q.empty() == false)
    {
        int f = q.front();
        q.pop();
        //cout<<f+1<<" ";
        for(int i = 0; i<adj[f].size(); i++)
        {
            neighbor = adj[f][i];
            if(distances[neighbor] == -1)
            {
                q.push(neighbor);
                distances[neighbor] = distances[f] + 1;
            }
        }
    }
}
lli count4(lli n)
{
    lli counter = 0;
    while(n >0)
    {
        if(n%10 == 4)
            counter++;
        n/=10;
    }
    return counter;
}
lli count7(lli n)
{
    lli counter = 0;
    while(n >0)
    {
        if(n%10 == 7)
            counter++;
        n/=10;
    }
    return counter;
}
int powprime(lli n, lli factor)
{
    int j = 0;
    while(n%factor == 0)
    {
        n = n/factor;
        j++;
    }
    return j;
}
int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    node arr[1000000];
    char date[6];
    lli no;
    lli j = 0;
    for(int i = 0; i<1000000; i++)
    {
        arr[i].x = 0;
        arr[i].y = i;
    }
    for(int i = 0; i<=s.length()-10; i++)
    {
        if(s.at(i+2) == '-' & s.at(i+5) == '-' & isdigit(s.at(i))&isdigit(s.at(i+1))&isdigit(s.at(i+3))&isdigit(s.at(i+4))& s.at(i+6) == '2' & s.at(i+7) == '0' &isdigit(s.at(i+8))&isdigit(s.at(i+9)))
        {
            date[0] = s.at(i);
            date[1] = s.at(i+1);
            date[2] = s.at(i+3);
            date[3] = s.at(i+4);
            date[4] = s.at(i+8);
            date[5] = s.at(i+9);
            no = atoi(date);
            if(arr[no].x == 0)
             j++;
            arr[no].x++;

        }
    }
    sort(arr, arr+1000000, compare);
    int mon,da,ye;
    for(int i = 0; i<j; i++)
    {
        da = arr[i].y/10000;
        mon = (arr[i].y/100)%100;
        ye = arr[i].y%100;
        //cout<<da<<mon<<ye<<endl;
        if(ye >= 13 & ye <=15)
        {
            if(mon == 2)
            {
                if(da >= 10 & da <= 28)
                {
                    cout<<da<<"-"<<0<<mon<<"-20"<<ye<<endl;
                        exit(0);
                }
                if(da >0 & da<10)
                {
                    cout<<0<<da<<"-"<<0<<mon<<"-20"<<ye<<endl;
                        exit(0);
                }
            }
            if(mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
            {
                if(da >=10 & da <=31)
                {
                    if(mon <10)
                    {
                        cout<<da<<"-0"<<mon<<"-20"<<ye<<endl;
                        exit(0);
                    }
                    if(mon >=10 & mon <= 12)
                    {
                        cout<<da<<"-"<<mon<<"-20"<<ye<<endl;
                        exit(0);
                    }
                }
                else if(da > 0 & da <10)
                {
                    if(mon <10)
                    {
                        cout<<0<<da<<"-0"<<mon<<"-20"<<ye<<endl;
                        exit(0);
                    }
                    if(mon >=10 & mon <= 12)
                    {
                        cout<<0<<da<<"-"<<mon<<"-20"<<ye<<endl;
                        exit(0);
                    }
                }
            }
            else
            {
                 if(da >=10 & da <=30)
                {
                    if(mon <10)
                    {
                        cout<<da<<"-0"<<mon<<"-20"<<ye<<endl;
                        exit(0);
                    }
                    if(mon >=10 & mon <= 12)
                    {
                        cout<<da<<"-"<<mon<<"-20"<<ye<<endl;
                        exit(0);
                    }
                }
                else if(da >0 & da <10)
                {
                    if(mon <10)
                    {
                        cout<<0<<da<<"-0"<<mon<<"-20"<<ye<<endl;
                        exit(0);
                    }
                    if(mon >=10 & mon <= 12)
                    {
                        cout<<0<<da<<"-"<<mon<<"-20"<<ye<<endl;
                        exit(0);
                    }
                }
            }
        }
    }
}