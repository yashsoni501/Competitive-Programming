#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
#define trace(x) cerr << #x << ": " << x << " " << endl;

int main() {
    FIO;
    int t, n, k, i, j, x, cnt1, cnt2, tmp;
    string s;

    cin >> t;
    while (t--> 0) {
        cin >> n >> x;
        cin >> s;

        int disparity[n][n]={};
        int frequency[26] = {0};

        for (i = 0; i < n; i++) {

            for (j = i; j < n; j++) {

                frequency[s[j] - 'a']++;

                cnt1 = 0;
                cnt2 = n;
                for (k = 0; k <= 25; k++) {
                    cnt1 = max(cnt1, frequency[k]);
                    if (frequency[k] > 0)
                        cnt2 = min(cnt2, frequency[k]);
                }
                // trace(cnt1) trace(cnt2)
                for (k = 0; k <= 25; k++)
                    if (frequency[k] == cnt1)
                        break;
                // trace(k)
                disparity[i][j] = k;

                for (k = 0; k <= 25; k++)
                    if (frequency[k] == cnt2)
                        break;
                // trace(k)
                disparity[i][j] -= k;
            }
            REP(j,26)   frequency[j]=0;
        }
        // cout<<"prt\n";
        REP(i,n)
        {
            REP(j,n)
            {
                cout<<disparity[i][j]<<" ";
            }
            cout<<endl;
        }
        int dp[k][n];

        for (i = 0; i < n; i++) {
            dp[0][i] = disparity[0][i];
        }

        for (i = 1; i < x; i++) {
            for (j = 0; j < n; j++) {
                dp[i][j] = dp[i - 1][j];
                for (k = 0; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + disparity[k + 1][j]);
                }
            }
        }

        cout << dp[x - 1][n - 1] << "\n";
    }
    return 0;
}
