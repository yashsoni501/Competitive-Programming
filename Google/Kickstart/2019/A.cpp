#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll t,n,q;
char a[100005];
ll ar[26][100005];

bool parity(ll a)
{
    return a%2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>t;
    for(int te=1;te<=t;te++)
    {
        cin>>n>>q;
        cin>>a;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<n;j++)
            {
                ar[i][j]=0;
            }
        }
        ar[a[0]-'A'][0]++;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                ar[j][i]=ar[j][i-1];
            }
            ar[a[i]-'A'][i]++;
        }

        ll l,r;
        bool odd,cntod,yes;
        ll ans=0;
        while(q--)
        {
            yes=1;
            cin>>l>>r;
            if(r-l+1%2)
            {
                odd=1;
                cntod=0;
            }
            else
                odd=0;
            for(int i=0;i<26;i++)
            {
                if(parity(ar[i][r-1]-ar[i][l-2]))
                {
                    if(odd)
                    {
                        if(!cntod)
                        {
                            cntod++;
                        }
                        else
                        {
                            yes=0;
                            break;
                        }
                    }
                    else
                    {
                        yes=0;
                        break;
                    }
                }
            }
            if(yes)
                ans++;
            
        }
        cout<<"Case #"<<te<<": "<<ans<<endl;
    }   
}