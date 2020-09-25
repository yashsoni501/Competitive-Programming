#include<bits/stdc++.h>
using namespace std;

#define FOR(i,j,k,s) for(int i=j;i<k;i+=s)
#define REM(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n,a[300000],b[300000];
ll taken[300000],ans[300000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    REM(i,n)
    {
        cin>>a[i];
    }
    REM(i,n)
    {
        cin>>b[i];
    }
    REM(i,n)
    {
        taken[i]=0;
        a[i]%=n;
        b[i]%=n;
    }
    sort(b,b+n);
    REM(i,n)
    {
        
    }

}
