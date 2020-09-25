#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll q,a,b,m;
ll ar[50];
ll p2[51];
ll lowb[50];
ll upb[50];

int main()
{
    IOS
    p2[0] = 1;
    p2[1] = 1;
    FOR(i,2,51,1)
    {
        p2[i] = 2*p2[i-1];
    }
    /*REP(i,51)
    {
        cout<<p2[i]<<endl;
    }
    cout<<endl;
    cout<<"lower bound 3: "<<*lower_bound(p2,p2+51,7)<<endl;*/
    cin>>q;
    while(q--)
    {
        cin>>a>>b>>m;
        if(a==b)
        {
            cout<<1<<" "<<a<<endl;
            return 0;
        }
        ar[0] = a;
        ar[1] = a;
        ll k=-1;
        ll toAdd;
        ll upbnd=0; // max value of k;
        for(int i=2;i<50;i++)
        {
            ar[i] = ar[i-1]*2;
            if(ar[i]>b)
            {
                upbnd=i;
            }
        }

        for(int i=1;i<upbnd;i++)
        {
            ll minp = p2[i];
            ll maxp = minp*m;
            if(maxp < minp)
            {
                maxp = 1e14;
            }
            if(b>=ar[i]+minp && b<=ar[i]+maxp)
            {
                k = i+1;
                toAdd = b-ar[i]-minp;
                ar[i]+=minp;
                break;
            }
            else if(b<ar[i]+minp)
            {
                ar[i]+=minp;
                break;
            }
            ar[i]+=minp;
        }
        for(int i=0;i<k;i++)
        {
            cout<<ar[i]<<endl;
        }
        cout<<endl;
        if(k==-1)
        {
            cout<<-1<<endl;
            return 0;
        }
        //ll t=k-1;
        cout<<"k "<<k<<endl;
        cout<<"toadd "<<toAdd<<endl;
        while(toAdd>m)
        {
            cout<<toAdd<<endl;
            ll t=lower_bound(p2,p2+51,toAdd+1)-p2-1;
            cout<<"t "<<t<<endl; 
            ar[k-t]++;
            for(int i=k-t+1;i<k;i++)
            {
                ar[i]+=p2[i-k+t-1];
            }
            toAdd-=*(lower_bound(p2,p2+50,toAdd+1)-1);
            cout<<"lower "<<*(lower_bound(p2,p2+51,toAdd+1)-1)<<endl;
        }
        cout<<"toAdd "<<toAdd<<endl;
        if(toAdd)
        {
            ar[k-1]+=toAdd;
        }
        cout<<k<<" ";
        for(int i=0;i<k;i++)
        {
            cout<<ar[i]<<" ";
        }
        cout<<endl;
    }    
}   