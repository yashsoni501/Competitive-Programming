#include<iostream>
#include<string.h>
using namespace std;

typedef long long int ll;
ll t,l,r;
char s[100],e[100];

ll indexof(char *s)
{
    char r[][25]={"saturday","sunday","monday","tuesday","wednesday","thursday","friday"};
    for(ll i=0;i<7;i++)
    {
        if(!strcmp(r[i],s))
            return i;
    }
}

int main()
{
    cin>>t;
    while(t--)
    {
        ll si,ei;
        cin>>s>>e>>l>>r;
        si=indexof(s);
        ei=indexof(e);

        //ll li=l,ri=r;

        ll jump=((ei-si+7)%7+1)%7;
/*
        r=r-7*(l/7);
        l=l%7;
*/

        int cse=0,ans;
        for(int i=l;i<=r;i++)
        {
            if(i%7==jump)
            {
                cse++;
                ans=i;
            }
        }

        if(cse==0)
            cout<<"impossible"<<endl;
        else if(cse==1)
        {
            cout<<ans<<endl;
        }
        else
            cout<<"many"<<endl;
    }
}
