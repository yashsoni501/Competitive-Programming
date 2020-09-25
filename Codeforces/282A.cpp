#include<iostream>
using namespace std;

int main()
{
    int t,cnt=0;
    cin>>t;
    while(t--)
    {
        char a[4];
        cin>>a;
        //cout<<a<<endl;
        if(a[0]=='+'||a[2]=='+')
            cnt++;
        else
            cnt--;
    }
    cout<<cnt;
}
