#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

string s, t, p, a= "";
vector <pii> res;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    p = s;
    reverse(p.begin(), p.end());
    int x, y, pos, n = s.size();
    for (int i = 0; i < t.size(); i++)
    {
        a += t[i];
        pos = s.find(a);
        if (pos == -1)
        {
            pos = p.find(a);
        } else
        {
            x = pos+1, y =x+a.size()-1;
            continue;
        }
        if (pos == -1)
        {
            if (a.size() == 1)
                return cout << -1, 0;
            res.push_back({x, y});
            i--;
            a.clear();
        } else
        {
            x = pos+1, y = x+a.size() - 1;
            x = n+1-x,  y = n+1-y;
        }
    }
    res.push_back({x, y});
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i].first << " " << res[i].second << endl;
    return 0;
}
