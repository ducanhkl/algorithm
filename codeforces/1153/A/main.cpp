#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
int n, t;
pair <int, int> a[maxn];
int ans = INT_MAX, tt = 0;

int main()
{
   // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        int res;
        if (t <= a[i].first)
            res = a[i].first;
        else
            res = ceil((t-a[i].first)*1.0/a[i].second)*a[i].second+a[i].first;
        if (ans > res)
        {
            ans = res;
            tt = i;
        }
    }
    cout << tt;
    return 0;
}
