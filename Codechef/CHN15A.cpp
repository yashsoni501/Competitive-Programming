#include<iostream>
using namespace std;

typedef long long int ll;

ll t,n,k,a[105],c;

int main()
{
    cin>>t;
    while(t--)
    {
        c=0;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if((a[i]+k)%7==0)
            {
                c++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
