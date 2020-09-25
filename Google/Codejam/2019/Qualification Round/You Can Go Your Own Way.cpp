#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll test,n;

struct location
{
    ll s,y;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        map<location,char> mp;
        cin>>n;
        location l={0,0};
        string s;
        cin>>s;
        for(int i=0;i<2*n-2;i++)
        {
            char d=s[i];
            if(d=='S')
            {
                mp.insert(pair<location,char>(l,d));
                l.x++;
            }
            else
            {
                mp.insert(pair<location,char>(l,d));
                l.y++;
            }
        }

        dfs(0,0);


    }
}
