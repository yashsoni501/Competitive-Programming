#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
ll a[300000];
string s="";
ll previ=0;

void solve(ll st,ll en)
{
    if(st==en)
    {
        if(a[st]>previ)
        {
            previ=a[st];
            s+='L';
        }
        return;
    }
    else
    {
        if(a[st]<a[en])
        {
            if(a[st]>previ)
            {
                s+='L';
                previ=a[st];
                solve(st+1,en);
            }
            else if(a[en]>previ)
            {
                s+='R';
                previ=a[en];
                solve(st,en-1);
            }
            else
            {
                return;
            }
        }
        else if(a[st]>a[en])
        {
            if(a[en]>previ)
            {
                s+='R';
                previ=a[en];
                solve(st,en-1);
            }
            else if(a[st]>previ)
            {
                s+='L';
                previ=a[st];
                solve(st+1,en);
            }
            else
            {
                return;
            }
        }
        else
        {
            if(a[st]==previ)
                return;
            
            ll i=st+1,j=en-1;
            while(a[i]==a[j] && i<j)
            {
                i++;
                j--;
            }
            cout<<i<<" "<<j<<endl;
            if(i==j)
            {
                s+='L';
                previ=a[st];
                solve(st+1,en);
            }
            else if(a[i]>a[j])
            {
                if(a[j]>a[st])
                {
                    s+='R';
                    previ=a[en];
                    solve(st,en-1);
                }
                else
                {
                    s+='L';
                    previ=a[st];
                    solve(st+1,en);
                }
            }    
            else
            {
                if(a[i]>a[st])
                {
                    s+='L';
                    previ=a[st];
                    solve(st+1,en);
                }
                else
                {
                    s+='R';
                    previ=a[en];
                    solve(st,en-1);
                }
            }
        }
    }  
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    solve(0,n-1);
    cout<<s.size()<<endl;
    cout<<s<<endl;   
}