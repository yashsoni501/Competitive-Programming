#include<iostream>
using namespace std;

int main()
{
    int n;
    string a;
    cin>>n>>a;
    int val,ind,cnt=0;

    for(int i=0;i<n-1;i++)
    {
        ind=i+1;
        while(a[ind]==a[i])
        {
            cnt++;
            ind++;
            if(ind==n)
                break;
        }
        i=ind-1;
    }
    cout<<cnt<<endl;
}
