#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n;
string s;

int main()
{
    IOS
    //cin>>n;
    cin>>s;
    n=s.length();
    ll op=0,cl=0;
    REP(i,s.length())
    {
        if(s[i]=='(')
        {
            s[i]=op%2+48;
            op++;
        }
        else
        {
            s[i]=cl%2+48;
            cl++;
        }
    }
    cout<<s<<endl;
}