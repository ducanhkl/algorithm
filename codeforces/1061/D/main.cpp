#include <bits/stdc++.h>
#define maxn 100006

using namespace std;

int n;
long long x, y, ans = 0, l[maxn], r[maxn];
vector <pair <long long, int> > v;
stack <int> s;
const long long mod = 1e9+7;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        v.push_back({l[i], i});
        v.push_back({r[i]+1, -i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        int id = v[i].second;
        if (id < 0)
        {
            s.push(v[i].first);
            continue;
        }
        while(true)
            {
                if (s.empty())
                {
                    ans = (ans + x + y * (r[id] - l[id])) % mod;
                    break;
                }
                int open = s.top();
                s.pop();
                long long keepCost = y * (v[i].first - open + 1);
                if (keepCost < x)
                {
                    ans = (ans + keepCost + y * (r[id] - l[id])) % mod;
                    break;
                }
            }
    }
    cout << ans%mod;
    return 0;
}
