#include<bits/stdc++.h>
using namespace std;

#define input for(int i=0;i<n;i++) cin
typedef long long int ll;
ll t,n;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll tmp;
        ll sum=1;
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            sum+=tmp-1;
        }
        cout<<sum<<endl;
    }
}
