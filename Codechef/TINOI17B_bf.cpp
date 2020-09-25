#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n,sini;
ll e[5010];
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

struct ret
{
    ll xp;
    string s;
};

ret recur(ll day,ll state,ll strength,ll xp)
{
    if(day==0)
    {
        ret st0=recur(day+1,0,strength,xp),st1=recur(day+1,1,strength,xp);
        if(st0.xp>st1.xp)
        {
            return ret{st0.xp,"0"+st0.s};
        }
        else
        {
            return ret{st1.xp,"1"+st1.s};
        }
    }
    if(day==n+1)
    {
        return ret{xp,""};
        
    }
    if(state==0)
    {
        strength+=soc(strength);
    }
    else
    {
        xp+=strength*e[day];
    }
    ret st0=recur(day+1,0,strength,xp),st1=recur(day+1,1,strength,xp);
    if(st0.xp>st1.xp)
    {
        return ret{st0.xp,"0"+st0.s};
    }
    else
    {
        return ret{st1.xp,"1"+st1.s};
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>sini;
    for(int i=1;i<=n;i++)
    {
        cin>>e[i];
    }

    ret x=recur(0,0,sini,0);
    cout<<x.s<<endl;
    cout<<x.xp<<endl;
}