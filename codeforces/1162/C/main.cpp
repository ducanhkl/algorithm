#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, k, ans;
int dd[maxn], a[maxn];
set < pair <int, int>  > s;

int main()
{
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    ans = (n-1)*2 + n;
    for (int i = k; i >= 1; i--)
    {
        if (dd[a[i]-1])
                s.insert({a[i], a[i] -1});
        if (dd[a[i]+1])
            s.insert({a[i], a[i]+1});
        s.insert({a[i], a[i]});
        dd[a[i]] = 1;
    }
    cout << ans-s.size();
    return 0;
}
