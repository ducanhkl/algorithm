#include <bits/stdc++.h>
#define maxn 4000005

using namespace std;

long long a[maxn], b[maxn], ma[maxn], mb[maxn], ans = 0, x;
int n, m;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < maxn; i++)
        ma[i] = mb[i] = INT_MAX;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        long long sum1 = 0;
        for (int j = i; j >= 1; j --)
        {
            sum1 += a[j];
            ma[i-j+1] = min(ma[i-j+1], sum1);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        long long sum1 = 0;
        for (int j = i; j >= 1; j--)
        {
            sum1 += b[j];
            mb[i-j+1] = min(mb[i-j+1], sum1);
        }
    }
    cin >> x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (ma[i]*mb[j] <= x)
                ans = max(ans, 1LL*i*j);
    cout << ans;
}
