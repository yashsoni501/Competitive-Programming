#include<iostream>
using namespace std;

typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    ll arr[31600]={};
    for(int i=2;i<31600;i++)
    {
        for(int j=2*i;j<31600;j+=i)
        {
            arr[j]=1;
        }
    }

    int np=0;
    for(int i=2;i<31600;i++)
    {
        if(arr[i]==0)
        {
            np++;
        }
    }
    ll prime[np];
    np=0;
    for(int i=2;i<31600;i++)
    {
        if(arr[i]==0)
        {
            prime[np++]=i;
        }
    }
    ll t,n;
    cin>>t;
    /*
    for(int i=0;i<np;i++)
    {
        cout<<prime[i]<<" ";
    }
    cout<<endl;
    */
    while(t--)
    {
        ll f=0;
        cin>>n;
        ll ind=0;
        ll k=np-1;
        for(int i=1;i<np/2;i++)
        {
            if(f==(n-2))
                break;
            cout<<prime[ind%k]*prime[(ind+i)%k]<<" ";
            f++;
            ind=(ind+i)%k;
            while(ind!=0)
            {
                if(f==(n-2))
                    break;
                cout<<prime[ind%k]*prime[(ind+i)%k]<<" ";
                f++;
                ind=(ind+i)%k;
            }
        }
        cout<<prime[ind]*prime[np-1]<<" ";
        cout<<prime[np-1]*prime[0]<<endl;
    }
}
