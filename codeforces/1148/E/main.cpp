#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, long long> pii;
const int maxn = 3e5+100;
int n;
pii s[maxn], t[maxn];
vector <pair<pii, int>> ans;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i].first, s[i].second = i;
    for (int i = 1; i <= n; i++)
        cin >> t[i].first, t[i].second = i;
    sort (s+1, s+n+1);
    sort (t+1, t+n+1);
    stack <pii> q;
    for (int i = 1; i <= n; i++)
    {
        int d = t[i].first - s[i].first;
        if (d == 0)
            continue;
        if (d > 0 )
        {
            q.push({d, s[i].second});
        }
        else
        {
            while (d)
            {
                if (q.empty())
                {
                    return cout << "NO", 0;
                }
                int val = q.top().first;
                val = min(val, -d);
                d += val;
                ans.push_back({{q.top().second, s[i].second}, val});
                int p = q.top().first;
                q.top().first -= val;
                if (q.top().first == 0)
                    q.pop();
            }
        }
    }
    if (q.size())
    {
        return cout << "NO", 0;
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    }
    return 0;
}

