#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, m, k;
int a[maxn];
pair <int, int> b[maxn];
int ans1 = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i != 1)
            b[i-1] = {a[i] - a[i-1], i};
    }
    sort(b+1, b+n);
    for (int i = 1; i <= n-k; i++)
            ans1 += b[i].first-1;
    ans1 += n;
    cout << ans1;
    return 0;
}
