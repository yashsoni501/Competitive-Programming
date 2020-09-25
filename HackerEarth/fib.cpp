#include<iostream>
#include<math.h>
using namespace std;


int arr[100000],b[100000]={},s[100000];
int n,q;
int binary(int k,int low,int high,int mi)
{
    cout<<low<<" "<<high<<endl;
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
    int t;
    long long int n;
    //int arr[n];
    cin>>t;
    while(t--)
    {
        long long int in=1000000007;
        cin>>n;
        double a=sqrt(5);
        double x=(1/a*(pow((a+1)/2,n)))-(1/a*(pow((1-a)/2,n)));
        int y=(long long int)(x+1)%in;
        cout<<y+1<<endl;
    }


}
