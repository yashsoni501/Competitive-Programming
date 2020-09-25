#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    long double n,m,a;
    cin>>n>>m>>a;
    a+=0.0;
    long long int t=ceil(n/a)*ceil(m/a);
    cout<<t<<endl;
    return 0;
}
