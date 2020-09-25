#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
#define PI 3.14159265358979323846264338327950288419716939937510
#define epsilon 1e-9
typedef long long int ll;
ll n,m;

bool iszero(double d)
{
    return abs(d)<epsilon;
}
int main()
{
    IOS
    cin>>n>>m;
    double x=0,y=0;
    double theta=2*PI/n;
    REP(i,m)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        double t=min(abs(a-b),n-abs((n+a-b)%n));
        cout<<t<<endl;
        double len = 2*sin(t/2*theta);
        x += len*(cos(a*theta) + cos(b*theta)/2);
        y += len*(sin(a*theta) + sin(b*theta)/2);
    }
    if(iszero(x) && iszero(y))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
   cout<<x<<" "<<y<<endl;
}