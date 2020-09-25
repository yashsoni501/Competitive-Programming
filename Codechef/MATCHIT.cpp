#include<iostream>
#include<stack>
using namespace std;

typedef long long int ll;
ll n,m;

struct node
{
    ll x,y;
};

stack <node> st;
int main()
{
    cin>>n>>m;
    bool arr[n][n]={};

    ll a,b;
    for(int i=0;i<2*m;i++)
    {
        cin>>a>>b;
        arr[a-1][b-1]=1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a;
        }
    }
    bool state=false;
    for(ll i=0;i<n;i++)
    {
        if(i%2)
        {
            for(ll j=n-1;j>=0;j--)
            {
                if(arr[i][j])
                {
                    if(state)
                    {
                        st.push(node{i+1,j+1});
                        state=false;
                        cout<<st.size()<<" ";
                        while(!st.empty())
                        {
                            node tmp=st.top();
                            st.pop();
                            cout<<tmp.x<<" "<<tmp.y<<" ";
                        }
                        cout<<endl;
                    }
                    else
                    {
                        state=true;
                        st.push(node{i+1,j+1});
                    }
                }
                else
                {
                    if(state)
                    {
                        {
                            st.push(node{i+1,j+1});
                        }
                    }
                }

            }
        }
        else
        {
            for(ll j=0;j<n;j++)
            {
                if(arr[i][j])
                {
                    if(state)
                    {
                        st.push(node{i+1,j+1});
                        state=false;
                        cout<<st.size()<<" ";
                        while(!st.empty())
                        {
                            node tmp=st.top();
                            st.pop();
                            cout<<tmp.x<<" "<<tmp.y<<" ";
                        }
                        cout<<endl;
                    }
                    else
                    {
                        state=true;
                        st.push(node{i+1,j+1});
                    }
                }
                else
                {
                    if(state)
                    {
                        {
                            st.push(node{i+1,j+1});
                        }
                    }
                }
            }
        }

    }

}
