#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long int ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    cout<<3*n+min(k-1,n-k)<<endl;

}
