#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n,b,a;
    cin>>n>>b>>a;
    ll ain=a;
    ll s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    ll in=0;
    while((a>=0||b>=0)&&in<n)
    {
        if(s[in])
        {
            if(b>0)
            {
                if(a<ain)
                {
                    b--;
                    a++;
                }
                else
                {
                    a--;
                }
            }
            else if(a>0)
                a--;
            else
            {
                break;
            }
        }
        else
        {
            if(a>0)
            {
                a--;
            }
            else if(b>0)
            {
                b--;
            }
            else
            {
                break;
            }
        }
        in++;
        //cout<<in<<" "<<a<<" "<<b<<endl;
    }
    cout<<in<<endl;
}
