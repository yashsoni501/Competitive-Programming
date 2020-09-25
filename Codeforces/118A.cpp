#include<iostream>
using namespace std;

int main()
{
    string a;
    char b[200];
    cin>>a;
    int len=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>97&&a[i]<123&&a[i]!='e'&&a[i]!='i'&&a[i]!='o'&&a[i]!='u'&&a[i]!='y')
        {
            b[len++]='.';
            b[len++]=a[i];

        }
        else if(a[i]>'A'&&a[i]<='Z'&&a[i]!='E'&&a[i]!='I'&&a[i]!='O'&&a[i]!='U'&&a[i]!='Y')
        {
            b[len++]='.';
            b[len++]=a[i]+32;
        }
    }
    b[len]='\0';
    cout<<b<<endl;
}
