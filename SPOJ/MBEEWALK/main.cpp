#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

ll dp[35][35][35];
int dx[6] = {1, 1, 0, -1, -1, 0};
int dy[6] = {0, -1, -1, 0, 1, 1};
int t, n;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> t;
	while (t--)
    {
        cin >> n;
        memset(dp, 0, sizeof(dp));
        dp[0][15][15] = 1;
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <=30; i ++)
                for (int j = 1; j <= 30; j ++)
                    for (int h = 0; h < 6; h++)
                        dp[k][i][j] += dp[k-1][i+dx[h]][j+dy[h]];
        cout << dp[n][15][15] << endl;
    }
	return 0;
}
