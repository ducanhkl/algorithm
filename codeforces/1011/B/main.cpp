#include <bits/stdc++.h>
#define maxn 300

using namespace std;


int n, m, ans = 0, cnt = 1;
pair <int, int> dd[maxn];
int a[maxn];

bool check(int x)
{
    if (x == 0)
        return true;
    int res = 0;
    for (int i = 1; i <= cnt; i++)
        res += dd[i].second/x;
    return res >= n;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    sort(a+1, a+m+1);
    dd[1].first = a[1], dd[1].second = 1;
    for (int i = 2; i <= m; i++)
        if (a[i] != dd[cnt].first)
            cnt++, dd[cnt].first = a[i], dd[cnt].second = 1;
        else
            dd[cnt].second++;
    int l = 0, r = 200;
    while (l<=r)
    {
        int mid = (l+r)/2;
        if (check(mid))
            l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
