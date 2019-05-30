#include <bits/stdc++.h>

using namespace std;

int n, k, ans = 0;
char a[100];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        a[i] = (a[i] -'a');
    sort(a+1, a+n+1);
    int i, j = 1, tr = a[1]; ans += a[1];
    for (int i = 1; i <= n; i++)
        if (a[i] - tr > 1)
    {
        ans += a[i];
        tr = a[i];
        j ++;
        if (j == k)
            break;
    }
    if (j < k)
        return cout << -1, 0;
    cout << ans+k;
    return 0;
}
