#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);
    int t;
    long long int n,temp;
    cin>>t;
    long long int pow[24];

    pow[0]=1;
    for(int i=1;i<24;i++)
    {
        pow[i]=5*pow[i-1];
    }
    //cout<<pow[22]<<" "<<pow[23]<<endl;

    while(t--)
    {
        cin>>n;
        int cnt=0;
        temp=n;
        while(temp)
        {
            cnt++;
            temp/=5;
        }
        temp=n;
        cnt++;
        int arr[cnt];
        for(int i=0;i<cnt;i++)
        {
            arr[i]=temp%5;
            temp/=5;
        }
        arr[cnt-1]=0;
        if(n<2147483647)
        {
            int left[cnt],right[cnt],li=0,ri=0;
            for(int i=0;i<cnt;i++)
            {
                if(arr[i]==1)
                {
                    right[ri++]=pow[i];
                }
                else if(arr[i]==2)
                {
                    right[ri++]=pow[i];
                    right[ri++]=pow[i];
                }
                else if(arr[i]==3)
                {
                    left[li++]=pow[i];
                    left[li++]=pow[i];
                    arr[i+1]++;
                }
                else if(arr[i]==4)
                {
                    left[li++]=pow[i];
                    arr[i+1]++;
                }
                else if(arr[i]==5)
                {
                    arr[i]=0;
                    arr[i+1]++;
                }
            }
            if(li==0)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<li<<endl;
                for(int i=0;i<li;i++)
                {
                    cout<<left[i]<<" ";
                }
                cout<<endl;
            }
            if(ri==0)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<ri<<endl;
                for(int i=0;i<ri;i++)
                {
                    cout<<right[i]<<" ";
                }
                cout<<endl;
            }
        }
        else
        {
            long long int left[cnt],right[cnt],li=0,ri=0;
            for(int i=0;i<cnt;i++)
            {
                if(arr[i]==1)
                {
                    right[ri++]=pow[i];
                }
                else if(arr[i]==2)
                {
                    right[ri++]=pow[i];
                    right[ri++]=pow[i];
                }
                else if(arr[i]==3)
                {
                    left[li++]=pow[i];
                    left[li++]=pow[i];
                    arr[i+1]++;
                }
                else if(arr[i]==4)
                {
                    left[li++]=pow[i];
                    arr[i+1]++;
                }
                else if(arr[i]==5)
                {
                    arr[i]=0;
                    arr[i+1]++;
                }
            }
            if(li==0)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<li<<endl;
                for(int i=0;i<li;i++)
                {
                    cout<<left[i]<<" ";
                }
                cout<<endl;
            }
            if(ri==0)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<ri<<endl;
                for(int i=0;i<ri;i++)
                {
                    cout<<right[i]<<" ";
                }
                cout<<endl;
            }

        }

    }

}
