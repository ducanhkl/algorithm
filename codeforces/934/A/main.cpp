#include <bits/stdc++.h>
#define maxn 10005

using namespace std;

int n, m;
long long a[maxn], b[maxn], c[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        c[i] = -1e18;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            c[j] = max(c[j],a[j]*b[i]);
    sort(c+1, c+n+1);
    cout << c[n-1];
    return 0;
}
