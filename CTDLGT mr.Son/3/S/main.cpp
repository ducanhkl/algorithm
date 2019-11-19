#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+100;
long long f[maxn][maxn];
const long long mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    memset(f, 0, sizeof(f));
    for (int i = 0; i < maxn; i++)
        f[i][0] = 1;
    for (int i = 1; i < maxn; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = (f[i-1][j]+f[i-1][j-1])%mod;
    int test;
    cin >> test;
    while  (test--)
    {
        int n, k;
        cin >> n >> k;
        cout << f[n][k] << endl;
    }
    return 0;
}
