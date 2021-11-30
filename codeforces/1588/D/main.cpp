#include <bits/stdc++.h>

using namespace std;

const int maxn = 12;

int n;
string s[maxn];
map<vector<int>, pair<int, string>> dp;


pair <int, string> dfs(vector <int>  state )
{
    if (dp.count(state))
    {
         return dp[state];
    }
    pair<int, string> res = { 0, ""};
    for (int i = 0; i < n; i++)
    {
         if (s[i].length() <= state[i])
         {
             return res;
         }
    }
    vector <int> new_state;
    for (int c = 'A'; c <= 'z'; c ++)
    {
        new_state.clear();
        for (int i = 0; i < n; i++)
        {
            int pos = -1;
            for (int j = state[i]; j < s[i].length(); j++)
            {
                if (s[i][j] == c)
                {
                    pos = j;
                    break;
                }
            }
            if (pos == -1)
                break;
            new_state.push_back(pos + 1);
        }
        if (new_state.size() != n)
            continue;
        auto next_res = dfs(new_state);
        next_res.second = (char)c + next_res.second;
        next_res.first ++;
        res = max(res, next_res);
    }
    return dp[state] = res;
}

void solve()
{
    vector<int> first_state;
    for (int i = 1; i <= n; i++)
    {
        first_state.push_back(0);
    }
    dp.clear();
    auto res = dfs(first_state);
    cout << res.first << endl << res.second << endl;
}

int main()
{
//    freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test --)
    {
        cin  >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        solve();
    }
    return 0;
}
