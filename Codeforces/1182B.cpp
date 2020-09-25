#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll h,w,cnt=0;
bool mat[510][510]={};
bool mat2[510][510]={};
bool isvalid(int i,int j)
{
    if(i>=0&&i<h&&j>=0&&j<w)
        return 1;
    return 0;
}

ll ar[5]={};

int neigh(int i,int j)
{   
    ll cnt=0;
    if(isvalid(i,j-1) && mat[i][j-1])
    {
        cnt++;
    }
    if(isvalid(i,j+1) && mat[i][j+1])
    {
        cnt++;
    }
    if(isvalid(i-1,j) && mat[i-1][j])
    {
        cnt++;
    }
    if(isvalid(i+1,j) && mat[i+1][j])
    {
        cnt++;
    }

    return cnt;
}

string y="YES";
string n="NO";

int main()
{
    IOS
    cin>>h>>w;
    REP(i,h)
    {
        string s;
        cin>>s;
        REP(j,w)
        {
            char c=s[j];
            
            if(c=='*')
            {
                mat[i][j]=1;
                mat2[i][j]=1;
                cnt++;
            }
            else
            {
                mat[i][j]=0;
                mat2[i][j]=0;
            }
        }
    }

    if(!cnt || h<3 || w<3)
    {
        cout<<n<<endl;
        return 0;
    }
    ll row=-1,col=-1;
    ll cnt2=0;
    REP(i,h)
    {
        REP(j,w)
        {
            if(mat[i][j])
            {
                col=j;
                for(int k=i;mat[k][j];k++)
                {
                    if(neigh(k,j)==0 or neigh(k,j)==3)
                    {
                        cout<<n<<endl;
                        return 0;
                    }
                    else
                    {
                        if(neigh(k,j)!=4)
                        {
                            mat2[k][j]=0;
                            cnt2++;
                        }
                        else
                        {
                            if(row!=-1 )
                            {
                                cout<<n<<endl;
                                return 0;
                            }
                            else
                            {
                                row=k;
                            }
                        }
                    }
                }
                break;
            }
        }
        if(col!=-1) break;
    }

    ll cnt3=cnt2;
    REP(i,w)
    {
        ll k=row;
        if(mat[k][i] && neigh(k,i)!=0 && neigh(k,i)!=3)
        {
            cnt2++;
            mat2[k][i]=0;
        }
    }
    if(cnt2==cnt3)
    {
        cout<<n<<endl;
        return 0;
    }
    if(cnt2==cnt)
    {
        cout<<y<<endl;
        return 0;
    }
    else{
        cout<<n<<endl;
        return 0;
    }
}