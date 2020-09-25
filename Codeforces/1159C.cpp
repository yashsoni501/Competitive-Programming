#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n,m;
ll b[100005],g[100005];
ll bmax=0,gmin=1e9,gsum=0;

int main()
{
    IOS
    cin>>n>>m;
    
    REP(i,n)
    {
        cin>>b[i];
        bmax=max(bmax,b[i]);
    }
    REP(i,m)
    {
        cin>>g[i];
        gmin=min(gmin,g[i]);
        gsum+=g[i];
    }
    //cout<<"bmax "<<bmax<<endl;
    //cout<<"gmin "<<gmin<<endl;
    if(bmax>gmin)
    {
        cout<<-1<<endl;
        return 0;
    }

    sort(b,b+n);
    sort(g,g+m);

    ll sweet=0;
    if(b[n-1]==g[0])
    {
        sweet+=gsum;
       // cout<<"a "<<sweet<<endl;
        REP(i,n-1)
        {
            sweet+=m*b[i];
         //   cout<<"a "<<sweet<<endl;
        }
    }
    else
    {
        sweet+=gsum-g[0] + b[n-1];
        //cout<<sweet<<endl;
        sweet+=g[0]+(m-1)*b[n-2];
        //cout<<sweet<<endl;
        REP(i,n-2)
        {
            sweet+=m*b[i];
          //  cout<<sweet<<endl;
        }
    }

    cout<<sweet<<endl;
    
}