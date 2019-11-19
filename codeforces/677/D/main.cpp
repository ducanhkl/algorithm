#include <bits/stdc++.h>
#define maxn 500

using namespace std;

struct data
{
    int x, y;
    long long val;
};
int n, m, p, a[maxn][maxn];
vector <data> t[100005];

long long dis(data x, data y)
{
    return abs(x.x - y.x)+abs(x.y-y.y);
}

bool cmp(data x, data y)
{
    return x.val < y.val;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                t[a[i][j]].push_back((data){i, j, INT_MAX});
            }
    t[0].push_back((data){1, 1, 0});
    for (int i = 0; i < p; i ++)
        {
            sort(t[i].begin(), t[i].end(), cmp);
            for (int j = 0; j < min(700, (int)t[i].size()); j++)
                for (int k = 0; k < t[i+1].size(); k++)
                    t[i+1][k].val = min(t[i+1][k].val, t[i][j].val + dis(t[i][j], t[i+1][k]));
        }
    /*for (int i = 1; i <= 12; i++)
        cout << t[i][0].val << " ";*/
    cout << t[p][0].val;
    return 0;
}
