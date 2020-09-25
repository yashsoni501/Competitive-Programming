#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll ar[1000000];
//bool used[1000000];
ll a[6]={};

ll ind(ll i)
{
    if(i==4)
        return 0;
    if(i==8)
        return 1;
    if(i==15)
        return 2;
    if(i==16)
        return 3;
    if(i==23)
        return 4;
    if(i==42)
        return 5;
}
int main()
{
    IOS
    ll n;
    cin>>n;
    REP(i,n)
        cin>>ar[i];
    
    REP(i,n)
    {
        if(ind(ar[i])==0)    a[ind(ar[i])]++;
        else if (a[ind(ar[i])-1]>a[ind(ar[i])]) a[ind(ar[i])]++;
    }
    cout<<n-6*a[5]<<endl;

}
