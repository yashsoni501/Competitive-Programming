#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll k;

int main()
{
    IOS
    cin>>k;
    k--;

    ll ar[20];
    ar[0]=0;
    FOR(i,1,20,1)
    {
        ll tmp = i;
        for(int j=0;j<i;j++)
        {
            tmp*=10;
        }
        //cout<<tmp<<endl;
        tmp-=i*(i+1)/2;
        ll x=0;
        for(int j=0;j<i-1;j++)
        {
            x=x*10+1;
        }
        x*=10;
        tmp-=x;
        ar[i]=tmp;
        //cout<<ar[i]<<endl;
    }
    //return 0;
    ll tmp=0;
    for(int i=0;i<16;i++)
    {
        if(k>=ar[i]&&k<ar[i+1])
        {
            k-=ar[i];
            tmp=i+1;
            break;
        }
    }
    //cout<<tmp<<" here"<<endl;
    ll n=k/tmp;
    ll m=pow(10,tmp-1)+n+0.1;

    //cout<<m<<endl;
    k = tmp-k%tmp;
    ll ans;
    //cout<<k<<endl;
    while(k--)
    {
        ans=m%10;
        m/=10;
    }
    cout<<ans<<endl;
}