#include<bits/stdc++.h>
using namespace std;
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   #define int long long
int a[100000+1];
int b[100000+1];
tuple<int, int> c[100000+1];
int psums[100000+2];
int countop(int m,int n)
{
   int ans = 0;
   REP(i, n)
   {
       if(a[i] <= m)
           ans+=m-a[i];
       else
           ans += b[i]+m-a[i];
   }
   return ans;
}
signed main()
{
   IOS
   int t;
   cin >> t;
   while(t--)
   {
       int n;
       cin >>n;
       REP(i, n)
           cin >> a[i];
       REP(i,n)
           cin >> b[i];
       REP(i, n)
           a[i] = a[i]%b[i];
       REP(i, n)
           c[i] = make_tuple(a[i], b[i]);
       psums[0]=0;
       REP(i,n)
           psums[i+1] = psums[i]+b[i];
       sort(c, c+n);
       int mans = countop(a[0], n);
       int pans = 0;
       REP(i, n)
           pans-=a[i];
       pans += psums[n];
       int bhigh=get<1>(c[0]);
       REP(i,n)
       {
           bhigh = min(bhigh,get<1>(c[0]));
       }
       REP(i,n)
       {
           if(get<0>(c[i]) >= bhigh)
               break;
           pans -= get<1>(c[i]);
           int ans = pans + n*get<0>(c[i]);
           mans = min(ans, mans);
           cout<<ans<<endl;
       }
       cout << "ans1 "<<mans << "\n";
       int ans = 1e14,he=-1;
       REP(i,bhigh)
       {
           if(ans>countop(i,n))
           {
               ans = countop(i,n);
               he = i;
           }
       }
       cout<<"ans2 "<<ans<<" "<<he<<endl;
       REP(i,n) cout<<get<0>(c[i])<<"\t";
       cout<<endl;
       REP(i,n) cout<<get<1>(c[i])<<"\t";
       cout<<endl;
       REP(i,n) cout<<get<0>(c[i]) % get<1>(c[i])<<"\t";
       cout<<endl;
   }
}