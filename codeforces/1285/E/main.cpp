#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5, maxc = 1e6;

typedef pair <int, int> pii;
vector <pii> v;
set <int> s;
int cnt[maxn], n;


void solve()
{
    int ans = 0, res = -maxc;
    sort (v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        int pos = abs(v[i].second);
        if (v[i].second < 0)
        {
            if (s.size() == 0)
            {
                cnt[pos] --;
            }
            s.insert(pos);
        } else
        {
            s.erase(pos);
            if (s.size() == 0)
            {
                cnt[pos] --;
            }
        }
        if (s.size() == 0)
            ans ++;
        if ((int)(s.size()) == 1)
            cnt[*s.cbegin()] ++;
    }
    for (int i = 1; i <= n; i++)
    {
        res = max(res, cnt[i]);
    }
    cout << ans + res << endl;
}

void init()
{
    v.resize(0);
    s.clear();
    memset(cnt, 0, sizeof(cnt));
}

int main()
{
    ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while  (test--)
    {
        init();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int l, r;
            cin >> l >> r;
            v.push_back({l, -i});
            v.push_back({r, i});
        };
        solve();
    }
    return 0;
}
