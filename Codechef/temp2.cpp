#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct st
{
    ll val;
    int ind;
};
ll t,n,k;
st a[300000];
ll minmoves=1e15;
bool p=0;

void srch(ll str,ll nd)
{
    if(nd-str>=k)
        p=1;
    else
        return;
    ll moves=0,in,mid=(k+1)/2;
    for(int i=str;i<str+k;i++)
    {
        in=i-str+1;
        ll to_ind=a[str+mid-1].ind-mid+in;
        moves+=abs(a[i].ind-to_ind);
    }
    //cout<<"moves "<<moves<<endl;
    minmoves=min(moves,minmoves);

    for(int i=str+1;i<=nd-k;i++)
    {
        ll newe=i+k;
        moves-=a[i+mid-2].ind-mid+1-a[i-1].ind;
        //cout<<"moves = "<<moves<<endl;
        if(k%2==0)
        {
            moves-=a[i+mid-1].ind-a[i+mid-2].ind-1;
            moves+=a[newe-1].ind-(a[mid+i-1].ind+(k+1)/2);
        }
        else
            moves+=a[newe-1].ind-(a[mid+i-1].ind+(k+1)/2-1);

        //cout<<"moves "<<moves<<endl;
        minmoves=min(moves,minmoves);
    }
}

bool compare(st a,st b)
{
    if(a.val!=b.val)
        return a.val<b.val;
    return a.ind<b.ind;
}

int main()
{
    cin>>t;

    while(t--)
    {
        cin>>n>>k;
        p=0;
        minmoves=1e15;


        for(int i=0;i<n;i++)
        {
            cin>>a[i].val;
            a[i].ind=i;
        }

        sort(a,a+n,compare);


        ll str=0,nd,va,i=0;
        while(i<n)
        {
            va=a[i].val;
            while(a[i].val==va&&i<n)
                i++;
            nd=i;
            //cout<<"start "<<str<<" end "<<nd<<endl;
            srch(str,nd);
            str=i;
        }
        if(p)
            cout<<minmoves<<endl;
        else
            cout<<-1<<endl;
    }
}
