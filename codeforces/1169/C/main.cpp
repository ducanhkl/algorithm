#include <bits/stdc++.h>

using namespace std;


const int maxn = 3e5+100, maxc = 1e8;
int n, m;
int a[maxn], b[maxn];

bool check(int mid)
{
    for (int i = 1; i <= n; i++)
        b[i] = a[i];
    b[0] = 0;
    for (int i = 1; i <= n; i++)
        if (b[i-1] > b[i])
    {
        if (b[i-1] - b[i] <= mid)
            b[i] = b[i-1];
        else
            return false;
    } else
    {
        if (b[i-1] - b[i] + m <= mid)
            b[i] = b[i-1];
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int mid, l = 0, r = maxc, ans = 0;
    while (l <= r)
    {
        mid = (l+r) >> 1;
        if (check(mid))
            r = mid-1, ans = mid;
        else
            l = mid+1;
    }
    cout << ans;
    return 0;
}
