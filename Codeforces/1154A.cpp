#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll a[4];
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    sort(a,a+4);
    for(int i=0;i<3;i++)
    {
        cout<<a[3]-a[i]<<" ";
    }
    cout<<endl;


}
