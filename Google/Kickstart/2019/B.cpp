#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll s[100005],e[100005],l[100005],consumed[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,n;
    cin>>t;
    for(int te=1;te<=t;te++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            consumed[i]=0;
        for(int i=0;i<n;i++)
        {
            cin>>s[i]>>e[i]>>l[i];
        }

        ll ind=-1;
        ll ene=0;
        for(int j=0;j<n;j++)
        {
            ll ma=-1e9;
            for(int i=0;i<n;i++)
            {
                if(!consumed[i] && (e[i]>ma || (e[i]==ma && l[i]>l[ind])))
                //if(!consumed[i] &&e[i]>ma)
                {
                    ma=e[i];
                    ind=i;
                }
                
            }
            ene+=e[ind];
            consumed[ind]=1;
            for(int i=0;i<n;i++)
            {
                e[i]=max(e[i]-s[ind]*l[i],(ll)0);
            }
        }
        cout<<"Case #"<<te<<": "<<ene<<endl;
    }


    
}