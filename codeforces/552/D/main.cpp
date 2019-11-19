#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
long long  n;
struct data
{
    int x, y;
} a[maxn];
long long ans = 0;

int cnt[1000][1000];

void calc(int pos)
{
    int maxx = 500;
    long long res = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = pos+1; i <= n; i++)
    {
        int dx = a[i].x - a[pos].x;
        int dy = a[i].y - a[pos].y;
        long long g = __gcd(dx, dy);
        dx /= g;
        dy /= g;
        if (dx < 0)
        {
            dx = -dx;
            dy = -dy;
        }
        if (dx == 0)
            dy = abs(dy);
        if (dy < 0)
            dy = dy + maxx;
        res += cnt[dx][dy];
        cnt[dx][dy]++;
    }
    ans -= res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    ans = n*(n-1)*(n-2)/6;
    for (int i = 1; i <= n; i++)
        calc(i);
    cout << ans;
    return 0;
}
