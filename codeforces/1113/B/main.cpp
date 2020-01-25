#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100, maxc = 100;
int a[maxn], n, cnt[300], ans = 0;


int main()
{
    freopen("inp.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], cnt[a[i]] ++;
    while (true)
        {
            int res = 0, val = 0, pos = 0, vt = 0;
            for (int j = 1; j <= maxc; j++)
                    if (cnt[j] != 0)
                {
                    pos = j;
                    break;
                }
            for (int i = maxc; i >= pos; i--)
            {
                if (cnt[i] == 0)
                    continue;
                for (int j = 2; j <= i; j++)
                {
                    if (i%j == 0)
                        {
                            int m = (i-i/j-(pos*j-pos));
                            if (m > res)
                            {
                                res = m;
                                vt = i;
                                val = j;
                            }
                        }
                }
            }
            if (res > 0)
                {
                    int m =  min(cnt[pos],cnt[vt]);
                    cnt[vt] -= m;
                    cnt[pos] -= m;
                    cnt[pos*val] += m;
                    cnt[vt/val] += m;
                }
            else
                break;
        }
    for (int i = 1; i <= maxc; i++)
        ans += i*cnt[i];
    cout << ans;
    return 0;
}
