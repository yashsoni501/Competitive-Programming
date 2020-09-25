#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void adda(ll ar[],ll howmany,int ind)
{
    while(howmany)
    {
        if(ind==0||ind==3||ind==6)
        {
            ar[ind]++;
            howmany--;
        }
        ind++;
        if(ind==7)
            ind=0;
    }
}

void addb(ll ar[],ll howmany,int ind)
{
    while(howmany)
    {
        if(ind==1||ind==5)
        {
            ar[ind]++;
            howmany--;
        }
        ind++;
        if(ind==7)
            ind=0;
    }
}

void addc(ll ar[],ll howmany,int ind)
{
    while(howmany)
    {
        if(ind==2||ind==4)
        {
            ar[ind]++;
            howmany--;
        }
        ind++;
        if(ind==7)
            ind=0;
    }
}

int main()
{
    ll a,b,c;
    cin>>a>>b>>c;

    ll weeks=min(a/3,min(b/2,c/2));
    ll ar[7]={0,0,0,0,0,0,0};
    ll lea=a-3*weeks,leb=b-2*weeks,lec=c-2*weeks;
    ll arr[14];
    ll days=0;

    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
            ar[j]=0;
        adda(ar,min(lea,(ll)3),i);
        addb(ar,min(leb,(ll)2),i);
        addc(ar,min(lec,(ll)2),i);

        for(int j=0;j<14;j++)
            arr[j]=0;
        for(int j=0;j<7;j++)
        {
            arr[j]=arr[7+j]=ar[j];
        }

        ll ma=0;
        ll j=i;
        if(arr[j+1])
        {
            while(j<14&&arr[j])
            {
                ma++;
                j++;
            }
        }

        days=max(ma,days);
        //cout<<days<<endl;
    }
    cout<<7*weeks+days<<endl;
}
