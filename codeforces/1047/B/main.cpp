#include <bits/stdc++.h>

using namespace std;

int n, x, y, ans = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        ans = max(ans, x+y);
    }
    cout << ans;
    return 0;
}
