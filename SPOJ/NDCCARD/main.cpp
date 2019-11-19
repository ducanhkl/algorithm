#include <bits/stdc++.h>


using namespace std;

const int maxn = 1e4+100;

int n, m;
int a[maxn], ans;

void solve()
{
    sort(a+1, a+n+1);
    ans = a[1] + a[2] + a[3];
    for (int i = 1; i <= n; i++)
    {
        int sum = m - a[i];
        int j = i-1, k = 1;
        while (k < j)
        {
            while (k < j && a[j] + a[k] > sum)
                j--;
            while (k < j && a[j] + a[k]  <= sum)
            {
                ans = max(ans, a[i] + a[j] + a[k]);
                k ++;
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    solve();
    cout << ans;
    return 0;
}