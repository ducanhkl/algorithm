#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

typedef pair <int, int> pii;
pii d[maxn];
int f[3][maxn], n, m, b[maxn];
char a[maxn];

int main()
{
    freopen("inp.txt", "r", stdin);
    memset(d, 0, sizeof(d));
    memset(f, 0, sizeof(f));
    memset(b, 0, sizeof(b));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == '?')
            b[i] = b[i-1] + 1;
        else b[i] = b[i-1];
        if (a[i] != 'a')
            f[1][i] = f[0][i-1]+1;
        if (a[i] != 'b')
            f[0][i] = f[1][i-1]+1;
        if (f[!(m&1)][i] >= m)
            d[i] = {d[i-m].first + 1, -(b[i]-b[i-m]-d[i-m].second)};
        d[i] = max(d[i-1], d[i]);
    }
    cout << - d[n].second;
    return 0;
}
