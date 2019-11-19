#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e6+100;
int n, ii;
int a[maxn], b[maxn], ans = INT_MAX;

int p2(int x)
{
    int res = 1;
    for (int i = 1; i <= x; i++)
    {
        res = res*2;
        if (res > maxn)
            return maxn;
    }
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> ii;
    ii = ii*8;
    ii = p2(ii/n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort (a+1, a+n+1);
    b[1] = 1;
    int cnt = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i-1])
            b[++cnt] = 1;
        else
            b[cnt] ++;
    b[0] = 0;
    for (int i = 1; i <= cnt; i++)
        b[i] = b[i-1]+b[i];
    for (int i = 1; i <= cnt; i++)
    {
        int p = i + ii-1;
        p = min(p ,n);
        int res = b[cnt] - b[p] + b[i-1];
        if (res < ans)
            ans = res;
    }
    cout << ans;
    return 0;
}
