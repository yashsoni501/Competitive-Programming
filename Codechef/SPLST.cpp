#include<iostream>
using namespace std;

typedef long long int ll;
ll t,x,y,a[3];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a[0]>>a[1]>>a[2]>>x>>y;

        int m=0,n=0;
        for(int i=0;i<2;i++)
        {
            if(a[i]<=x)
                m++;
            if(a[i]<=y)
                n++;
        }
        if(m&&n&&m+n>2)
        {
            if(a[0]+a[1]+a[2]==x+y)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
}
