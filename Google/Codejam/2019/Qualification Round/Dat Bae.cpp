#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t,n,b,f;
ll missing[20];
ll mis_cnt=0;

string input;

void push(ll s)
{
    missing[mis_cnt++]=s;
}

struct node
{
    ll x,y;
};

map<node,int> indices;

void calc(ll st,ll en,ll miss)
{
    input[n] = '\0';

    bool complete=0;

    while(!complete)
    {
        complete=1;
        for(map<ll,ll>::iterator it=indices.begin(); it!=iterator.end();it++)
        {
            if(!binary(it->first.x,it->first.y,b))
            {

            }
        }
    }
}

bool binary(ll st,ll en,ll miss)
{
    if(en-st+1==miss)
    {
        for(int i=st;i<=en;i++)
        {
            push(i);
            input[i]='1';
        }
        return 1;
    }
    else
    {
        ll mid=(en+st)/2;
        for(int i=st;i<mid;i++)
            input[i]='1';
        for(int i=mid;i<=en;i++)
            input[i]='0';

    }
    return 0;
}

int main()
{
    cin>>t;
    for(int te=1;te<=t;te++)
    {
        mis_cnt=0;
        cin>>n>>b>>f;
        for(int i=0;i<n/2;i++)
            input[i]='1';
        for(int i=n/2;i<)

    }
}
