#include <bits/stdc++.h>

using namespace std;

const int maxn = 5030;
int n, m, d;
int p[maxn], c[maxn], ufr[maxn], trc[maxn], q[maxn], dd[maxn], ans[maxn];
vector <int> e[maxn];

bool match(int u)
{
    for (auto v : e[u])
    {
        if (!ufr[v])
        {
            ufr[v] = 1;
            if (trc[v] == -1 || match(trc[v]))
            {
                trc[v] = u;
                ufr[v] = 0;
                return true;
            }
            ufr[v] = 0;
        }
    }
    return false;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <=n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    cin >> d;
    for (int i = 1; i <= d; i++)
        {
            cin >> q[i];
            dd[q[i]] = 1;
        }
    for (int i = 1; i <= n; i++)
        if (!dd[i])
            e[p[i]].push_back(c[i]);
    int cnt = 0;
    memset(ufr, 0, sizeof(ufr));
    for (int i = 0; i < maxn; i++)  trc[i] = -1;
    for (int i = d; i >= 1; i--)
    {
        for (; cnt <= 5100; cnt ++)
            {
                if (!match(cnt))
                    break;
            }
        ans[i] = cnt;
        e[p[q[i]]].push_back(c[q[i]]);
    }
    for (int i = 1; i <= d; i++)
        cout << ans[i] << endl;
    return 0;
}
