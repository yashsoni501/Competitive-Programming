#include<bits/stdc++.h>
#include<fstream>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define OTP(s) cout<<s<<endl;
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)

typedef long long int ll;

ll linear_count(string a, char find_this)
{
    ll linear_count_cnt=0;
    for(ll i=0;i<a.length();i++)
    {
        if(a[i]==find_this)  linear_count_cnt++;
    }
    return linear_count_cnt;
}

int main()
{
    fstream fin,fout;
    fin.open("input.txt");
    fout.open("output.txt");

    ll t;
    fin>>t;
    REP(te,t)
    {
        string s;
        fin>>s;
        ll n=s.length()-1;
        ll n_b=linear_count(s,'B');
        fout<<"Case #"<<te+1<<": ";
        if(n_b >= (n+1)/2 && n_b<n)
            fout<<"Y"<<endl;
        else
        {
            fout<<"N"<<endl;
        }
    }
}