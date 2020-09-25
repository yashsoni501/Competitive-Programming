#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ind=0;
    for(int i=1;ind<n;i++)
    {
        cout<<s[ind];
        ind+=i;
    }
}
