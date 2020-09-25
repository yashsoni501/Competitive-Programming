#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n;
vector<string> mp[1000001][5];

char ar[]={'a','e','i','o','u'};

pair<ll,char> vow(string s)
{
    pair<ll,char> a;
    a.first=0;
    REP(i,s.size())
    {
        if(binary_search(ar,ar+5,s[i]))
        {
            a.first++;
            a.second=lower_bound(ar,ar+5,s[i])-ar;
        }
    }

    return a;
}

int main()
{
    IOS
    cin>>n;
    string s;
    REP(i,n)
    {
        cin>>s;
        ll vcnt=vow(s).first;
        ll lst=vow(s).second;
        mp[vcnt][lst].push_back(s);
    }  
    ll mxfrst=0,mxsnd=0;
    REP(i,1000001)
    {
        ll cnt=0;
        REP(j,5)
        {
            cnt+=mp[i][j].size();
            mxsnd+=mp[i][j].size()/2;
        }
        mxfrst+=cnt/2;
    }
    ll numcnt=min(mxfrst/2,mxsnd);
    cout<<numcnt<<endl;
    
    vector<string> fst,snd;

    REP(i,1000001)
    {
        REP(j,5)
        {
            REP(k,2*(mp[i][j].size()/2))
            {
                if(snd.size()<2*numcnt)
                {
                    snd.push_back(mp[i][j][k]);
                }
                else
                {
                    fst.push_back(mp[i][j][k]);
                }
            }
            if(mp[i][j].size()%2)
            {
                fst.push_back(mp[i][j][mp[i][j].size()-1]);
            }
        }
        if(fst.size()%2)
        {
            fst.pop_back();
        }
    }

    REP(i,2*numcnt)
    {
        cout<<fst[i]<<" "<<snd[i]<<endl;
    }
}