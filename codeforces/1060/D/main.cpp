#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

long long l[maxn], r[maxn], ans = 0, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    sort(l+1, l+n+1);
    sort(r+1, r+n+1);
    for (int i = 1; i <= n; i++)
        ans += max(l[i], r[i]);
    cout << ans;
    return 0;
}
