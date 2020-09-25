#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n;
ll ar[1000000];

int main()
{
    IOS
    cin>>n;
    REP(i,n)
    {
        cin>>ar[i];
        ar[i] = abs(ar[i]);
    }

    sort(ar,ar+n);

    ll cnt=0;
    for(int i=n-1;i>=0;i--)
    {
        cnt += ar+i - lower_bound(ar,ar+n,(ar[i]+1)/2);
        for(int it = lower_bound(ar,ar+n,(ar[i]+1)/2)-ar;it<i;it++)
        {
            cout<<ar[i]<<" "<<ar[it]<<endl;
        }
    }

    cout<<cnt<<endl;
}