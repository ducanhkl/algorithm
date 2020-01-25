#include <bits/stdc++.h>
#define maxn 200005

using namespace std;

int n, m, d, res = 0;
int b[maxn], ans[maxn], dd[maxn], f[maxn], vt = 0;
pair <int, int> a[maxn];

int main()
{
    memset(f, 0, sizeof(f));
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first, a[i].second = i;
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
        b[i] = a[i].first;
    for (int i = 1; i <= n; i++)
    {
        int kq = 0, vt = 0;
        for (int j = res; j >= 1; j--)
            if (b[i] - b[f[j]] - 1 >= d && kq < b[f[j]])
            {
                kq = b[f[j]];
                vt = j;
            }
        if (kq == 0)
            vt = ++res;
        f[vt] = b[i];
        dd[i] = vt;
    }
    cout << res << endl;
    for (int i = 1; i <= n; i++)
        ans[a[i].second] = dd[i];
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}
