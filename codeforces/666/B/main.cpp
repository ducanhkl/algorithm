#include <bits/stdc++.h>
#define maxc 123456789
#define maxn 10005

using namespace std;


int n, m;
vector <int> e[maxn];
int dd[maxn][maxn];
struct data
{
    int val, node;
    data(){};
} from[maxn][5], to[maxn][5];


struct data1
{
    int u, v, x, y, val;
    void out()
    {
        cout << u << " " << v << " " << x << " " << y;// << " " << val;
        return;
    }

};
data1 ans = (data1){0, 0, 0, 0, -maxc};

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                dd[i][j] = 0;
            else dd[i][j] = -maxc;
    for (int i = 1; i <= n; i++)
    {
        from[i][1].val = from[i][2].val = from[i][3].val = from[i][4].val= -maxc;
        to[i][1].val = to[i][2].val = to[i][3].val = to[i][4].val = -maxc;
    }
}

void bfs(int start)
{
    queue < pair<int, long long> > q;
    q.push({0, start});
    while (q.size())
    {
        int v = q.front().second, w = -q.front().first;
        q.pop();
        if (w > dd[start][v])
            continue;
        for (int i = 0; i < e[v].size(); i++)
        {
            int u = e[v][i];
            if (dd[start][u] > dd[start][v] + 1 || dd[start][u] == -maxc)
            {
                dd[start][u] = dd[start][v] + 1;
                q.push({-dd[start][u], u});
            }
        }
    }
    return;
}


void init()
{

    for (int i = 1; i <= n; i++)
        bfs(i);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            int k;
            for (k = 1; k <= 4; k++)
                if (from[i][k].val < dd[j][i])
                    break;
            if (k <= 4)
            {
                for (int t = 4; t >= k+1; t--)
                    from[i][t] = from[i][t-1];
                from[i][k].val = dd[j][i];
                from[i][k].node = j;
            }
            for (k = 1; k <= 4; k++)
                if (to[i][k].val < dd[i][j])
                    break;
            if (k <= 4)
                {
                    for (int t = 4; t >= k+1; t--)
                        to[i][t] = to[i][t-1];
                    to[i][k].val = dd[i][j];
                    to[i][k].node = j;
                }
        }
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    input();
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= 4; k++)
                for (int h = 1; h <= 4; h++)
    {
        int u = from[i][k].node;
        int v = to[j][h].node;
        int res = from[i][k].val + dd[i][j] + to[j][h].val;
        if (u != i && u != j && v != j && v != i && v != u && res > ans.val && res > 0 && i != j)
            ans = (data1){u, i, j, v, res};
    }
    ans.out();
    return 0;
}
