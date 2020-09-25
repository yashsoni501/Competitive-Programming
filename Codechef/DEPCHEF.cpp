#include<bits/stdc++.h>
using namespace std;

#define input for(int i=0;i<n;i++) cin

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],d[n];
        input>>a[i];
        input>>d[i];

        int ma=0,ind=-1;
        for(int i=0;i<n;i++)
        {
            if(d[i]-a[(n+i-1)%n]-a[(i+1)%n]>0)
            {
                if(ma<d[i])
                {
                    ind=i;
                    ma=d[ind];
                }
            }
        }
        if(ma)
        {
            cout<<d[ind]<<endl;
        }
        else
            cout<<-1<<endl;
    }
}
