#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct node
{
    ll a,b;
};

bool comp(node x,node y)
{
    return (x.a-x.b)>(y.a-y.b);
}
node ar[100005];
node lft[100005],rght[100005],mid[100005];
ll lcnt=0,rcnt=0,mcnt=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>ar[i].a>>ar[i].b;
    }
    for(int i=0;i<n;i++)
    {
        if(ar[i].a>ar[i].b)
        {
            lft[lcnt++]=ar[i];
        }
        else if(ar[i].a==ar[i].b)
        {
            mid[mcnt++]=ar[i];
        }
        else
        {
            rght[rcnt++]=ar[i];
        }
    }

    sort(lft,lft+lcnt,comp);
    sort(rght,rght+rcnt,comp);
    sort(mid,mid+mcnt,comp);

    ll ind=0,sum=0;

    for(int i=0;i<lcnt;i++)
    {
        ll j=i+1;
        sum+=(lft[i].a)*(j-1)+(lft[i].b)*(n-j);
    }
    for(int i=0;i<mcnt;i++)
    {
        ll j=lcnt+i+1;
        sum+=(mid[i].a)*(j-1)+(mid[i].b)*(n-j);
    }
    for(int i=0;i<rcnt;i++)
    {
        ll j=lcnt+mcnt+i+1;
        sum+=(rght[i].a)*(j-1)+(rght[i].b)*(n-j);
    }
    cout<<sum<<endl;
    
}