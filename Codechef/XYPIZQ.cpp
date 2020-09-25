#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;

int main()
{
    ll T,t,n,x,y,z;
    cin>>T;
    while(T--)
    {
        cin>>n>>t>>x>>y>>z;
        if(t==1||t==3)
        {
            if(t==3)
            {
                int temp=x;
                x=z;
                z=temp;
            }
            if(x==z)
            {
                ll p=__gcd(x,2*n+1);
                cout<<x/p<<" "<<(2*n+1)/p<<endl;
            }
            else
            {
                ll q;
                if(x>z)
                {
                    q=2*n+1-(y-1);
                    ll p=__gcd(q,2*n+1);
                    cout<<q/p<<" "<<(2*n+1)/p<<endl;
                }
                else
                {
                    q=2*n+1-(y+1);
                    ll p=__gcd(q,2*n+1);
                    cout<<q/p<<" "<<(2*n+1)/p<<endl;
                }
            }
        }
        else
        {
            ll p=__gcd(2*n+1-2*y,2*n+1);
            cout<<(2*n+1-2*y)/p<<" "<<(2*n+1)/p<<endl;
        }
    }
}
