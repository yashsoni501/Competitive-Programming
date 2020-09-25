#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;
ll n;

int main()
{
    IOS
    cin>>n;
    ll mini=n;
    ll cnt=n;
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        if(c=='-')
        {
            cnt--;
        }
        else
        {
            cnt++;
        }
        mini=min(mini,cnt);
        
    }
    cout<<cnt-mini<<endl;
}