#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
    int day,prob;
};
bool comp(node a,node b)
{
    return a.day<b.day;
}

int main()
{
    int t,d,q;
    cin>>t;
    while(t--)
    {
        cin>>d;
        node arr[d+1];
        for(int i=0;i<d;i++)
        {
            cin>>arr[i].day>>arr[i].prob;
        }
        arr[d]={0,0};
        sort(arr,arr+d+1,comp);
        cin>>q;
        int sum=0;
        for(int i=0;i<d+1;i++)
        {
            sum+=arr[i].prob;
            arr[i].prob=sum;
        }
        int dead, req;
/*
        cout<<"printing"<<endl;

        for(int i=0;i<d+1;i++)
        {
            cout<<arr[i].day<<" "<<arr[i].prob<<endl;
        }

        cout<<"comp printing"<<endl;*/
        while(q--)
        {
            cin>>dead>>req;
            for(int i=1;i<d+1;i++)
            {
                if(arr[i].day>dead)
                {
                    if(arr[i-1].prob>=req)
                        cout<<"Go Camp"<<endl;
                    else
                        cout<<"Go Sleep"<<endl;
                    break;
                }
            }
            if(dead>=arr[d].day)
            {
                if(arr[d].prob>=req)
                    cout<<"Go Camp"<<endl;
                else
                    cout<<"Go Sleep"<<endl;
            }
        }
    }
}
