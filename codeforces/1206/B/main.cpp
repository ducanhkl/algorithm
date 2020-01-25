#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n;
long long ans = 0, a[maxn], cnt0 = 0, cnt1 = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            ans += -(a[i] + 1);
            a[i] = -1;
            cnt1 ++;
        }
        if (a[i] > 0 )
        {
            ans += a[i] - 1;
            a[i] = 1;
        }
        if (a[i] == 0)
        {
            cnt0++;
        }
    }
    if (cnt1%2)
    {
        if (!cnt0)
        {
            ans += 2;
        }
    }
    cout << ans + cnt0;
    return 0;
}
