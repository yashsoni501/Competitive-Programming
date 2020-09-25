#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;

int main()
{
    IOS
    ll n;
    string s;
    string t="";
    cin>>n>>s;
    ll cnt=0;
    ll i=1;
    char prev=s[0];
    t+=s[0];
    while(i<n)
    {
        if(s[i]!=prev)
        {
            t+=s[i];
            
            if(i<n-1)
            {
                t+=s[i+1];
                prev=s[i+1];
            }
            i+=2;
        }
        else
        {
            i++;
            cnt++;
        }
        
    }
    if(t.length()%2!=0)
    {
        cnt++;
    }

    cout<<cnt<<endl;
    for(int i=0;i<((int)t.length()/2)*2;i++)
        cout<<t[i];
    cout<<endl;
    
}