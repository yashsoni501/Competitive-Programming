#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

typedef long long int ll;
ll t,n,a[100005],maxi=0;

bool isprime(ll x)
{
    for(int i=2;i<sqrt(x);i++)
        if(x%i)
            return false;
    return true;
}

void solve(ll *c,ll x)
{
    if(x==0)
        return;


    /*for(int i=0;i<x;i++)
        cout<<c[i]<<" ";
    cout<<endl<<"x "<<x<<endl;
*/
    ll prm[100];
    ll prl=0;
    if(c[0]%2==0)
        prm[prl++]=2;
    for(ll i=3;i<=c[0];i+=2)
    {
        if(!(c[0]%i))
            if(isprime(i))
                prm[prl++]=i;
    }

    ll nu=prl; // nu=number of common prime
    for(int i=0;i<prl;i++)
    {
        bool tr=false;
        for(int j=0;j<x;j++)
        {
            if(c[j]%prm[i]!=0)
            {
                tr=true;
                //cout<<"lkaslasdhjflkjdsjhfklasdjlksdjfklsdfasdfasdfsadfas"<<endl;
                break;
            }
        }
        if(tr)
            nu--;
    }

   // cout<<"NU "<<nu<<" "<<prm[0]<<endl;
    maxi=max(nu*x,maxi);
 //   cout<<"maxi "<<maxi<<endl;
}

void generatee(ll *ar,ll step,ll len)
{
    if(step==n)
        solve(ar,len);
    else
    {
        ll ar1[len+1],ar2[len];
        for(int i=0;i<len;i++)
        {
            ar1[i]=ar[i];
            ar2[i]=ar[i];;
        }
        ar1[len]=a[step];
       // cout<<"Step"<<step<<endl;
        generatee(ar2,step+1,len);
        generatee(ar1,step+1,len+1);
    }
}

int main()
{
    cin>>t;
    while(t--)
    {
        ll c[100004];
        cin>>n;
        ll tmp;
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
        }

        ll k=0;
        for(int i=0;i<n;i++)
            if(c[i]!=1)
                a[k++]=c[i];
        n=k;

        sort(a,a+n);

     //   cout<<"n "<<n<<endl;
     //   for(int i=0;i<n;i++)
       //     cout<<a[i]<<" ";
       // cout<<endl;
        ll b[100]={};
        generatee(b,0,0);
        cout<<maxi<<endl;
    }
}
