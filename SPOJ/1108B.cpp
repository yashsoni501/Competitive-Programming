#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n;
    cin>>n;
    ll ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    sort(ar,ar+n);
    cout<<ar[n-1]<<" ";
    for(int i=n-2;i>=0;i--)
    {
        if(ar[i]==ar[i+1]||ar[n-1]%ar[i]!=0)
        {
            cout<<ar[i]<<endl;
            break;
        }
    }
}
