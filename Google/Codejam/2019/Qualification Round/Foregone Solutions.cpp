#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        char n[200];
        cin>>n;
        ll len=strlen(n);
        char a[len],b[len];
        for(int i=0;i<len;i++)
        {
            if(n[i]=='4')
            {
                a[i]='2';
                b[i]='2';
            }
            else
            {
                a[i]=n[i];
                b[i]='0';
            }
        }
        a[len]='\0';
        char c[200];
        int i=0;
        for(i=0;b[i]=='0';i++);
        for(int j=i;j<len;j++)
        {
            c[j-i]=b[j];
        }
        c[len-i]='\0';
        cout<<"Case #"<<test<<": "<<a<<" "<<c<<endl;
    }
}
