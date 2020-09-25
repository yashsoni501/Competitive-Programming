#include<bits/stdc++.h>
using namespace std;

#define INF 1e18
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;
ll te,t,A;
char c[256][510];
string ans;
bool pssble;

struct node
{
    map<char,bool> c;
    node *r,*s,*p;
};
node *head;

node *getnode()
{
    node *t=new node;
    t->c['R']=t->c['S']=t->c['P']=0;
    t->r=t->s=t->p=NULL;
    return t;
}

void push(char *str)
{
    node *t=head;
    ll len=strlen(str);
    
    for(int i=0;i<500;i++)
    {
        ll ind = i % len;
        if(!(t->c['R']))
        {
            t->r=getnode();
        }
        if(!(t->c['S']))
        {
            t->s=getnode();
        }
        if(!(t->c['P']))
        {
            t->p=getnode();
        }
        t->c[str[ind]]=1;
        
        if(str[ind]=='R')
           t=t->r;
        else if(str[ind]=='S')
           t=t->s;
        else if(str[ind]=='P')
           t=t->p;
    }
}

void solve()
{
    node *h=head;
    for(int i=0;i<500;i++)
    {
        if(!h)
        {
            cout<<1/0<<endl;
            return;
        }
        if(h->c['R'] && h->c['S'] && h->c['P'])
        {
            pssble=0;
            return;
        }
        if(h->c['R'] && h->c['S'])
        {
            ans+='R';
            h=h->r;
        }
        else if(h->c['P'] && h->c['S'])
        {
            ans+='S';
            h=h->s;
        }
        else if(h->c['R'] && h->c['P'])
        {
            ans+='P';
            h=h->p;
        }
        else if(h->c['R'])
        {
            ans+='P';
            return;
        }
        else if(h->c['P'])
        {
            ans+='S';
            return;
        }
        else if(h->c['S'])
        {
            ans+='R';
            return;
        }
        else
        {
            pssble=0;
            return;
        }
    }
}

int main()
{
    IOS
    cin>>te;
    for(t=1;t<=te;t++)
    {
        ans="";
        head=getnode();
        
        pssble=1;
        cin>>A;
        for(int i=0;i<A;i++)
        {
            cin>>c[i];
            push(c[i]);
        }

        solve();
        if(pssble)
        {
            cout<<"Case #"<<t<<": "<<ans<<endl;
        }
        else
        {
            cout<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<endl;
        }
        
    }
}