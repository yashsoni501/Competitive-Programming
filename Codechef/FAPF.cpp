#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t,n,q;
ll a[300000],b[300000];
ll c[300000];
int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        map<ll,ll> mp;
        map<ll,ll> pos;
        cin>>n>>q;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b,b+n);
        mp[b[0]] = 1;
        pos[b[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(b[i]!=b[i-1])
            {
                mp[b[i]]=1;
                pos[b[i]]=i;
            }
            else
            {
                mp[b[i]]++;
            }
        }
        /*
        cout<<"map start"<<endl;
        for(map<ll,ll >::const_iterator it = mp.begin();it != mp.end(); ++it)
        {
            cout << it->first << " " << it->second << endl;
        }
        cout<<"map ends"<<endl;
        for(map<ll,ll >::const_iterator it = pos.begin();it != pos.end(); ++it)
        {
            cout << it->first << " " << it->second << "\n";
        }
        */
        ll x,y;
        while(q--)
        {
            cin>>x>>y;
            cout<< abs(a[x-1]-a[y-1]) + y-x<<" ";
            if(a[x-1]==a[y-1])
            {
                cout<<mp[a[x-1]]<<endl;
            }
            else
            {
                ll num=mp[a[x-1]]+mp[a[y-1]];
                if(a[x-1]<a[y-1])
                {
                    num+=lower_bound(b,b+n,a[y-1])-upper_bound(b,b+n,a[x-1]);
                }
                else
                {
                    num+=lower_bound(b,b+n,a[x-1])-upper_bound(b,b+n,a[y-1]);
                }
                
                cout<<num<<endl;
            }
        }
    }
}