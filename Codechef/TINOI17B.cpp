#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

#define max(a,b) a>b?a:b

typedef long long int ll;
ll n,sini;
ll e[5010];
ll sp[5010];
ll dp[5010][2];
ll soc(ll a)
{
    ll sum=0;
    while(a)
    {
        sum+=a%10;
        a/=10;
    }
    return sum*sum*sum;
}

ll arrr[5010]={};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //ifstream fin("2.in");
    cin>>n>>sini;
    for(int i=1;i<=n;i++)
    {
        cin>>e[i];
    }
    sp[0]=sini;
    for(int i=1;i<=n;i++)
    {
        sp[i]=sp[i-1]+soc(sp[i-1]);
    }
    
    dp[0][0]=0;
    dp[0][1]=sini;
    for(int i=1;i<=n;i++)
    {
        ll ma=1e-9;
        cout<<" i = "<<i<<" ";
        for(int j=0;j<i;j++)
        {
            ll st=*(upper_bound(sp,sp+n+1,dp[j][1])+i-j-2);
            
            ll t=dp[j][0]+(st)*e[i];
            if(ma<t)
            {
                dp[i][0]=t;
                dp[i][1]=st;
                ma=t;
                arrr[i]=j;
                cout<<ma<<" ";
            }
        }
        cout<<endl;
    }
    
    //cout<<"here"<<endl;
    string s="";
    bool ar[n+1]={};
    ll ind=n;
    
    for(int i=0;i<=n;i++)
    {
        cout<<arrr[i]<<" ";
    }
    cout<<endl;
    
    
    while(ind>0)
    {
        ar[ind]=1;
        ind=arrr[ind];
    }

    for(int i=1;i<=n;i++)
    {
        cout<<ar[i];
    }
    cout<<endl;
    
    for(int i=0;i<=n;i++)
    {
        cout<<dp[i][0]<<" ";
    }
    cout<<endl;
        for(int i=0;i<=n;i++)
    {
        cout<<dp[i][1]<<" ";
    }
    cout<<endl;
    
    cout<<dp[n][0]<<endl;
}
