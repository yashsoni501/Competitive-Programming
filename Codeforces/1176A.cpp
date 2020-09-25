#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;

int main()
{
    IOS
    ll n,q;
    cin>>q;
    while(q--)
    {

        cin>>n;
        bool a=1;
        ll cnt=0;
        while(n>1)
        {
            if(n%2==0)
            {
                cnt++;
                n/=2;
            }
            else if(n%3==0)
            {
                cnt+=2;
                n/=3;
            }
            else if(n%5==0)
            {
                cnt+=3;
                n/=5;
            }
            else
            {
                a=0;
                break;
            }
        }
        if(a)
            cout<<cnt<<endl;
        else
            cout<<-1<<endl;
    }
}
