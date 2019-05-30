#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n,m;
int a[maxn], ans[maxn], dd[maxn], sl[maxn];
pair <int, int> b[maxn];

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] <= n)
            sl[a[i]] ++;
    }
    for (int i = 1; i <= m; i++)
        cin >> b[i].first >> b[i].second;
    for (int i = 1; i <= n; i++)
        if (sl[i] >= i)
    {
        memset(dd, 0, sizeof(dd));
        for (int j = 1; j <= n; j++)
            dd[j] = dd[j-1]+(int)(a[j] == i);
        for (int j = 1; j <= n; j++)
            if (dd[b[j].second] - dd[b[j].first-1] == i)
                ans[j] ++;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
    return 0;
}
