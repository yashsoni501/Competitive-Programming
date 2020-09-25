#include<iostream>
using namespace std;

typedef long long int ll;
ll n;

struct node
{
   // bool stat;
    int n1;
    int n2;
};

node arr[1000000];
int x1,x2;

void connecter(int i,int j)
{
    if(arr[i].n1==NULL)
    {
        arr[i].n1=j;
    }
    else
    {
        arr[i].n2=j;
    }

    if(arr[j].n1==NULL)
    {
        arr[j].n1=i;
    }
    else
    {
        arr[j].n2=i;
    }
}

void print()
{
    cout<<1<<" ";
    int prev=0;
    int ind=0;
    if(arr[ind].n2==(x1-1)||arr[ind].n2==(x2-1))
        ind=arr[ind].n2;
    else
        ind=arr[ind].n1;
    for(int i=1;i<n;i++)
    {
        cout<<ind+1<<" ";
        int tmp=ind;
        if(arr[ind].n2==prev)
        {
            //cout<<arr[ind].n1+1<<" ";
            ind=arr[ind].n1;
        }
        else
        {
            //cout<<arr[ind].n2+1<<" ";
            ind=arr[ind].n2;
        }
        prev=tmp;
    }
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        //arr[i].stat=0;
        arr[i].n1=NULL;
        arr[i].n2=NULL;
    }

    int x,y;

    cin>>x1>>x2;
    connecter (x1-1,x2-1);
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        connecter(x-1,y-1);
    }
/*
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" "<<arr[i].n1+1<<" "<<arr[i].n2+1<<endl;
    }
*/
    print();

}
