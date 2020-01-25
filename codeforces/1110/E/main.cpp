#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;
int n;
int a[maxn], t[maxn], d1[maxn], d2[maxn];

int main()
{
    freopen("inp.txt", "r", stdin);
    a[0] = t[0] = 0;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], d1[i] = a[i] - a[i-1];
    for (int i = 1; i <= n; i++)
        cin >> t[i], d2[i] = t[i] - t[i-1];
    if (a[1] != t[1] || a[n] != t[n])
        return cout << "No", 0;
    sort(d1+1, d1+n+1);
    sort(d2+1, d2+n+1);
    for (int i = 1; i <= n; i++)
        if (d1[i] != d2[i])
            return cout << "No", 0;
    cout << "Yes";
    return 0;
}
