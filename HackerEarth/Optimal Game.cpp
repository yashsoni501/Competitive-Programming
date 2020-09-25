#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;

    char arr[1000001];
    arr[1]='P';
    for(int i=2;i<=1000000;i++)
    {
        if(arr[i/2]=='P'||arr[(i+1)/2]=='P')
            arr[i]='R';
        else
            arr[i]='P';
    }
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        if(arr[x]=='R')
            cout<<"Ritik"<<endl;
        else
            cout<<"Prashant"<<endl;
    }

}
