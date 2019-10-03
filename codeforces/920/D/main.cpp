#include <bits/stdc++.h>

using namespace std;

const int maxn = 5010;

int a[maxn], dp[maxn][maxn], dd[maxn];
int n, k, v;
long long sum = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> v;
    for (int i = 1;  i <= n; i++)
        cin >> a[i], sum += a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            dp[i][j] = (dp[i-1][j] || dp[i-1][(j-a[i]%k+k)%k]);
    if (!dp[n][v%k] || sum < v)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    int val = v%k;
    for (int i = n; i >= 1; i--)
    {
        if (dp[i][val] != dp[i-1][val])
        {
            dd[i] = 1;
            val = (val-a[i]%k+k)%k;
        }
    }
    int p = -1;
    for (int i = 1; i <= n; i++)
        if (dd[i])
    {
        if (p == -1)
            p = i;
        else
        {
            a[p] += a[i];
            if (a[i])
                cout << (a[i]+k-1)/k << " " << i << " " << p << endl;
            a[i] = 0;
        }
    }
    if (p == -1)
        p = n;
    int q = 1;
    if (p == 1)
        q = 2;
    for (int i = 1; i <= n; i++)
        if (!dd[i] && i != q)
    {
        a[q] += a[i];
        if (a[i])
            cout << (a[i]+k-1)/k << " "  << i << " " << q << endl;
        a[i] = 0;
    }
    if (a[p] < v)
        cout << (v-a[p])/k <<  " " << q  << " " << p << endl;;
    if (a[p] > v)
        cout << (a[p]-v)/k <<  " " << p << " " << q << endl;
    return 0;
}
