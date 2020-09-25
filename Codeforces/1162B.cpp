#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n,m;
ll a[50][50],b[50][50];

int main()
{
    bool ans=1;
    IOS
    cin>>n>>m;
    REP(i,n)
    {
        REP(j,m)
        {
            cin>>a[i][j];
        }
    }
    REP(i,n)
    {
        REP(j,m)
        {
            cin>>b[i][j];
        }
    }

    REP(i,n)
    {
        REP(j,m-1)
        {
            if(!((a[i][j]<a[i][j+1] && b[i][j]<b[i][j+1]) || (a[i][j]<b[i][j+1] && b[i][j]<a[i][j+1])))
            {
                ans=0;
                break;
            }
        }
    }
    REP(j,m)
    {
        REP(i,n-1)
        {
            if(!((a[i][j]<a[i+1][j] && b[i][j]<b[i+1][j]) || (a[i][j]<b[i+1][j] && b[i][j]<a[i+1][j])))
            {
                ans=0;
                break;
            }
        }
    }

    if(ans)
    {
        cout<<"Possible"<<endl;
    }
    else
    {
        cout<<"Impossible"<<endl;
    }
    
}
