#include <bits/stdc++.h>

using namespace std;

const int maxn = 5*1e5+100;
int n, q;
int l[maxn], last[30], p[30], a[maxn], ans[maxn];
vector <int> v[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    memset(last, 0, sizeof(last));
    memset(p, 0, sizeof(p));
    memset(ans, 0, sizeof(ans));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int r;
        cin >> l[i] >> r;
        v[r].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int num = a[i], pos = i;
        for (int b = 30; b >= 0; b--)
            if ((num >> b) & 1)
        {
            if (last[b] == 0)
            {
                last[b] = num;
                p[b] = pos;
                break;
            }
            if (p[b] < pos)
            {
                swap(num, last[b]);
                swap(p[b], pos);
            }
            num ^= last[b];
        }
        for (auto vt : v[i])
        {
            int res = 0, lf = l[vt];
            for (int b = 30; b >= 0; b--)
                if (p[b] >= lf)
            {
                res = max(res, res^last[b]);
            }
            ans[vt] = res;
        }
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << endl;
    return 0;
}
