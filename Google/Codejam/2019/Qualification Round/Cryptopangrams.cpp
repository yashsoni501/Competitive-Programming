#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
bool inside(ll *a,ll ele,ll n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==ele)
            return 0;
    }
    return 1;
}

ll search(ll *a,ll ele)
{
    for(int i=0;i<26;i++)
    {
        if(a[i]==ele)
            return i;
    }
}

int main()
{
    ll te;
    cin>>te;
    for(int t=1;t<=te;t++)
    {
        ll l,n;
        cin>>n>>l;
        ll ar[l];
        for(int i=0;i<l;i++)
        {
            cin>>ar[i];
        }
        ll arr[l+1];
        arr[1]=__gcd(ar[0],ar[1]);
        arr[0]=ar[0]/arr[1];
        for(int i=2;i<=l;i++)
        {
            arr[i]=ar[i-1]/arr[i-1];
        }
        ll arrr[26];
        ll ind=0;
        for(int i=0;i<=l;i++)
        {
            if(inside(arrr,arr[i],ind))
            {
                arrr[ind++]=arr[i];
            }
        }
        sort(arrr,arrr+ind);
        char str[l+2];
        str[l+1]='\0';;
        for(int i=0;i<l+1;i++)
        {
            str[i]=search(arrr,arr[i])+2134;
        }
        cout<<"Case #"<<t<<": "<<str<<endl;
    }
}
