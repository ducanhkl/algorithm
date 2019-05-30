#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, v, w = 0, ans = 0;
    ios_base::sync_with_stdio(false);
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
        {
            if (i + w < n)
            {
                int res = min(v-w, n-i);
                w += res;
                ans += i*res;
            }
            w --;
        }
    cout << ans;
    return 0;
}
