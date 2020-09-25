#include<bits/stdc++.h>
using namespace std;

#define INF 1e18
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;
ll t,f,te;
map<string,bool> perm;

bool isvalid(string s)
{
    char st[6];
    for(int i=0;i<5;i++)
    {
        st[i]=s[i];
    }
    sort(st,st+5);
    for(int i=0;i<5;i++)
    {
        if(st[i]==st[i+1])
            return 0;
    }
    return 1;
}

char charac(int i)
{
    return i+64;
}

void push(string s,int ind)
{
    if(ind==4)
    {
        if(isvalid(s))
            perm[s]=0;
        return;
    }
    for(int i=1;i<6;i++)
    {
        string st=s;
        st+=charac(i);
        push(st,ind+1);
    }
}

bool pres(string s,char c)
{
    for(int i=0;i<4;i++)
    {
        if(s[i]==c)
            return 1;
    }
    return 0;
}

void comple(string s)
{
    for(int i=1;i<6;i++)
    {
        if(!pres(s,i+64))
        {
            s+=charac(i);
            perm[s]=1;
            return;
        }
    }
}

int main()
{
    IOS
    cin>>te>>f;
    for(int t=1;t<=te;t++)
    {
        perm.clear();
        for(int i=1;i<6;i++)
        {
            string s="";
            s+=charac(i);
            push(s,0);
        }
        /*
        cout<<perm.size()<<endl;
        for(map<string,bool>::iterator it=perm.begin();it!=perm.end();it++)
        {
            cout<<it->first<<endl;
        }
        */
        ll ar[4][5]={};
        for(int i=0;i<118;i++)
        {
            string s="";
            for(int j=1;j<5;j++)
            {
                char c;
                cout<<5*i+j<<endl;
                cin>>c;
                s+=c;
                ar[j-1][c-65]++;
            }
            comple(s);
        }
        char c;
        int ind;
        for(int i=0;i<4;i++)
        {
            bool num3=1;
            for(int j=0;j<5;j++)
            {
                if(ar[i][j]==23)
                {
                    num3=0;
                }
            }
            if(num3)
            {
                ind=i+1;
                cout<<118*5+ind<<endl;
                cin>>c;
                break;
            }
        }
        char ch[6];
        ch[ind-1]=c-64;
        bool bo[5]={};
        bo[ind-1]=1;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(ar[i][j]==22)
                {
                    ch[i]=charac(j+1);
                    bo[i]=1;
                }
            }
        }
        for(int i=0;i<5;i++)
        {
            if(!bo[i])
            {
                ind=i;
                break;
            }
        }
        for(int i=1;i<=5;i++)
        {
            bool bo=1;
            for(int j=0;j<5;i++)
            {
                if(j!=ind && ch[i]==i+48)
                    bo=0;
            }
            if(bo)
            {
                ch[ind]=i+48;
                break;
            }
        }
        string s="";
        for(int i=0;i<5;i++)
        {
            s+=ch[i];
        }
        perm[s]=1;
        string ans;
        for(map<string,bool>::iterator it=perm.begin();it!=perm.end();it++)
        {
            if(!(it->second))
            {
                ans=it->first;
            }
        }
        s="";
        for(int i=0;i<5;i++)
        {
            ans+=charac(ch[i]);
        }
        ll res;
        cout<<ans<<endl;
        cin>>res;
        if(res=='n')
        {
            exit(0);
        }
    }
    
}