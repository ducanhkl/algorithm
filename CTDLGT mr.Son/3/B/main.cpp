#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n;
pair <int, int> a[maxn];

bool cmp(pair <int, int> x, pair <int, int> y)
{
    if (x.second == y.second)
        return x.first < y.first;
    return x.second < y.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].first >> a[i].second;
        sort(a+1, a+n+1, cmp);
        int last = a[1].second, ans = 1;
        for (int i = 2; i <= n; i++)
            if (a[i].first >= last)
        {
            last = a[i].second;
            ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}
