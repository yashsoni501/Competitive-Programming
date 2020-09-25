#include<iostream>
using namespace std;

typedef long long int ll;
ll t,n;
char a[100005];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll ma=0,su=0;
        for(int i=0;i<n;i++)
        {
            su+=(a[i]=='0')?1:-1;
            if(su<0)
                su=0;
            ma=max(ma,su);
        }
        if(ma==0)
            cout<<-1<<endl;
        else
            cout<<ma<<endl;
    }
}
