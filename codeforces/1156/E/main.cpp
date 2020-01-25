#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;
int n, ans;
int a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i < n; i++)
    {
        if (a[i] < a[i-1] || a[i] < a[i+1])
            continue;
        set <int> s;
        for (int j = i-1; j >= 1 && a[i] > a[j]; j--)
            s.insert(a[j]);
        for (int j = i+1; j <= n && a[i] > a[j]; j++)
            if (s.find(a[i]-a[j]) != s.end())
                ans++;
    }
    cout << ans;
    return 0;
}
