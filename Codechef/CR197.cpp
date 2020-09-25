#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll p;

struct inp
{
    double val;
    ll kill;
    ll pow;
};
inp s[55];

bool comp(inp a,inp b)
{
    if(a.val!=b.val)
        return a.val<b.val;
    return a.pow<b.pow;
}

ll recur(int i)
{
    if(p==0)
        return 0;

    ll ans=s[i].kill*(p/s[i].pow);
    p%=s[i].pow;
    return ans+min(s[i].kill,recur(i+1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    ll n;
    ll tmp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>p;
        double power=1;
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            s[i].kill=tmp;
            s[i].val=tmp/power;
            s[i].pow=(ll)power;
            power*=2;
        }

        sort(s,s+n,comp);

        int ind=0;
        ll killed=0;
        killed=recur(ind);

        cout<<killed<<endl;
    }
}
