#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[200], b[200], ans = 0, dem = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    int cnt = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i-1])
            b[++dem] = cnt, cnt = 1;
        else
            cnt++;
    b[++dem] = cnt;
    sort(b+1, b+dem+1);
    int res = ceil(b[dem]*1.0/k);
    for (int i = 1; i <= dem; i++)
        ans += res*k-b[i];
    cout << ans;
    return 0;
}
