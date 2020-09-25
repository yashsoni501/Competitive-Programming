#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;

int main()
{
    IOS
    string s;
    ll n,x,y;
    cin>>n>>x>>y;
    cin>>s;
    ll cnt=0;
    for(int i=s.length()-1;i>s.length()-1-x;i--)
    {
        if(s[i]=='1')
        {
            cnt++;
        }
    }
    
    if(s[s.length()-1-y]=='1')
    {
        cnt--;
    }
    else
    {
        cnt++;
    }
    
    
    cout<<cnt<<endl;
    
}