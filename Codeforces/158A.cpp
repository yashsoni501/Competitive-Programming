#include<iostream>
using namespace std;;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[50];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int t=k-1,val=a[k-1];
    if(val>0)
    {
        while(a[t]==val&&a[t]>0)
            t++;
        cout<<t<<endl;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]<=0)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
}
