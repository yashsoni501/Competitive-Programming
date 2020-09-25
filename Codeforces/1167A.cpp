#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll t,n;
string s;
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        bool boo=0;
        if(n<11)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<n-10;i++)
        {
            if(s[i]=='8')
            {
                boo=1;
                break;
            }
        }
        if(boo)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

    }
}