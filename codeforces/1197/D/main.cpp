#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100;
int n, m, k;
int a[maxn];
long long ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <=  m; i++)
    {
        long long tmp = 0;
        for (int j = i; j <= n; j += m)
            {
                tmp -= k;
                for (int k = 1; k <= m; k++)
                {
                    if (j+k-1 > n)
                        break;
                    tmp += a[j+k-1];
                    ans = max(ans, tmp);
                }
                tmp = max(tmp, 0LL);
            }
    }
    cout << ans;
    return 0;
}
