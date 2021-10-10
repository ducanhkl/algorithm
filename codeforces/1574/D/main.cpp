#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;

vector<long long> a[maxn];
vector<vector<int>> b;
vector<int> ans;
int n, m;
int mx = 0;

void max_sum(vector<int> &pos)
{
    long long sum = 0;
    for (int i = 0; i < pos.size(); i++)
    {
        int j = pos[i]-1;
        sum += a[i+1][j];
    }
    if (sum > mx)
    {
        mx = sum;
         ans = pos;
    }
}

bool check_exist(vector<int> &pos)
{
    int res =  binary_search(b.begin(), b.end(), pos);
    return res;
}

void solve()
{
    sort(b.begin(), b.end());
    vector<int> first_post;
    for (int i = 1; i <= n; i++)
    {
        first_post.push_back(a[i].size());
    }
    if (!check_exist(first_post))
    {
       max_sum(first_post);
    }
    for (int i = 0; i < m; i++)
    {
        vector<int> pos = b[i];
        for (int j = 0; j < pos.size(); j ++ )
        {
            if (pos[j] <= 1)
            {
                continue;
            }
            pos[j] --;
            if (!check_exist(pos))
            {
                max_sum(pos);
            }
            pos[j] ++;
        }
    }
    for (auto v: ans)
    {
        cout << v << " ";
    }
}

int main()
{
//    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        for (int j = 1; j <= c; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        vector<int> banded_pos;
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            banded_pos.push_back(x);
        }
        b.push_back(banded_pos);
    }
    solve();
    return 0;
}
