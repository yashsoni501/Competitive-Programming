#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REM(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n, a[1000005];
ll dp[1000005];

void merge(ll st,ll en)
{
    ll mid=(st+en)/2;
    ll leftsz=mid-st;
    ll rightsz=en-mid;
    pair<ll,ll> leftar[leftsz],rightar[rightsz];
    FOR(i,st,mid,1) leftar[i-st]=make_pair(dp[i],i);
    FOR(i,mid,en,1) rightar[i-mid]=make_pair(dp[i],i);
    sort(leftar,leftar+leftsz);
    sort(rightar,rightar+rightsz);
    ll maxar[leftsz];
    ll maxi=leftar[0];
    REM(i,leftar)
    {
        maxi = min(maxi,leftar[i]);
        maxar[i]=maxi;
    }
    ll lind=0,rind=0;
    while(lind<leftsz && rind<rightsz)
    {
        //cout<<"here"<<endl;
        if(get<0>(rightar[rind]) >= get<0>(leftar[lind+1]))
        {
            lind++;
            continue;
        }
        dp[get<1>(rightar[rind])] += maxr[lind];
        rind++;
    }

}

void mergeSort(ll st,ll en)
{
    if(st==en-1) return;

    ll mid=(st+en)/2;
    mergeSort(st,mid);
    mergeSort(mid,en);

    merge(st,en);
}

int main()
{
    IOS
    cin>>n;
    REM(i,n) cin>>a[i];
    REM(i,n) dp[i]=1;
    mergeSort(0,n);
    REM(i,n) cout<<a[i]<<" ";
    cout<<endl;
    REM(i,n) cout<<i<<" "<<dp[i]<<endl;
}