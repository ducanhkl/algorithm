#include <bits/stdc++.h>

using namespace std;

int n, k, res, ans = 0;
char a[100004];
int cnt[400];

int main()
{
    memset(cnt, 0, sizeof(cnt));
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cnt[a[i]] ++;
        res = INT_MAX;
        for (int i = 'A'; i <= 'A'+k-1; i++)
            res = min(cnt[i], res);
        ans = max(ans, res*k);
    }
    cout << ans;
    return 0;
}
