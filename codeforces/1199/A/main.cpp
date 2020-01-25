#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;
int n, x, y;
int a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int maxx = INT_MAX;
        for (int j = max(i-x, 1); j < i; j++)
            maxx = min(maxx, a[j]);
        for (int j = i+1; j <= min(n, i+y); j++)
            maxx = min(maxx, a[j]);
        if (maxx > a[i])
        {
            return cout << i, 0;
        }
    }
    return 0;
}
