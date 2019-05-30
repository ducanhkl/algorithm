#include <bits/stdc++.h>

using namespace std;

int f[2][100];
int n, k;
int a[1001];

int calc(int x, int y)
{
    int res = x-y;
    if (res < 0)
        return res + k;
    else return res;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] = a[i] % k;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 100; j++)
            f[i][j] = INT_MIN;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            f[i%2][j] = max(f[(i+1)%2][j], f[(i+1)%2][calc(j, a[i])] + 1);
    cout << f[n%2][0];
    return 0;
}
