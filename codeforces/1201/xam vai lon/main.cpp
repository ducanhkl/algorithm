#include <bits/stdc++.h>

using namespace std;

int n, b, sum, res, ans;
int a[20], c[20], vt[20];

void backtrack(int k)
{
    if (k > n)
    {
        int res = 0, sum = 0;
        for (int i = 1; i <= n; i++)
            res += a[i]*vt[i],
            sum += c[i]*vt[i];
        if (sum <= b)
            ans = max(ans, res);
        return ;
    }
    vt[k] = 1;
    backtrack(k+1);
    vt[k] = 0;
    backtrack(k+1);
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    backtrack(1);
    cout << ans;
    return 0;
}
