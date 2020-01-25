#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int t;
int dp[1001][1001];
bool check(string a, string b, int n, int m)
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
        if (islower(a[i-1]))
            dp[i][0] = 1; else break;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (isupper(a[i-1]))
                if (a[i-1] == b[j-1] && dp[i-1][j-1])
                    dp[i][j] = true;
                else dp[i][j] = false;
            else
            {
                if (toupper(a[i-1]) == b[j-1] && dp[i-1][j-1])
                    dp[i][j] = true;
                else dp[i][j] = dp[i-1][j];
            }
    return dp[n-1][m-1];
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    string a, b;
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> t;
	while (t--)
    {
        cin >> a >> b;
        int l1 = a.length();
        int l2 = b.length();
        bool k = check(a, b, l1+1, l2+1);
        if (k)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}
