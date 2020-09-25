#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll len=0;
    cin>>len;
    cin>>s;
    ll cnt=0;
    if(len%2==1)
    {
        cout<<":("<<endl;
        return 0;
    }

    if(s[len-1]=='(')
    {
        cout<<":("<<endl;
        return 0;
    }
    else
    {
        s[len-1]=')';
    }
    if(s[0]==')')
    {
        cout<<":("<<endl;
        return 0;
    }
    else
    {
        s[0]='(';
    }
    cnt=1;

    ll q,l,r;
    q=l=r=0;
    for(int i=1;i<len-1;i++)
    {
        if(s[i]=='(')
            l++;
        else if(s[i]==')')
            r++;
        else
            q++;
    }

    ll newl,newr;
    newl=(len-2)/2-l;
    newr=(len-2)/2-r;

    if(newl<0||newr<0)
    {
        cout<<":("<<endl;
        return 0;
    }
    //cout<<newl<<" "<<newr<<endl;
    for(int i=1;i<len-1;i++)
    {
        cout<<"i = "<<i<<" "<<s<<newl<<" "<<newr<<endl;
        if(cnt<=0)
        {
            cout<<":("<<endl;
            return 0;
        }
        if(s[i]=='(')
            cnt++;
        else if(s[i]==')')
        {
            cnt--;
        }
        else
        {
            if(cnt>1)
            {
                if(newr>newl)
                {
                    s[i]=')';
                    cnt--;
                    newr--;
                }
                else
                {
                    s[i]='(';
                    cnt++;
                    newl--;
                }
            }
            else
            {
                if(newl>0)
                {
                    s[i]='(';
                    cnt++;
                    newl--;
                }
                else
                {
                    cout<<":("<<endl;
                    return 0;
                }
            }
        }
    }
    if(newl!=0||newr!=0)
    {
        cout<<":("<<endl;
        return 0;
    }
    cout<<s<<endl;
}
