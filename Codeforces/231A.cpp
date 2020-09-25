#include<iostream>
using namespace std;

int main()
{
    int t,a,b,c;
    int cnt=0;
    cin>>t;
    while(t--)
    {
        a=0;
        for(int i=0;i<3;i++)
        {
            cin>>b;
            if(b)
                a++;
        }
        if(a>1)
            cnt++;
    }
    cout<<cnt<<endl;
}
