#include <bits/stdc++.h>
#define maxn 100011

using namespace std;

int a[maxn], cnt[maxn];
int n, k, ans = 0;

int main()
{
    memset(a, 0, sizeof(a));
    memset(cnt, 0, sizeof(cnt));
    //freopen("inp.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1;i <= n; i++)
        cin >> a[i], cnt[a[i]%k]++;
    for (int i = 1; i <= k/2; i++)
        ans += max(cnt[i], cnt[k-i]);
    if (k%2 == 0)
        {
            ans -= cnt[k/2];
            if (cnt[k/2]) ans ++;
        }
    if (cnt[0] > 0)
        ans ++;
    cout << ans;
    return 0;
}
