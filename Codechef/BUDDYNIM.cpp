#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;

ll t,n,m,a[102],b[102];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int i=0;
        while(i<n)
        {
            cin>>a[i];
            if(a[i]==0)
                n--;
            else
                i++;
        }
        i=0;
        while(i<m)
        {
            cin>>b[i];
            if(b[i]==0)
                m--;
            else
                i++;
        }
        //cout<<"a "<<n<<"b "<<m<<endl;
        if(n==m)
        {
            sort(a,a+n);
            sort(b,b+m);
/*
            for(int i=0;i<n;i++)
                cout<<a[i]<<" "<<b[i]<<" ";
            cout<<endl;
*/
            bool d=true;
            for(int j=0;j<n;j++)
            {
                //cout<<"j = "<<j<<endl;
                if(a[j]!=b[j])
                {
                    d=false;
                    break;
                }
            }
            if(d)
            {
                cout<<"Bob"<<endl;
                continue;
            }
        }
        cout<<"Alice"<<endl;

    }
}
