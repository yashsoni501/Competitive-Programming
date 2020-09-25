#include<iostream>
using namespace std;

typedef long long int ll;
ll t,n,x,s,a,b;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>s;
        while(s--)
        {
            cin>>a>>b;
            if(x==a)
                x=b;
            else if(x==b)
                x=a;
        }
        cout<<x<<endl;
    }
}
