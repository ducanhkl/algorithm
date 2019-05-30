#include <bits/stdc++.h>

using namespace std;

const int maxc = 1e6+100;
int n;
int cnt[maxc], ans = 0;

int main()
{
    memset(cnt, 0, sizeof(cnt));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            cnt[x] ++;
        }
    for (int x = 0; x < maxc; x++)
    {
        if (cnt[x] >= 2)
        {
            cnt[x+1] += (cnt[x]/2);
            cnt[x] -= (cnt[x]/2)*2;
        }
    }
    for (int x = 0; x < maxc; x++)
        ans += cnt[x];
    cout << ans;
    return 0;
}
