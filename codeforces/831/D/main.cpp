#include <bits/stdc++.h>
#define maxn 4000

using namespace std;

int a[maxn], b[maxn];
long long f[maxn][maxn];
int n, k, p;


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    cin >> n >> k >> p;
    fill(f[0],f[n+2], 1e10+7);
    fill(f[0], f[0]+k+2, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        cin >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+k+1);
    for (int i = 1;i <= n; i++)
        for (int j = 1; j <= k; j++)
            f[i][j] = min(f[i][j-1], max(f[i-1][j-1],(long long )abs(b[j] - a[i]) + (long long) abs(b[j] - p)));
    cout << f[n][k];
    return 0;
}
