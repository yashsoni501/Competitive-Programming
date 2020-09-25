#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long int ll;
ll n,k;
struct chap
{
    int l,r;
};
chap a[100];

bool comp(chap a,chap b)
{
    return a.l<b.l;
}

int l[100],r[100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
    }
    cin>>k;
    sort(l,l+n);
    int *t=lower_bound(l,l+n,k);
    int t2=t-l;
    if(l[t2]==(ll)k)
        cout<<n-t2<<endl;
    else
        cout<<n-t2+1<<endl;
}
