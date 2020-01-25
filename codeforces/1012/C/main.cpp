#include <bits/stdc++.h>
#define maxn 6000

using namespace std;

int n;
long long a[maxn], f[maxn][3];

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 2; j++)
            f[i][j] = INT_MAX;
    f[0][0] = f[1][1] = 0;
    for (int i = 2; i <= n; i++)
        for (int j = (i+1)/2; j >= 1; j--)
    {
        f[j][0] = min(f[j][0],f[j][2]);
        f[j][2] = f[j][1] + max(0LL, a[i]-a[i-1]+1);
        f[j][1] = min(f[j-1][0] + max(0LL, a[i-1]-a[i]+1), f[j-1][2] + max(0LL, min(a[i-1],a[i-2]-1)-a[i]+1));
    }
    for (int i = 1; i <= (n+1)/2; i++)
        cout << min(f[i][0], min(f[i][1], f[i][2])) << " ";
    return 0;
}
