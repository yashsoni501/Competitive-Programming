#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;

int main()
{
    IOS
    ll n,ar[10000];
    cin>>n;
    n*=2;
    REP(i,n)    cin>>ar[i];
    bool a=1;
    REP(i,n)    if(ar[i]!=ar[0])    a=0;
    if(a)
    {
        cout<<-1<<endl;
        return 0;
    }   

    sort(ar,ar+n);
    REP(i,n)    cout<<ar[i]<<" ";
    cout<<endl;
}