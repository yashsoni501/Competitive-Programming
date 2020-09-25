#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define OTP(s) cout<<s<<endl;
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;

ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}

string strAdd(string a,string b) // adds two integers stored as strings and return the sum
{
    if(a.length()<b.length())
    {
        string tmp(b.length()-a.length(),'0');
        a=tmp+a;
    }
    if(b.length()<a.length())
    {
        string tmp(a.length()-b.length(),'0');
        b=tmp+b;
    }
    string s(a.length()+1,'0');
    ll carry=0,carry2=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        carry2=0;
        ll tmp=a[i]-48+b[i]-48+carry;
        if(tmp>9)
            carry2=1,tmp-=10;
        
        s[i+1]=tmp+48;
        carry=carry2;
    }
    s[0]=carry+48;
    if(s[0]=='0')
        s=s.substr(1,s.length());
    return s;
}

string min2(string a,string b)
{
    if(a.length()>b.length())   return b;
    if(b.length()>a.length())   return a;
    return min(a,b);
}
int main()
{
    IOS
    ll l;
    string s;
    cin>>l>>s;
    if(l%2==0)
    {
        ll l1,l2;
        l1=l/2;
        l2=l/2;
        while(s[l1]=='0')   l1--;
        while(s[l2]=='0')   l2++;
        if(l1==0)   l1=l2;
        string tmp1=strAdd(s.substr(0,l1),s.substr(l1,l-l1));
        string tmp2=strAdd(s.substr(0,l2),s.substr(l2,l-l2));
        cout<<min2(tmp1,tmp2)<<endl;
    }
    else
    {
        ll l1,l2,l3,l4;
        l1=l/2;
        l2=l/2;
        l3=(l+1)/2;
        l4=(l+1)/2;
        while(s[l1]=='0')   l1--;
        while(s[l2]=='0')   l2++;
        while(s[l3]=='0')   l3--;
        while(s[l4]=='0')   l4++;
        if(l3==0)   l3=l4;   
        if(l1==0)   l1=l2;
        string tmp1=strAdd(s.substr(0,l1),s.substr(l1,l-l1));
        string tmp2=strAdd(s.substr(0,l2),s.substr(l2,l-l2));
        string tmp3=strAdd(s.substr(0,l3),s.substr(l3,l-l3));
        string tmp4=strAdd(s.substr(0,l4),s.substr(l4,l-l4));
        //cout<<tmp1<<" "<<tmp2<<endl;
        cout<<min2(min2(tmp1,tmp2),min2(tmp3,tmp4))<<endl;
    }
    
}