#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 1000000001

using namespace std;

string s[55];
int a[60][55];
int n;
int ans = maxnum;

int main()
{
    memset(a, 0, sizeof(a));
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 2; i <= 51; i++)
        for (int j = 0; j <= 51; j++)
            a[i][j] = maxnum;
    for (int i = 0; i< 51; i++)
        a[1][i] = i;
    int  l = s[1].length();
    for (int i = 1; i <= n; i++)
        s[i] = s[i] + s[i];
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < l; j++)
            for (int k = 0; k < l; k++)
                if (s[i].substr(k, l) == s[i-1].substr(j, l))
                    a[i][k] = min(a[i][k], a[i-1][j]+k);
    for (int i = 0; i < l; i++)
        ans = min(ans, a[n][i]);
    if (ans == maxnum)
        return cout << -1, 0;
    cout << ans;
	return 0;
}
