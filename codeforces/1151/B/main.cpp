#include <bits/stdc++.h>

using namespace std;

const int maxn = 600;
int n, m;
int a[maxn][maxn];
vector <int> v[maxn][3];

void solve()
{
    for (int cnt = 0; cnt <= 10; cnt++)
    {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int i = 1; i <= n; i++)
            v[i][1].resize(0), v[i][2].resize(0);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if ((a[i][j]>>cnt)&1)
                    v[i][1].push_back(j);
                else
                    v[i][2].push_back(j);
        for (int i = 1; i <= n; i++)
        {
            if (v[i][1].size() == 0)
                cnt1++;
            if (v[i][1].size () && v[i][2].size())
                cnt2++;
            if (v[i][1].size() != 0 && v[i][2].size() == 0)
                cnt3++;
        }
        if (cnt3%2)
        {
            cout << "TAK" << endl;
            for (int i = 1; i <= n; i++)
            {
                if (v[i][1].size() && v[i][2].size() == 0)
                    cout << v[i][1][0] << " ";
                else
                    cout << v[i][2][0] << " ";
            }
            exit(0);
        }
        if (cnt3%2 == 0 && cnt2 >= 1)
        {
            cout << "TAK" << endl;
            int check = 1;
            for (int i = 1; i <= n; i++)
            {
                if (v[i][1].size() && v[i][2].size() && check)
                {
                    cout << v[i][1][0] << " ";
                    check = 0;
                    continue;
                }
                if (v[i][1].size() != 0 && v[i][2].size() == 0)
                    cout << v[i][1][0] << " " ;
                else
                    cout << v[i][2][0] << " ";
            }
            exit(0);
        }
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    solve();
    cout << "NIE";
    return 0;
}
