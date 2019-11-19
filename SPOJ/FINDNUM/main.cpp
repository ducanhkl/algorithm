#include <bits/stdc++.h>

using namespace std;

long long prime[] = {0, 2,3,5,7,11,13,17,19,23,29};
long long maxpow[] = {0, 59,37,25,21,17,16,14,14,13,12};
int n;
long long f[1001][20];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 11; j++)
        {
            if (i == 1)
                f[i][j] = 1; else
            if (j == 0)
                f[i][j] = LONG_LONG_MAX; else
                {
                    f[i][j] = f[i][j-1];
                    long long mul = prime[j];
                    for (int k = 1; k <= maxpow[j]; k++, mul*=prime[j])
                        if (i % (k+1) == 0 && f[i/(k+1)][j-1] <= LONG_LONG_MAX/mul)
                            f[i][j] = min(f[i][j], f[i/(k+1)][j-1]*mul);
                }
        }
    cout << f[n][10];
    return 0;
}
