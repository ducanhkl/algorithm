#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000
#define maxm 1000

using namespace std;

int a[maxm], n, m;
ll dp[maxn];
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = a[i]; j <= n; j++)
            dp[j] += dp[j-a[i]];
    cout << dp[n];
    return 0;
}
