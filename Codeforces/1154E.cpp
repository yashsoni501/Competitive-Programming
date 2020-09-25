#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct node
{
    ll sk,ind;
};

struct nody
{
    nody *next,*prev;
    ll data,ind;
};

void del(nody *tail)
{
    if(tail->prev)
        (tail->prev)->next=tail->next;
    if(tail->next)
        (tail->next)->prev=tail->prev;
}

void insert(nody **tail,ll da,ll in,nody *place[])
{
    nody *t=new nody();
    t->data=da;
    t->ind=in;
    place[in]=t;
    if(!(*tail))
    {
        t->next=NULL;
        t->prev=NULL;
        *tail=t;
    }
    else
    {
        t->next=NULL;
        (*tail)->next=t;
        t->prev=*tail;
        *tail=t;
    }
}

nody *head=NULL;

bool comp(node a,node b)
{
    return a.sk<b.sk;
}

ll index;

ll find(node a[],ll ar[][2],ll n)
{
    for(int i=index-1;i>=0;i--)
    {
        if(!ar[a[i].ind][1])
        {
            index=i;
            return a[i].ind;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,k;
    cin>>n>>k;
    node a[n];
    ll ar[n][2];
    nody *place[n];
    nody *tail=head;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i][0];
        ar[i][1]=0;
        a[i]={ar[i][0],i};
        insert(&tail,ar[i][0],i,place);
    }
    index=n;
    sort(a,a+n,comp);
    ll cnt=0,team=0;
    place[n-1]->next=NULL;
    place[0]->prev=NULL;

    while(cnt<n)
    {
        ll tmp=find(a,ar,n);
        //cout<<"tmp "<<tmp<<endl;
        ll cnting=0;
        for(nody *p=place[tmp];cnting<k+1&&p;p=p->next)
        {
            if(!p)
                break;
            //cout<<"place "<<p->ind<<endl;
            ll i=p->ind;
            if(!ar[i][1])
            {
                ar[i][1]=team%2+1;
                cnt++;
                cnting++;
                del(p);
            }
        }

        cnting=0;
        for(nody *p=place[tmp-1];tmp-1>=0&&cnting<k&&p;p=p->prev)
        {
            if(!p)
                break;
            //cout<<"place "<<p->ind<<endl;
            ll i=p->ind;
            //cout<<"team "<<team<<" i "<<i<<endl;
            if(!ar[i][1])
            {
                ar[i][1]=team%2+1;
                cnt++;
                cnting++;
                del(p);
            }
        }
        //cout<<"cnting "<<cnting<<" team "<<team<<endl;
        team++;

    }

    for(int i=0;i<n;i++)
    {
        cout<<ar[i][1];
    }
    cout<<endl;
}
