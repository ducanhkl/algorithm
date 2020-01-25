#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1001

using namespace std;


int n, d[maxn];
int t[maxn][6], dem = 0;
ll tinh(int _i, int _j, int _k)
{
    ll ans = 0;
    for (int i = 1; i <= 5; i++)
        ans += (t[_j][i] - t[_i][i])*(t[_k][i]-t[_i][i]);
    return ans;

}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	memset(d, 0, sizeof(d));
	for (int i = 1; i<= n; i++)
        for (int j = 1; j <= 5; j++)
            cin >> t[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (j!= k && i!= k && i != j)
                    if (tinh(i, j, k) > 0)
                        d[i] = 1, j = n, k = n;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            dem ++;
    cout << dem << endl;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            cout << i << endl;
	return 0;
}
