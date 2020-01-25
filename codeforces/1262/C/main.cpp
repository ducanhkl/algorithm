#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e3+100;

int n, k;
char a[maxn], s[maxn];
vector < pair <int, int> > ans;

void solve()
{
    ans.resize(0);
    for (int i = 1; i <= n; i++)
        if (s[i] != a[i])
    {
        for (int j = i+1; j <= n; j ++)
        {
            if (s[i] == a[j])
            {
                ans.push_back({i, j});
                for (int k = 1; k <= (j-i+1)/2; k++)
                    swap(a[i+k-1], a[j-k+1]);
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> k;
        for (int i = 1;  i <= n; i++)
            cin >> a[i];
        for (int i = 1; i < k; i++)
        {
            s[2*i-1] = '(';
            s[2*i] = ')';
        }
        for (int i = 2*(k-1)+1; i  <= n; i++)
        {
            if (i - 2*(k-1) > (n-2*(k-1))/2)
                s[i] = ')';
            else
                s[i] = '(';
        }
        solve();
    }
    return 0;
}
