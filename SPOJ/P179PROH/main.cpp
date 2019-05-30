#include <bits/stdc++.h>
#define maxn 21

using namespace std;

int n, k;
long long f[1<<maxn];
int a[maxn][maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int num = 0; num < (1<<n); num++)
    {
        f[num] = INT_MAX;
        if (__builtin_popcount(num) < k)
            continue;
        if (__builtin_popcount(num) == k)
        {
            f[num] = 0;
            continue;
        }
        for (int i = 0; i < n; i++)
            if ((num>>i)&1)
        {
            for (int j = 0; j < n; j++)
                if (i != j && (num>>j)&1)
                    f[num] = min(f[num], f[num-(1<<j)]+a[j][i]);
        }
    }
    cout << f[(1<<n)-1];
    return 0;
}
