#include<iostream>
using namespace std;

int main()
{
    string str;
    cin>>str;

    int len=0;
    for(len=0;str[len]!='\0';len++);


    int ind=(len-1)/2;
    //cout<<str[ind];
    for(int i=0;i<len;i++)
    {
        ind=(i%2)?(ind+i):(ind-i);
        cout<<str[(i%2)?(ind):(ind)];
    }
    cout<<endl;
}
