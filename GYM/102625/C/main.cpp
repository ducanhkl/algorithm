#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;
int n, m;
long long a[maxn];
pair <int, int> q[maxn];

int main()
{
    // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].second >> q[i].first;
    }
    sort(a+1, a+n+1);
    sort (q+1, q+m+1, greater<pair<int, int>>());
    int last = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= q[i].second; j++)
        {
            if (q[i].first < a[last+1])
                break;
            a[++last] = q[i].first;
            if (last > n)
                break;
        }
        if (last > n)
            break;
    }
    long long res = 0;
    for (int i = 1; i <= n; i++)
        res += a[i];
    cout << res;
    return 0;
}
