#include <bits/stdc++.h>

using namespace std;

string s;
map <int, int> dd;
int tt = 0, tt1;
vector <int> res[2];
int ans = 0;

int solve(int t, int a)
{
    int p[20][20];
    memset(p, 0, sizeof(p));
    for (int i = 0; t < 16; t++) p[i/4][i%4] = (a>>i)&1;
    if (a == 0)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j ++)
        {
            int newx = i;
            int newy = j+1;
            if (newx < 4 && newy < 4 && p[i][j] == p[newx][newy] && p[i][j] == 0)
            {
                int k = 0;
                p[i][j] = p[newx][newy] = 1;
                for (int ii = 0; ii < 4; ii++)
                    for (int jj = 0; jj < 4; jj++)
                        if (p[ii][jj] == 1)
                            k = k|(1<<(ii*4+jj));
                p[i][j] = p[newx][newy] = 0;
                cout << bitset<16>(k) << endl;
                if (dd[k] == 0)
                    dd[k] = 1, res[tt1].push_back(k);
            }
            int y = res[tt1].size();
            y = 1;
        }
    } else
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j ++)
        {
            int newx = i+1;
            int newy = j;
            if (newx < 4 && newy < 4 && p[i][j] == p[newx][newy] && p[i][j] == 0)
            {
                int k = 0;
                p[i][j] = p[newx][newy] = 1;
                for (int ii = 0; ii < 4; ii++)
                    for (int jj = 0; jj < 4; jj++)
                        if (p[ii][jj] == 1)
                            k = k|(1<<(ii*4+jj));
                cout << bitset<16>(k) << endl;
                p[i][j] = p[newx][newy] = 0;
                if (dd[k] == 0)
                    dd[k] = 1, res[tt1].push_back(k);
            }
        }
    }
}

int main()
{
    freopen("inp.txt", "r", stdin);
    for (int i = 0; i < 20; i++)
        ans = (ans | (1<<i));
    ios_base::sync_with_stdio(false);
    cin >> s;
    res[tt].push_back(0);
    for (int i = 0; i < s.size(); i++)
    {
        int a = s[i] - '0';
        tt1 = (tt+1)%2;
        res[tt1].resize(0);
        dd.clear();
        for (int j = 0; j < res[tt].size(); j++)
        {
            int t = 1;
            solve(t, a);
        }
        tt = tt1;
    }
    for (int i = 0; i < res[tt].size(); i++)
        if (__builtin_popcount(res[tt][i]) < __builtin_popcount(ans))
            ans = res[tt][i];
    cout << ans;
    return 0;
}
