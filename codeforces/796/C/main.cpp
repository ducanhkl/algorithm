#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 10000004

using namespace std;

int n, maxxr = 0, maxx = INT_MIN, maxxx = 0, ans = INT_MAX;
int d[maxn];
vector <int> a[maxn];
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        if (d[i] == maxx)
            maxxr ++;
        if (d[i] > maxx)
            maxx = d[i], maxxr = 1;
    }
    for (int i = 1; i <= n; i++)
        if (d[i] == maxx - 1)
            maxxx ++;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        int l = 0, k = 0, kt = 0;
        if (d[i] == maxx)
            l ++;
        for (int j = 0; j < a[i].size(); j++)
        {
            if (d[a[i][j]] == maxx) k++;
            if (d[a[i][j]] == maxx - 1) kt ++;
        }
        if (k + l == maxxr)
        {
            if (k == 0 && kt == maxxx)
                ans = min(ans, maxx);
            else ans = min(ans, maxx + 1);
        } else ans = min(ans, maxx + 2);
    }
    cout << ans;
    return 0;
}
