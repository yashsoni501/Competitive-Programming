#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
stack<ll> st;
int main()
{
    IOS
    ll n;
    cin>>n;
    ll cnt=0,ad=1;

    bool b=0;
    ll c=0;
    while(n--)
    {
        
        char s[10];
        cin>>s;

        //cout<<s<<endl;
        if(s[0]=='e')
        {
            if(b)
            {
                c--;
                if(c == 0)
                {
                    b=0;
                }
            }
            else
            {
                ll tmp = st.top();
                st.pop();
                ad/=tmp;
            }
        }
        else if(s[0]=='a')
        {
            if(b)
            {
                cout<<"OVERFLOW!!!"<<endl;
                return 0;
            }
            if(4294967295-ad>=cnt)
                cnt+=ad;
            else
            {
                cout<<"OVERFLOW!!!"<<endl;
                return 0;
            }
        }
        else
        {
            ll o;
            cin>>o;
            if(!b)
            {
                st.push(o);
                ad*=o;
            }
            if(ad>4294967295 && !b)
            {
                b=1;
                c=0;
            }
            if(b)
                c++;
        }    
    }
    cout<<cnt<<endl;
}