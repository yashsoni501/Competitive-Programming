#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll m,n,h;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>h;
    ll top[n][m];
    ll front[m];
    ll left[n];
    ll obj[n][m];
    for(int i=0;i<m;i++)
    {
        cin>>front[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>left[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>top[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(top[i][j]==0)
            {
                obj[i][j]=0;
            }
            else
            {
                obj[i][j]=min(left[i],front[j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<obj[i][j]<<" ";
        }
        cout<<endl;
    }
}