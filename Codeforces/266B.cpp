#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define OTP(s) cout<<s<<endl;
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;

ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}

char ar[100];
char ar2[100];
int main()
{
    IOS
    ll n,t ;
    cin>>n>>t;
    cin>>ar;
    for(int i=0;i<t;i++)
    {
        strcpy(ar2,ar);
        REP(j,n-1)
        {
            if(ar[j]=='B' && ar[j+1]=='G')
                ar2[j]='G',ar2[j+1]='B';
        }
        strcpy(ar,ar2);
    }   
    cout<<ar<<endl;
}