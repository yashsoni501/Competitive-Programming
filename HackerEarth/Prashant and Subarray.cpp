#include<iostream>
#include<math.h>
using namespace std;

int arr[100000],b[100000]={},s[100000];
int n,q;
int binary(int k,int low,int high,int mi)
{
    //cout<<low<<" "<<high<<endl;
    if(high==low)
        return low;
    int mid=(high+low)/2;
    if(s[mid]-mi<k)
    {
        return binary(k,mid+1,high,mi);
    }
    else
        return binary(k,low,mid,mi);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int n;
    //int arr[n];
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    //int b[n];
    for(int i=0;i<n;i++)
    {
        int t=arr[i];
        while(t)
        {
            b[i]+=t%2;
            t/=2;
        }
    }
   // for(int i=0;i<n;i++)
     //   cout<<b[i]<<" ";
    //cout<<endl;
    //int s[n],sum=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=b[i];
        s[i]=sum;
    }
   ///// for(int i=0;i<n;i++)
   //     cout<<s[i]<<" ";
  //  cout<<endl;

    //int q;
    //cin>>q;
    while(q--)
    {
        int k;
        cin>>k;
        if(s[n-1]<k)
        {
            cout<<-1<<endl;
            continue;
        }
        int m=1e9;
        for(int i=0;i<n;i++)
        {
            if(i&&s[n-1]-s[i-1]<k)
                break;
            m=min(m,binary(k,i,n-1,i?s[i-1]:0)-i+1);
        }
        cout<<m<<endl;
    }

}
