#include<bits/stdc++.h>
using namespace std;

#define INF 1e18
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;
ll n,a[1000000];
vector<ll> st,bk;

void printerr(vector<ll> st)
{
    cout<<"printing: ";
    for(vector<ll>::iterator it = st.begin();it!=st.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main()
{
    IOS
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%3)
    {
        cout<<0<<endl;
        return 0;
    }
    ll pssum=sum/3;
    sum=0;


    for(int i=0;i<n-1;i++)
    {
        sum+=a[i];
        if(sum==pssum)
        {
            st.push_back(i);
        }
    }
    sum=0;
    for(int j=n-1;j>0;j--)
    {
        sum+=a[j];
        if(sum==pssum)
        {
            bk.push_back(j-1);
        }
    }
    sort(bk.begin(),bk.end());
    //printerr(st);
    //printerr(bk);
    ll ans=0;
    for(vector<ll>::iterator it=st.begin();it!=st.end();it++)
    {
        ans+=bk.end() - upper_bound(bk.begin(),bk.end(),*it);
    }

    cout<<ans<<endl;
}