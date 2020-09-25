#include<iostream>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int i=0;
    bool b=0;
    while(true)
    {
        if(a[i]=='\0')
            break;
        char cur=a[i];
        int cnt=0;
        while(a[i]==cur)
        {
            if(a[i]=='\0')
                break;
            cnt++;
            i++;
        }
        if(cnt>6)
        {
            b=1;
            break;
        }
    }
    if(b)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
