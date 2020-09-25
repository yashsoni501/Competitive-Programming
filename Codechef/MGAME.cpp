#include<iostream>
using namespace std;

typedef long long int ll;

int main()
{
    ll t,n,p;
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        ll till=n/2+1;
        ll m=n-till;
        ll ans=0;


        if(m==0)
        {
            ans=p*p*p;
        }
        else
        {
            //layer 1
            ans+=(p-m)*(p-m);
            //layer 2
            ans+=(p-n)*(p-m);
            //layer 3
            ans+=(p-n)*(p-n);
        }
        cout<<ans<<endl;
    }
}
