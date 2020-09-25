#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;
ll n,a[100005];
//map<ll,ll> cnt;
ll ar[11]={};

int main()
{
    IOS
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    ll ind=-1;
    for(int i=0;i<n;i++)
    {
        ar[a[i]]++;
        
        ll cnt=0;
        for(int j=1;j<11;j++)
        {
            if(ar[j])
            {
                cnt++;
            }
        }
        //cout<<cnt<<endl;
        if((i+1)%cnt==1)
        {
            bool t=1,q=1;
            for(int j=1;j<11;j++)
            {
        //cout<<"here"<<endl;
                if(ar[j])
                {
                    if(ar[j]==i/cnt)
                        continue;
                    else if(ar[j]==(i/cnt+1))
                    {
                        if(!q) 
                        {
                            t=0;
                            break;
                        }
                        else q=0;
                    }
                    else
                    {
                        t=0;
                        break;
                    }
                }
            }
            if(t)
            {
                ind=i+1;
            }
        }
        else if(cnt>1&&(i+1)%(cnt-1)==0)
        {
            bool t=1,q=1;
            for(int j=1;j<11;j++)
            {
                if(ar[j]==(i+1)/(cnt-1))
                {
                    continue;
                }
                else if(ar[j]==1)
                {
                    if(!q)
                    {
                        t=0;
                        break;
                    }
                    else
                    {
                        q=0;
                    }
                }
                else
                {
                    t=0;
                    break;
                }
            }
            if(t)
            {
                ind=t+1;
            }
        }
    }
    cout<<ind<<endl;
}