#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll a[1000000],b[1000000];
ll n,m,k,ta,tb;

int main()
{
    IOS
    cin>>n>>m>>ta>>tb>>k;
    REP(i,n)
    {
        cin>>a  [i];
        a[i]+=ta;
    }
    REP(i,m)
    {
        cin>>b[i];
    }
    if(k>=n || k>=m)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll ina=0,inb=0;
    ina=k;
    k=0;
    while(ina>0)
    {
        //cout<<"jere"<<endl;
        ll tmp = lower_bound(b,b+m,a[ina])-b;
        if(lower_bound(b,b+m,a[ina])-b==m)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(tmp==lower_bound(b,b+m,a[ina-1])-b)
        {
            ina--;
            k++;
        }
        else
        {
            break;
        }
    }
    inb=lower_bound(b,b+m,a[ina])-b;
    inb+=k;
    if(inb>=m)
    {
        cout<<-1<<endl;
        return 0;
    }
    //cout<<ina<<" "<<k<<" "<<inb<<endl;
    if(lower_bound(b+inb,b+m,a[ina])-b==m)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<*(lower_bound(b+inb,b+m,a[ina]))+tb<<endl;
}