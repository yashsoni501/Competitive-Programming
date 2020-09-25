#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;
ll t,n,inf=1000000007,a[100005],ans,fac[100005],dfct=0,l,ml;

void initialize()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+n);
    ans=1;
    fac[0]=1;
}

ll fact(int t)
{
    if(t<=dfct)
        return fac[t];
    else
        for(ll i=dfct+1;i<=t;i++)
        {
            fac[i]=(fac[i-1]*i)%inf;
            //cout<<"In fact"<<endl;
        }

    dfct=t;
    return fac[t];
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        initialize();
        while(a[n/2-1-l]==a[n/2+l]&&l<n/2)
            l++;
        cout<<"l "<<l<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"i "<<i<<endl;
            int tmp=a[i],le=0;
            while(i<n&&a[i++]==tmp)
            {
                le++;
                cout<<"IN loop"<<endl;
                cout<<"i "<<i<<endl;
            }
            i--;
            cout<<"i "<<i<<endl;
            if(a[n/2]!=tmp&&!l)
                ans=(ans*fact(le))%inf;
            else if(l&&a[n/2]==tmp)
                ml=le;
        }
        if(l)
        {
            //cout<<l<<" "<<ml<<endl;
            ans=(ans*fact(ml)/fact(ml-2*l)/fact(2*l))%inf;
            //cout<<ans<<endl;
            //cout<<ans<<"here"<<endl;
            ans=(ans*l*(2*l-1))%inf;
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
}
