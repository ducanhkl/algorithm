#include <bits/stdc++.h>
#define maxn 1009

using namespace std;


int connect[maxn][maxn];
int b[maxn], a[maxn], res[maxn];
int n, m;

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(connect, 0, sizeof(connect));
    for (int i = 0; i < maxn; i++)
        res[i] = 1;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    b[1] = a[1];
    m = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i-1])
        b[++m] = a[i];
    for (int i = 1; i <= m; i++)
        for (int j = i+1; j <= m; j++)
    {
        int pos = lower_bound(b+1, b+m+1, b[i]+b[j])-b;
        if (b[pos] == b[i] + b[j])
            connect[i][pos] = 1, connect[j][pos] = 1;
    }
    for (int i = 1; i <= m; i++)
        for (int j = i - 1; j >= 1; j--)
            if (connect[j][i])
                res[i] = max(res[i], res[j] + 1);
    cout << *max_element(res+1, res+m+1);
    return 0;
}
