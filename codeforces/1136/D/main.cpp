#include <bits/stdc++.h>

using namespace std;

const int maxn = 3*1e5+100;
int n, m, ans = 0;
vector <int> e[maxn];
int cnt[maxn], a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[v].push_back(u);
    }
    for (int i = 0; i < e[a[n]].size(); i++)
        cnt[e[a[n]][i]]++;
    for (int i = n-1; i >= 1; i--)
    {
        if (cnt[a[i]] == n-ans-i)
            ans++;
        else
            for (int j= 0; j < e[a[i]].size(); j++)
                cnt[e[a[i]][j]]++;
    }
    cout << ans;
    return 0;
}
