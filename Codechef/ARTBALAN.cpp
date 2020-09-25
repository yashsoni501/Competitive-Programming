#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;

ll len(string s)
{
    ll l;
    for(l=0;s[l]!='\0';l++);
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    string s;

    while(t--)
    {
        cin>>s;
        ll l=len(s);
        ll arr[26]={};

        for(ll i=0;i<l;i++)
        {
            arr[s[i]-'A']++;
        }
        //cout<<"here"<<endl;
        ll mini=1e9;
        sort(arr,arr+26,greater<ll>());

        //cout<<"here"<<endl;
        for(int i=1;i<=26;i++)
        {
            if(l%i)
            {
                continue;
            }
            ll sz=l/i;
            ll sum=0;

            for(int j=0;j<i;j++)
            {
                sum+=max((ll)0,arr[j]-sz);
            }
            for(int j=i;j<26;j++)
            {
                sum+=arr[j];
            }
            mini=min(mini,sum);
        }
        cout<<mini<<endl;
    }
}
