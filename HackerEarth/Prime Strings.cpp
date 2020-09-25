#include<iostream>
using namespace std;

int l(string s)
{
    int t;
    for(t=0;s[t]!='\0';t++);
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;

    bool arr[1000000]={};
    int cnt=0;
    for(int i=2;i<1000000;i++)
    {
        if(arr[i])
        {
            continue;
        }
        cnt++;
        for(int j=2*i;j<1000000;j+=i)
        {
            arr[j]=1;
        }
    }
    //cout<<"here"<<endl;
    //cout<<cnt<<endl;
    int prime[cnt];
    int ind=0;
    /*for(int i=2;i<25;i++)
    {
        cout<<i<<" "<<arr[i]<<endl;
    }*/
    for(int i=2;i<1000000;i++)
    {
        if(!arr[i])
            prime[ind++]=i;
    }
    //cout<<"here"<<endl;
    cin>>t;
    while(t--)
    {
        int len;
        cin>>len;
        string s;
        cin>>s;
//        int len=l(s);
        for(int i=0;prime[i]<=len;i++)
        {
            cout<<s[prime[i]-1];
        }
        cout<<endl;
    }

}
