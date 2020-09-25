#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int k,n;
    cin>>n>>k;
    long long int minx=1000000000;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            int j=n/i;
            if(i<k)
                minx=min((int)minx,i+j*k);
            if(j<k)
                minx=min((int)minx,j+i*k);
        }
    }
    cout<<minx<<endl;
}
