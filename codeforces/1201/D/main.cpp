#include <bits/stdc++.h>

using namespace std;

const long long maxn = 2*1e5+100, maxc = 1e14+100;
map <int, set<int> > t;
int n, m, k, q, cnt;
vector <int> v;
pair <long long, long long> dp[maxn][3];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < maxn; i++)
        dp[i][1] = dp[i][2] = {maxc, maxc};
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; i++)
    {
        int r, c;
        cin >> r >> c;
        t[r].insert(c);
    }
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    t[1].insert(1);
    if (t.size() == 1)
    {
        cout << *t[1].rbegin()-*t[1].begin();
        return 0;
    }
    cnt = 1;
    dp[cnt][2].first = *t[1].rbegin()-*t[1].begin();
    dp[cnt][2].second = *t[1].rbegin();
    dp[cnt][1] = {maxc, maxc};
    map <int, set<int>>::iterator it2 = t.begin();
    for (map <int, set<int>>::iterator it = t.begin(); it != t.end(); it++)
    {
        if (it == t.begin())
            continue;
        cnt++;
        int p[3];
        //cout << it->first  << endl;
        p[1] = *(it->second).begin(), p[2] = *(it->second).rbegin();
        for (int i = 1; i <= 2; i++)
        {
            int pos = lower_bound(v.begin(), v.end(), p[i]) - v.begin();
            //cout << v[pos];
            dp[cnt][i].second = p[i%2+1];
            for (int j = 1; j <= 2; j++, pos--)
            {
                if (pos >= 0 && pos < v.size())
                {
                    int dis = abs(v[pos] - p[i]);
                    int dis1 = abs(v[pos] - dp[cnt-1][1].second);
                    int dis2 = abs(v[pos] - dp[cnt-1][2].second);
                    dp[cnt][i].first = min(dp[cnt][i].first,
                                           min(dis1+dis+dp[cnt-1][1].first, dis2+dis+dp[cnt-1][2].first)+it->first - it2->first+abs(p[1]-p[2]));
                }
            }
        }
        it2++;
    }
    cout << min(dp[cnt][1].first, dp[cnt][2].first);
    return 0;
}
