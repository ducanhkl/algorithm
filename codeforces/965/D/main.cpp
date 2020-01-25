#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, l, ans = INT_MAX;
int a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> l;
    memset(a, 0, sizeof(a));
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        a[i] += a[i-1];
        if (i >= l)
            ans = min(ans, a[i] - a[i-l]);
    }
    cout << ans;
    return 0;
}
