#include<iostream>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        char a[100];
        cin>>a;
        for(n=0;a[n]!='\0';n++);
        if(n<11)
            cout<<a<<endl;
        else
        {
            cout<<a[0]<<n-2<<a[n-1]<<endl;
        }
    }
}
