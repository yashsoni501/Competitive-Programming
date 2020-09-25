#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;
ll n,t,a[100005];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll *ps=a;
        ll *pe=a+n;
        sort(ps,pe);

        ll mi=1000000005;
        for(int i=1;i<n;i++)
        {
            mi=min(mi,a[i]-a[i-1]);
        }
        cout<<mi<<endl;
    }
}
