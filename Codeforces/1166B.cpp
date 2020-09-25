#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll k;
char vow[6] = "aeiou";



int main()
{
    IOS
    cin>>k;
    ll n,m;
    n = m = -1;
    if(k<25)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=5;i<=sqrt(k);i++)
    {
        if(k%i==0)
        {
            n=i;
            m=k/i;
        }
    }
    if(n==-1 )
    {
        cout<<-1<<endl;
        return 0;
    }
    
    char ar[n][m];
    REP(i,n)
    {
        REP(j,m)
        {
            ar[i][j] = vow[(i+j)%5];
        }
    }

    REP(i,n)
    {
        REP(j,m)
        {
            cout<<ar[i][j];
        }
        //cout<<endl;
    }
    cout<<endl;
    
}