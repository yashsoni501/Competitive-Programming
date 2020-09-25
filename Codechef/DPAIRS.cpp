#include<iostream>
#include<algorithm>
using namespace std;

struct st
{
    int num;
    int ind;
};

bool sorting(st a,st b)
{
    return a.num<b.num;
}


int main()
{
    int n,m,tmp;
    cin>>n>>m;
    st a_n[n],a_m[m];
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        a_n[i]={tmp,i};
    }
    for(int i=0;i<m;i++)
    {
        cin>>tmp;
        a_m[i]={tmp,i};
    }

    sort(a_n,a_n+n,sorting);
    sort(a_m,a_m+m,sorting);

    for(int i=0;i<m;i++)\
    {
        cout<<a_n[0].ind<<" "<<a_m[i].ind<<endl;
    }
    for(int i=1;i<n;i++)
    {
        cout<<a_n[i].ind<<" "<<a_m[m-1].ind<<endl;
    }
}
