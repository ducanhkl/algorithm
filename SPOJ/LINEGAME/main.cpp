#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n;
long long f[maxn][2], a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = max(f[i-1][1]+a[i], f[i-1][0]);
        f[i][1] = max(f[i-1][0]-a[i], f[i-1][1]);
    }
    cout << max(f[n][0], f[n][1]);
    return 0;
}
