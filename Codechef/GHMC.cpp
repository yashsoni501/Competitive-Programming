#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;
ll t,n,k,x,d;
ll arr[100005];

ll mini()
{
    ll m=10000000000;
    for(int i=0;i<k;i++)
        if(arr[i]<m)
            m=arr[i];
    return m;
}

bool chek()
{
    ll *ps=arr;
    ll *pe=arr+k;
    sort(ps,pe);
    ll tmp=min(mini()+d,x);
    if(tmp<n){
        //cout<<"here"<<endl;
        return true;}
    if(arr[k-1]>x)
        return true;
    if(arr[k-1]-arr[0]>d)
        return true;
    return false;
}

ll su(ll mi)
{
    ll s=0;
    for(int i=0;i<k;i++)
        s+=arr[i];
    ll tmp=min(mi+d,x);
    for(int i=k;i<n;i++)
    {
        while(binary_search(arr,arr+k,tmp))
        {
            tmp--;
        }
        s+=tmp;
        tmp--;
    }
    return s;
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>x>>d;
        for(int i=0;i<k;i++)
        {
            cin>>arr[i];
        }
        if(chek())
        {
            cout<<-1<<endl;
        }
        else{
            ll mi=mini();
            ll sum=su(mi);
            cout<<sum<<endl;
        }
    }
}
