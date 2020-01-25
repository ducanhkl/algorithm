#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1004

using namespace std;

ll t, a[maxn][maxn], b[maxn][maxn];
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j], t += a[i][j], b[i][j] = b[i][j-1] + a[i][j];
    if (n == 2)
    {
        cout << 1 << " " << b[1][n] - 1;
        return 0;
    }
    t = t/(2*(n-1));
    for (int i = 1; i <= n; i++)
        cout << -(t - b[i][n])/(n-2) << " ";
	return 0;
}
