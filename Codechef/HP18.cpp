#include <iostream>
using namespace std;

int main()
{
    int t,a,b,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int fav_a=0,fav_b=0,fav_ab=0;
        for(int i=0;i<n;i++)
        {
            if(!(arr[i]%a||arr[i]%b))
            {
                fav_ab++;
            }
            else if(arr[i]%a==0)
            {
                fav_a++;
            }
            else if(arr[i]%b==0)
            {
                fav_b++;
            }
        }
        if(fav_ab)
            fav_a++;
        if(fav_a>fav_b)
        {
            cout<<"BOB"<<endl;
        }
        else
        {
            cout<<"ALICE"<<endl;
        }
    }
}
