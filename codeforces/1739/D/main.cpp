#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+10;

vector<int> e[maxn];
int n, k;
int num_cut = 0;

int dfs(int u, int dep, int max_dep)
{
    int res = 0;
    for (auto v : e[u])
    {
        res = max(res, dfs(v, dep+1, max_dep));
    }
    res ++;
    if (res >= max_dep &&  dep > 1)
    {
        res = 0;
        num_cut ++;
    }
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            e[i].resize(0);
        }
        for (int i = 2; i <= n; i++)
        {
            int u;
            cin >> u;
            e[u].push_back(i);
        }
        int res = 0;
        int l = 1, r = n;
        while(l <= r)
        {
            num_cut = 0;
            int mid = (l + r) / 2;
            dfs(1, 0, mid);
            if (num_cut > k)
            {
                l = mid+1;
            }
            else
            {
                res = mid;
                r = mid-1;
            }
        }
        cout << res << endl;
    }
    return 0;
}
