#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n;
pair <long long, long long> a[maxn];
long long ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    a[0] = {0, 0};
    if (a[1] == make_pair(0LL, 0LL))
        ans = 1;
    for (int i = 1; i <= n; i++)
        {
            if (a[i] == a[i-1])
                continue;
            ans += max(min(a[i].first, a[i].second) - max(a[i-1].first, a[i-1].second)+1, 0LL);
            if (i != 1 && a[i-1].first == a[i-1].second)
                ans --;
        }
    cout << max(ans, 1LL);
    return 0;
}
