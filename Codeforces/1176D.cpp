#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n;
ll b[1000000];
bool marked[1000000]={};
vector<ll> a;
ll prime[3000000];

bool predicate(ll mid,ll x)
{
    if(b[mid]>x || (b[mid]==x && marked[mid]))
        return 1;
    return 0;
}

void rem(ll x)
{
    ll low=0,high=2*n-1;
    ll mid=(low+high+1)/2;
    while(high-low>0)
    {
        //cout<<"high "<<high<<" mid "<<mid<<" low "<<low<<endl;
        if(predicate(mid,x))
        {
            high=mid-1;
        }
        else
        {
            low=mid;
        }
        mid=(high+low+1)/2;
    }
    //cout<<"value of mid "<<mid<<endl;
    marked[mid]=1;
}

bool sieve_prime[3000000]={};
ll sieve(ll *a,ll till) // inserts the primes from 2 to till in array 'a' and returns the size of the array
{
    ll size=0;
    for(int i=2;i<=till;i++)
    {
        if(sieve_prime[i])    continue;
        a[size++]=i;
        for(int j=i;j<=till;j+=i)
            sieve_prime[j]=1;
    }
    return size;
}

bool isprime(ll i,ll sz)
{
    return binary_search(prime,prime+sz,i);
}

int main()
{
    IOS
    cin>>n;
    REP(i,2*n)    cin>>b[i];
    ll sz = sieve(prime,2750131);
    //cout<<sz<<endl;
    //cout<<isprime(100,sz)<<endl;
    //cout<<"input taken"<<endl;
    sort(b,b+2*n);
    //cout<<"sorted"<<endl;
    for(int i=2*n-1;i>=0;i--)
    {
        if(marked[i])   continue;
        //marked[i]=1;
        if(isprime(b[i],sz))
        {
            a.push_back(lower_bound(prime,prime+sz,b[i])-prime+1);   
            //cout<<"pushing prime "<<i<<" "<<lower_bound(prime,prime+sz,b[i])-prime+1<<endl;
            rem(lower_bound(prime,prime+sz,b[i])-prime+1);
        }
        else
        {
            a.push_back(b[i]);
            ll sqt=sqrt(b[i])+1;
            for(int j=2;j<=sqt;j++)
            {
                if(b[i]%j==0)
                {
                    //cout<<"removing "<<b[i]/j<<endl;
                    rem(b[i]/j);
                    break;
                }
            }
        }
    }
    //REP(i,2*n)  cout<<marked[i]<<" ";
    //cout<<endl;
    sort(a.begin(),a.end());
    //cout<<"printing\n";
    REP(i,(ll)a.size())     cout<<a[i]<<" ";
    cout<<endl;
}
