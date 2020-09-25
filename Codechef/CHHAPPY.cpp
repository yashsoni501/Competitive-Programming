#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;
ll t,n,a[100005],b[100005];

struct st
{
    ll ind;
    ll val;
    bool valid;
};

st str[100005];

bool compare(st a,st b)
{
    return a.val<b.val;
}

bool result()
{
    for(int i=0;i<n;i++)
    {
        if(!str[i].valid)
            continue;
        ll j=i+1;
        while(str[i].val==str[j].val)
        {
            if(str[j].valid)
                return true;

            j++;
            if(j==n)
                break;
        }
    }
    return false;
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
            str[i].ind=i+1;
            str[i].val=a[i];
        }

        sort(b,b+n);

        for(int i=0;i<n;i++)
        {
            if(binary_search(b,b+n,str[i].ind))
                str[i].valid=true;
            else
                str[i].valid=false;
        }
        sort(str,str+n,compare);

        if(result())
            cout<<"Truly Happy"<<endl;
        else
            cout<<"Poor Chef"<<endl;
    }
}
