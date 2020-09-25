#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;

int main()
{
    IOS
    ll n,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ll cnt=0;
        while(n)
        {
            if(n%k==0)
            {
                n/=k;
                cnt++;
            }
            else
            {
                cnt+=n%k;
                n-=n%k;
            }
            
        }
        cout<<cnt<<endl;
    }
}