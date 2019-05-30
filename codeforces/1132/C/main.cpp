#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;
const int maxn = 5e3+100;
pii a[maxn];
int n, q;
int num1[maxn][maxn], num2[maxn][maxn], cnt[maxn];
int ans = 0;

int calc(pii x, pii y)
{
    if (x.first > y.first)
        swap(x, y);
    int xx = max(x.first, y.first);
    int yy = min(x.second, y.second);
    int xf = min(x.first, y.first);
    int yf = max(x.second, y.second);
    if (xx > yy)
        return num1[x.first][x.second] + num1[y.first][y.second];
    return num1[xf][xx-1] + num2[xx][yy] + num1[yy+1][yf];
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> a[i].first >> a[i].second;
        for (int j = a[i].first; j <= a[i].second; j++)
            cnt[j]++;
    }
    for (int i = 1; i <= n; i++)
    {
        int cnt1 = 0, cnt2 = 0;
        for (int j = i; j <= n; j++)
        {
            if (cnt[j] == 1)
                cnt1++;
            if (cnt[j] == 2)
                cnt2 ++;
            num1[i][j] = cnt1;
            num2[i][j] = cnt2;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += (cnt[i]!=0);
    for (int i = 1; i <= q; i++)
        for (int j = i+1; j <= q; j++)
    {
        int t = calc(a[i], a[j]);
        ans = max(ans, res-t);
    }
    cout << ans;
    return 0;
}
