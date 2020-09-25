#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll n;
char ar[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    cin>>s;
    for(int i=1;i<10;i++)
    {
        cin>>ar[i];
    }

    ll st=-1,en=-1;
    bool a=1;
    for(int i=0;i<n&&a;i++)
    {
        if(s[i]<ar[s[i]-48])
        {
            st=en=i;
            a=0;
            while(s[en]<=ar[s[en]-48])
            {
                en++;
            }
        }
    }
    for(int i=st;i<en;i++)
    {
        s[i]=ar[s[i]-48];
    }

    cout<<s<<endl;
}
