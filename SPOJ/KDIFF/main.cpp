#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100004

using namespace std;

int f[maxn], g[maxn], a[maxn];
int n, k;
deque <int> mi, ma;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = f[i-1]; j <= i; j++)
    {
        while (!mi.empty() && mi.front() < j) mi.pop_front();
        while (!ma.empty() && ma.front() < j) ma.pop_front();
        while (!mi.empty() && a[mi.back()] > a[i]) mi.pop_back();
        while (!ma.empty() && a[ma.back()] < a[i]) ma.pop_back();
        mi.push_back(i);
        ma.push_back(i);
        if (a[ma.front()] - a[mi.front()] <= k)
        {
            f[i] =  j;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
        g[i] = max(g[i-1], i - f[i]  + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, i - f[i] + 1 + g[f[i] - 1] );
    cout << ans;
	return 0;
}
