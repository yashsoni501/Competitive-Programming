#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    ll m_a,m_b,m_c,m_d;
    ll xl,yl,xu,yu;
    ll result;
    while(t--)
    {
        cout<<"Q 0 0"<<endl;
        cin>>m_a;
        cout<<"Q 1000000000 0"<<endl;
        cin>>m_b;
        cout<<"Q 0 1000000000"<<endl;
        cin>>m_c;
        cout<<"Q 1000000000 1000000000"<<endl;
        cin>>m_d;

        ll tmp1=m_c-m_d+1e9;
        cout<<"Q "<<tmp1/2<<" 0 "<<endl;
        cin>>yl;

        ll tmp2=m_b-m_d+1e9;
        cout<<"Q 0 "<<tmp2/2<<endl;
        cin>>xl;

        xu=tmp1-xl;
        yu=tmp2-yl;

        cout<<"A "<<xl<<" "<<yl<<" "<<xu<<" "<<yu<<endl;
        cin>>result;

        if(result<0)
            return 0;
    }
}
