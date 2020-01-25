#include <bits/stdc++.h>
#define maxn 100006

using namespace std;

long long a[maxn], b[maxn], c[maxn];
int n, k;
long long ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        if (b[i] >= a[i])
            ans += b[i] - a[i];
        else ans += k - a[i] + b[i] + 1;
    for (int i = 0; i < n; i ++)
    {
        for (int j = 1; j <= n; j++)
        {
            int d;
            if (i + j > n)
                d = (i+j)%n;
            else d = i+j;
            if (b[d] >= a[j])
                c[j] = b[d] - a[j];
            else c[j] = k-a[j] + b[d] + 1;
        }
        for (int j = 1; j <= n; j++)
        {
            int res = 0;
            for (int h = 1; h <= n; h++)
                if (c[h] >= c[j])
                    res += c[h] - c[j];
                else res += k - c[j] + c[h] + 1;
            ans = min(ans, res + c[j] + i);
        }
    }
    cout << ans;
    return 0;
}
