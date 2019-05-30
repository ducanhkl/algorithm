#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

pair <int, int> s[maxn];
int f[10000007];
int res[maxn], n, k, m, dem = 0;

int main()
{
    freopen("inp.txt", "r", stdin);
    memset(f, 0, sizeof(f));
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i  <= n; i++)
    {
        int x;
        cin >> x;
        f[x] ++;
        if (f[x] > k)
            return cout << -1, 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        s[i] = {x, i};
    }
    sort(s+1, s+m+1);
    int l = 0;
    for (int i = 1; i <= m; i++)
    {
        if (f[l] == k)
        {
            l ++, i--;
            continue;
        }
        if (l > s[i].first)
            continue;
        else
            f[l] ++, res[++dem] = s[i].second;
    }
    cout << dem << endl;
    for (int i = 1; i <= dem; i++)
        cout << res[i] << " ";
    return 0;
}
