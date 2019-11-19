#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

long long ans = 0;
int n, k, m, xx[maxn], c[maxn], x;
string a[maxn];
map <string, int> dd;


int main()
{
    //freopen("inp.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    for (int i = 1; i <= k; i++)
    {
        memset(xx, 0, sizeof(xx));
        cin >> x;
        for (int j = 1; j <= x; j++)
            cin >> xx[j];
        for (int j = 2; j <= x; j++)
            c[xx[j]] = min (c[xx[j-1]], c[xx[j]]);
        for (int j = x-1; j >= 1; j--)
            c[xx[j]] = min (c[xx[j+1]], c[xx[j]]);
    }

    for (int i = 1; i <= n; i++)
        dd[a[i]] = c[i];

    for (int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;
        ans += dd[s];
    }

    cout << ans;
    return 0;
}
