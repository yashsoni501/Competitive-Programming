#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
    char a[105],b[105];
    int l;
    cin>>a>>b;
    for(l=0;a[l]!='\0';l++)
    {
        if(isupper(a[l]))
            a[l]=tolower(a[l]);
    }
    for(l=0;b[l]!='\0';l++)
    {
        if(isupper(b[l]))
            b[l]=tolower(b[l]);
    }
    if(strcmp(a,b)<0)
        cout<<-1<<endl;
    else if(strcmp(a,b)==0)
        cout<<0<<endl;
    else
        cout<<1<<endl;
}
