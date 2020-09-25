#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ma=0,maind=-1;
    int mi=1000000,mind=-1;

    for(int i=0;i<n;i++)
    {
        if(a[i]>ma)
        {
            ma=a[i];
            maind=i;
        }
        if(a[i]<mi)
        {
            mi=a[i];
            mind=i;
        }
    }

    int ma2=0,mi2=1000000;
    for(int i=0;i<n;i++)
    {
        if(a[i]>ma2&&i!=maind)
        {
            ma2=a[i];
        }
        if(a[i]<mi2&&i!=mind)
        {
            mi2=a[i];
        }
    }
    cout<<min(ma-mi2,ma2-mi);
}
