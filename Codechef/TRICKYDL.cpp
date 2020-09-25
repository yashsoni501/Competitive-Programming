#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll t,a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        ll d1=0,d2=-1,pr=0,mp=-3e9,q=1;
        do
        {
            d1++;
            pr+=a-q;
            q*=2;
            if(pr>mp)
            {
                mp=pr;
                d2=d1;
            }
        } while(pr>0);
        cout<<d1-1<<" "<<d2<<endl;
    }
}
