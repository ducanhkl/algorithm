#include <bits/stdc++.h>
#define maxn 1002

using namespace std;

int ans = INT_MAX, n, a[maxn], d;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int  i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            if (a[j] - a[i] <= d)
                ans = min(ans, i-1+n-j);
    if (ans == INT_MAX)
        cout << n-1;
    else cout << ans;
    return 0;
}
