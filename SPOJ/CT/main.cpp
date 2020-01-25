#include <bits/stdc++.h>

using namespace std;

long long ans = 0, x, y;

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= 1010; i++)
        for (int j = 1; j <= 1010; j++)
            f[i][j] = f[i-1][j]+f[i-1][j-1];
    while (t--)
    {
        ans = 0;
        cin >> x >> y;
        cout <<
    }
    return 0;
}
