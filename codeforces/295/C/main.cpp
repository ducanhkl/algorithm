#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;


struct data
{
    int x;
    int y;
    int z;
};
int n, k, n1 = 0, n2 = 0;
long long d[60][60][3], f[60][60][3];
long long c[100][100];
queue <data> q;

long long get(int x, int y)
{
    return c[y+1][x+1];
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    memset(f, 0, sizeof(f));
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == 50)
            n1 ++;
        else n2 ++;
    }
    k /= 50;
    c[1][1] = 1;
    for (int i = 2; i < 60; i++)
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
    q.push((data){0, 0, 1});
    d[0][0][1] = f[0][0][1] = 1;
    while (q.size())
    {
        data t = q.front();
        q.pop();
        int x = t.x;
        int y = t.y;
        int z = t.z;
        long long step = f[x][y][z], tmp = d[x][y][z];
        if (z)
            x = n1 - x, y = n2 - y;
        for (int i = 0; i <= x; i++)
            for (int j = (int)(i == 0); j <= y; j++)
        {
            if (i + 2*j > k)
                break;
            int nx, ny, nz;
            if (z)
                nx = n1 - x + i, ny = n2 - y + j;
            else nx = x - i, ny = y - j;
            nz = !z;
            if (f[nx][ny][nz] == 0)
            {
                f[nx][ny][nz] = step+1;
                q.push((data){nx, ny, nz});
            }
            if (f[nx][ny][nz] == step+1)
                d[nx][ny][nz] = (d[nx][ny][nz] + ((tmp*get(i, x)%mod)*get(j, y))%mod)%mod;
        }
    }
    if (f[n1][n2][0] == 0)
        return cout << -1 << " " << 0, 0;
    cout << f[n1][n2][0]-1 << endl << d[n1][n2][0];
    return 0;
}
