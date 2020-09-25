#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    ll arr[t];

    ll ma=0;
    for(int i=0;i<t;i++)
    {
        cin>>arr[i];
        ma=max(ma,arr[i]);
    }
    ll sum[ma+1]={};
    for(int i=1;i<=ma;i++)
    {
        for(int j=2*i;j<=ma;j+=i)
        {
            sum[j]+=i;
        }
    }

    for(int i=0;i<t;i++)
    {
        cout<<sum[arr[i]]<<endl;
    }
}
