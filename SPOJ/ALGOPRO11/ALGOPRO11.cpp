#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100005

using namespace std;

vector <int> v[maxn];
int a[maxn], n, m, k;

int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
        cin >> a[i], v[a[i]].push_back(i);
    for (int i = 1; i <= m; i++)
        sort(v[i].begin(), v[i].end());
    int ans = -1;
    for (int i = 1; i <= m; i++)
    {
        if (v[i].size() == 1)
        {
            ans = max(ans, 1);
            continue;
        }
        int l = 0, dem = 0;
        for (int j = 1; j < v[i].size(); j++)
            {
                dem += v[i][j] - v[i][j-1] - 1;
                while (dem > k)
                    dem -= abs(v[i][l] - v[i][(l++)+1]+1);
                ans = max(ans, v[i][j] - v[i][l] + 1-dem);
            }
    }
    cout << ans;
	return 0;
}
