#include <bits/stdc++.h>
#define maxn 10009
#define maxc 12345678

using namespace std;

typedef pair <int, int> pii;
map <pii, vector<pii> > e;
int n, m, k;
int dd[maxn][maxn], d[maxn][maxn];
pii a[maxn];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct data
{
    int x, y, z;
};

bool operator > (data x, data y)
{
    return x.z > y.z;
}

void input()
{
    memset(d, 0, sizeof(d));
    memset(dd, 0, sizeof(dd));
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> a[i].first >> a[i].second, d[a[i].first][a[i].second] = 1;
    k++;
    a[k].first = n, a[k].second = m;
}

void init()
{
    for (int i = 1; i <= k; i++)
        for (int j = i+1; j <= k; j++)
        {
            pii a1 = (pii){a[i].first, a[j].second};
            pii a2 = (pii){a[j].first, a[i].second};
            e[a[i]].push_back(a1);
            e[a[j]].push_back(a1);
            e[a[i]].push_back(a2);
            e[a[j]].push_back(a2);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dd[i][j] = maxc;
    dd[1][1] = 0;
}


void solve()
{
    init();
    priority_queue <data> q;
    q.push((data){1, 1, 0});
    while (q.size())
    {
        data u = q.top();
        q.pop();
        int x = u.x, y = u.y;
        int w = u.z;
        if (w > dd[x][y])
            continue;
        for (int i = 0; i < 4; i++)
            if (d[x+dx[i]][y+dy[i]])
                q.push((data){x+dx[i], y+dy[i], dd[x+dx[i]][y+dy[i]]});
        if (d[x][y])
        {
            for (int i = 0; i < e[(pii){x,y}].size(); i++)
                {
                    int x1 = e[(pii){x, y}][i].first;
                    int y1 = e[(pii){x, y}][i].second;
                    q.push((data){x1, y1, dd[x1][y1]});
                }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    input();
    solve();
    cout << dd[n][m];
    return 0;
}
