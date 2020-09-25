#include<bits/stdc++.h>
using namespace std;

int strlen(string a)
{
    int l=0;
    for(l=0;a[l]!='\0';l++);
    return l;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string arr[n];
        int len[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            len[i]=strlen(arr[i]);
            sort(arr[i].begin(),arr[i].end());
        }
        int c=0;
        for(int i=0;i<len[0];i++)
        {
            bool bolo=true;
            if(i&&arr[0][i]==arr[0][i-1])
                continue;
            for(int j=1;j<n;j++)
            {
                if(!binary_search(arr[j].begin(),arr[j].end(),arr[0][i]))
                    bolo=false;
            }
            if(bolo)
                c++;
        }
        cout<<c<<endl;
    }
}
