#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+1000;

vector<vector<int>> init_array(int n, int m)
{
    n++;
    m++;
    vector<vector<int>> a;
    for (int i = 1; i <= n; i++)
    {
        vector<int> b;
        for (int i = 1; i <= m; i++)
        {
            b.resize(m);
        }
        a.push_back(b);
    }
    return a;
}

int cnt[maxn];

void solve()
{
    int n, m;
    cin >> n >> m;
    auto a = init_array(n, m);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            cnt[i] += a[i][j];
            sum += a[i][j];
        }
    }
    if (sum % n)
    {
        cout << -1 << endl;
        return;
    }
    int avg = sum / n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt[i] -= avg;
        ans += (cnt[i]>0)?cnt[i]:0;
    }
    cout << ans << endl;
    int it_positive = 1, it_negative = 1;
    while (it_positive <= n && it_negative <= n)
    {
        while (cnt[it_positive] >= 0 && it_positive  <= n)
        {
            it_positive++;
        }
        while (cnt[it_negative] <= 0 && it_negative <= n)
        {
            it_negative++;
        }
        for (int i = 1; i <= m && it_positive  <= n && it_negative <= n && cnt[it_negative] &&  cnt[it_positive]; i++)
        {
            if (a[it_positive][i] == 0 && a[it_negative][i] == 1)
            {
                cout << it_positive << " " << it_negative  <<  " " << i << endl;
                a[it_positive][i] = 1;
                a[it_negative][i] = 0;
                cnt[it_positive] ++;
                cnt[it_negative] --;
            }
        }
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while(test--)
    {
        solve();
    }
    return 0;
}
