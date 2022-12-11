#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    map<long long, long long> mark, dd;
    map<long long, set<long long>> ask, del;
    int q;
    cin >> q;
    while (q--)
    {
        char s;
        long long x;
        cin >> s >> x;
        mark[0] = 1;
        if (s == '+')
        {
            for (auto k : ask[x])
            {
                del[k].erase(x);
            }
            mark[x] = 1;
        }
        if (s == '-')
        {
            for (auto k : ask[x])
            {
                del[k].insert(x);
            }
            mark[x] = 0;
        }
        if (s == '?')
        {
            long long k = x;
            while (mark[dd[k]])
            {
                ask[dd[k]].insert(k);
                dd[k] += k;
            }
            long long res = dd[k];
            if (!del[k].empty())
            {
                res = min(res, *del[k].begin());
            }
            cout << res << endl;
        }
    }
    return 0;
}
