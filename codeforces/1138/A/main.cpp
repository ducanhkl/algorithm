#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, ans = 0;
int a[maxn], b[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    b[1] = 1;
    int cnt=1;
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i-1])
            b[++cnt] = 1;
        else
            b[cnt] ++;
    for (int i = 2; i <= cnt; i++)
        ans = max(ans, min(b[i], b[i-1])*2);
    cout << ans;
    return 0;
}
