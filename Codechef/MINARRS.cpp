#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n,t,a[100005],b[100005];


int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        ll xoro=0;
        ll tmp=1;
        ll cnt=0;
        bool over=0;
        while(!over)
        {
            over=1;
            cnt=0;
            for(int i=0;i<n;i++)
            {
                if(a[i])
                {
                    over=0;
                }
                if(a[i]%2)
                {
                    cnt++;
                }
                a[i]/=2;
            }
            if(cnt>n/2)
            {
                xoro+=tmp;
            }
            tmp*=2;
        }
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=b[i]^xoro;
        }
        cout<<sum<<endl;
    }
}