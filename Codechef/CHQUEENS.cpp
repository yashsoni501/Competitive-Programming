#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;
int t,x,y,n,m,ns;

int main()
{
    cin>>t;
    while(t--)
    {

        ns=0;
        cin>>n>>m>>x>>y;
        /*
        ns+=(x-1)*(n-x-1);
        ns+=(y-1)*(m-y-1);
        ns+=min(x-1,y-1)*min(n-x,m-y);
        ns+=min(x-1,m-y)*min(y-1,n-x);
        ns*=2;
        */
        //cout<<"Ns "<<ns<<endl;
        for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=m;j++)
            {
                if(i==x&&j==y)
                continue;
                ns += n*m-(m-1 + n-1 + min(i-1,j-1) + min(n-i,m-j) + min(i-1,m-j) + min(j-1,n-i) + 2);
                //cout<<"ns "<<ns<<endl;

                if(x==i)
                {
                    ns++;
                    if(j<y)
                        ns+=m-y;
                    else
                        ns+=y-1;
                }
                else if(y==j)
                {
                    ns++;
                    if(i<x)
                        ns+=n-x;
                    else
                        ns+=x-1;
                }
                else if(abs(x-i)==abs(y-j))
                {
                    //cout<<"inside"<<endl;
                    ns++;
                    if(i<x&&j<y)
                        ns+=min(n-x,m-y);
                    else if(i<x&&j>y)
                        ns+=min(y-1,n-x);
                    else if(i>x&&i<y)
                        ns+=min(x-1,m-y);
                    else
                        ns+=min(x-1,y-1);
                }
                //cout<<i<<" "<<j<<" "<<ns<<endl;
            }

        }

        cout<<ns<<endl;
    }
}
