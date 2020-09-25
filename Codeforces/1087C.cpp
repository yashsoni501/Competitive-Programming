#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

struct node
{
    int i,j;
};

stack<node> st;

bool sl(node a,node b)
{
    if(a.i==b.i||a.j==b.j)
        return true;
    return false;
}

int mandi(node a,node b)
{
    return abs(a.i-b.i)+abs(a.j-b.j);
}

void print(node a)
{
    cout<<a.i<<" "<<a.j<<endl;
}

void connect(node a,node b)
{
    if(a.i==b.i)
    {
        for(int x=min(a.j,b.j)+1;x<max(a.j,b.j);x++)
        {
            node tmp={a.i,x};
            st.push(tmp);
        }
    }
    else if(a.j==b.j)
    {
        for(int x=min(a.i,b.i)+1;x<max(a.i,b.i);x++)
        {
            node tmp={x,a.j};
            st.push(tmp);
        }
    }
    else{
        node tmp={b.i,a.j};
        st.push(tmp);
        connect(a,tmp);
        connect(tmp,b);
    }
}

int main()
{
    node a,b,c;
    cin>>a.i>>a.j;
    cin>>b.i>>b.j;
    cin>>c.i>>c.j;

    st.push(a);
    st.push(b);
    st.push(c);

    if(a.i==b.i&&b.i==c.i)
    {
        if(a.j<b.j<c.j||a.j>b.j>c.j)
        {
            connect(a,b);
            connect(b,c);
        }
        else if(b.j<a.j<c.j||b.j>a.j>c.j)
        {
            connect(a,b);
            connect(a,c);
        }
        else
        {
            connect(c,b);
            connect(a,c);
        }
    }
    else if(a.j==b.j&&b.j==c.j)
    {
        if(a.i<b.i<c.i||a.i>b.i>c.i)
        {
            connect(a,b);
            connect(b,c);
        }
        else if(b.i<a.i<c.i||b.i>a.i>c.i)
        {
            connect(a,b);
            connect(a,c);
        }
        else
        {
            connect(c,b);
            connect(a,c);
        }
    }
    else if(sl(a,b)&&sl(a,c))
    {
        connect(a,b);
        connect(a,c);
        //goto done;
    }
    else if(sl(a,b)&&sl(b,c))
    {
        connect(a,b);
        connect(b,c);
        //goto done;
    }
    else if(sl(a,c)&&sl(b,c))
    {
        connect(a,c);
        connect(b,c);
        //goto done;
    }
    else{
    node r[9];
    r[0].i=a.i;
    r[1].i=a.i;
    r[2].i=b.i;
    r[3].i=b.i;
    r[4].i=c.i;
    r[5].i=c.i;

    r[0].j=b.j;
    r[1].j=c.j;
    r[2].j=a.j;
    r[3].j=c.j;
    r[4].j=a.j;
    r[5].j=b.j;

    r[6]=a;
    r[7]=b;
    r[8]=c;


    int md=100000;
    int ind=-1;
    for(int i=0;i<9;i++)
    {
        int dis=mandi(a,r[i])+mandi(b,r[i])+mandi(c,r[i]);
        if(dis<md)
        {
            md=dis;
            ind=i;
        }
    }

    if(ind<6)
    {
        st.push(r[ind]);
    }

    connect(a,r[ind]);
    connect(b,r[ind]);
    connect(c,r[ind]);
    //cout<<"Manhatton Dist "<<md<<endl;
    //cout<<"connector ";
    //print(r[ind]);
    }

    cout<<st.size()<<endl;
    while(!st.empty())
    {
        node tmp=st.top();
        st.pop();
        print(tmp);
    }
}
