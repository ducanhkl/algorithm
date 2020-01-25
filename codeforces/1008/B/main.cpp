#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

int a[maxn][2], dd[maxn][2];
int n;

int main()
{
    memset(a, 0, sizeof(a));
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i][1] >> a[i][2];
    dd[1][1] = dd[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i][1] <= a[i-1][1])
            dd[i][1] = max(dd[i][1], dd[i-1][1]);
        if (a[i][1] <= a[i-1][2])
            dd[i][1] = max(dd[i][1], dd[i-1][2]);
        if (a[i][2] <= a[i-1][1])
            dd[i][2] = max(dd[i][2], dd[i-1][1]);
        if (a[i][2] <= a[i-1][2])
            dd[i][2] = max(dd[i][2], dd[i-1][2]);
    }
    if (dd[n][1] || dd[n][2])
        cout << "YES";
    else cout << "NO";
    return 0;
}
