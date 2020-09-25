#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll t,n,d[400];

vector<ll> divis(ll a)
{
    vector<ll> div;
    for(int i=1;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            div.push_back(i);
            div.push_back(a/i);
        }
    }
    return div;

}

int main()
{
    IOS

    cin>>t;
    while(t--)   
    {
        cin>>n;
        REP(i,n)
        {
            cin>>d[i];
        }
        bool boo=1;
        sort(d,d+n);
        ll num=d[0]*d[n-1];
        REP(i,(n+1)/2)
        {
            if(d[i]*d[n-i-1]!=num)
            {
                boo=0;
                break;
            }
        }

        vector<ll> d0 = divis(d[0]);
        vector<ll> dn = divis(d[n-1]);

        for(int i=0;i<(int)d0.size();i++)
        {
            for(int j=0;j<(int)dn.size();j++)
            {
                if(d0[i]*dn[j]==1 || d0[i]*dn[j]==num)
                    continue;
                //cout<<" fa "<<d0[i]*dn[j]<<endl;
                if(!binary_search(d,d+n,d0[i]*dn[j]))
                {
                    //cout<<"here1 "<<d0[i]*dn[j]<<endl;
                    
                    boo=0;
                    break;
                }
            }
        }

        REP(i,(int)d0.size())
        {
            if(!binary_search(d,d+n,d0[i]))
            {
                if(d0[i]==1 || d0[i]==num)
                    continue;
                //cout<<"here2 "<<d0[i]<<endl;
                boo=0;
                break;
            }
        }
        REP(i,(int)dn.size())
        {
            if(!binary_search(d,d+n,dn[i]))
            {
                if(dn[i]==1 || dn[i]==num)
                    continue;
                //cout<<"here3 "<<dn[i]<<endl;
                boo=0;
                break;
            }
        }

        if(boo)
        {
            cout<<num<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        
    }
}