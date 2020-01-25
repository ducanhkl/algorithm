#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, k;
int a[maxn], dd[maxn], ans = 0, res;
pair <int, int> _a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > 1e6 || a[i] == 0)
            i--, n--;
    }
    sort(a+1,a+n+1);
    int dem = 0;
    int sl;
    _a[++dem].first = a[1],sl = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i-1])
            _a[dem].second = sl, _a[++dem].first = a[i], sl = 1;
        else sl ++;
    _a[dem].second = sl;
    memset(dd, 0, sizeof(dd));
    for (int i = 1; i <= dem; i++)
        for (int j = _a[i].first;j <= k; j += _a[i].first)
            {
                dd[j] += _a[i].second;
                if (dd[114] == 4)
                    n = n;
                if (dd[j] > ans)
                    ans = dd[j];
            }
    for (int i = 1; i <= k; i++)
        if (dd[i] == ans)
    {
        res = i;
        break;
    }
    cout << res << " " << ans;
    return 0;
}
