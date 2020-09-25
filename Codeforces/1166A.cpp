#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n;
ll a[26];

int main()
{
    IOS
    cin>>n; 
    string tmp;
    REP(i,n)
    {
        cin>>tmp;
        a[tmp[0]-'a']++;
    }
    ll cnt = 0;
    REP(i,26)
    {
        ll t=a[i]/2;
        cnt += t*(t-1)/2;
        cnt += (a[i]-t)*(a[i]-t-1)/2;
    }
    cout<<cnt<<endl;
}