#include<iostream>
#include<algorithm>
using namespace std;

typedef int ll;
ll t,n,a[100005],b[100005];

struct st
{
    ll ind;
    ll val;
    bool v;
};
st str[100005];

bool compare(st a,st b)
{
    if(a.val!=b.val)
        return a.val<b.val;
    return a.ind<b.ind;
}

bool res()
{
    for(int i=0;i<n;i++)
    {
        if(!str[i].v)
            continue;
        ll j=i+1;
        while(str[i].val==str[j].val)
        {
            if(str[j].v)
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
        sort(str,str+n,compare);
        sort(b,b+n);

        for(int i=0;i<n;i++)
        {
            if(binary_search(b,b+n,str[i].ind))
                str[i].v=true;
            else
                str[i].v=false;
        }

        cout<<endl<<"Printing ";
        for(int i=0;i<n;i++)
        {
            cout<<str[i].val<<" ";
        }
        cout<<endl;

        cout<<endl<<"Printing ";
        for(int i=0;i<n;i++)
        {
            cout<<str[i].ind<<" ";
        }
        cout<<endl;

        cout<<endl<<"Printing ";
        for(int i=0;i<n;i++)
        {
            cout<<(int)str[i].v<<" ";
        }
        cout<<endl;

        if(res())
            cout<<"Truly Happy"<<endl;
        else
            cout<<"Poor Chef"<<endl;
    }
}
