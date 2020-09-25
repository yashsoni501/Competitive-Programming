#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;

int main()
{
    IOS
    ll x,y,z;
    cin>>x>>y>>z;
    if(x-z>y)
    {
        cout<<"+"<<endl;
    }   
    else if(y-z>x)
    {
        cout<<"-"<<endl;
    }
    else if(x==y && z==0)
    {
        cout<<"0"<<endl;
    }
    else
    {
        cout<<"?"<<endl;
    }
    
}