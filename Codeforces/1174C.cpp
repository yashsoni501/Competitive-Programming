#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll ar[1000000]={};
int main()
{
    IOS
    ll n;
    cin>>n;
    ll cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(ar[i]==0)
        {
            for(int j=i;j<=n;j+=i)
            {
                ar[j]=cnt;
            }
            cnt++;
        }
    }
    for(int i=2;i<=n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}