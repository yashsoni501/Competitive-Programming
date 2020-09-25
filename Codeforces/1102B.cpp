#include<iostream>
#include<algorithm>
using namespace std;

struct a
{
    int num;
    int pos;
};

bool comp(a m,a n)
{
    return m.num<n.num;
}

int n,k;
int main()
{
    cin>>n>>k;
    a arr[n];
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr[i].num=temp;
        arr[i].pos=i;
    }
    sort(arr,arr+n,comp);
    int macnt=0;
    for(int i=0;i<n;i++)
    {
        int tmp=arr[i].num;
        int cnt=0;
        bool c=0;
        while(arr[i].num==tmp)
        {
            c=1;
            cnt++;
            i++;
            if(i==n)
                break;
        }
        if(c)
        {
            i--;
        }
        //cout<<cnt<<" ";
        macnt=max(macnt,cnt);
    }
    //cout<<endl;
    if(macnt>k)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    int ar[n];
    for(int i=0;i<n;i++)
    {
        ar[arr[i].pos]=i%k+1;
    }

    cout<<"YES"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
