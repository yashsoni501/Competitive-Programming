#include<iostream>
using namespace std;

typedef long long int ll;

ll l,r,k,m;
ll ar[9];

ll recur(ll num,int iter,int len,int order)
{
    ll num2=num;
    for(int i=iter+1;i<19;i++)
        num2*=10;

    if((l>num2||r<num2)&&num!=0)
        return 0;
    if(iter>18)
    {
        ll arr[9]={};
        while(num)
        {
            arr[num%10]=1;
            num/=10;
        }
        for(int i=0;i<m;i++)
        {
            if(arr[ar[i]]==0)
                return 0;
        }
        return 1;
    }

    ll ans=0;
    for(int i=1;i<=9;i++)
    {

        if(i < num%10)
        {
            if(order==1&&len<=k)
            {
                ans+=recur(10*num+i,iter+1,len+1,1);
//                ans+=recur(10*num+i,iter+1,1,0);
            }
            else
            {
                ans+=recur(10*num+i,iter+1,2,0);
            }
        }
        if(i>num%10)
        {
            if(order==0&&len<=k)
            {
                ans+=recur(10*num+i,iter+1,len+1,0);
//                ans+=recur(10*num+i,iter+1,1,0);
            }
            else
            {
                ans+=recur(10*num+i,iter+1,2,1);
            }
        }
    }
    return ans;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>ar[m];
        }
        cin>>k>>l>>r;
        ll ans=recur((ll)0,0,0,0);
        ans+=recur(0,0,0,1);
        cout<<ans<<endl;
    }
}
