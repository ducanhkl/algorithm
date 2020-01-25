#include <bits/stdc++.h>
#define maxn 300

using namespace std;

int a[maxn][maxn], dd[maxn][maxn];
int n, m;
map <int, int> ans;

int main()
{
    memset(dd, 0, sizeof(dd));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        char x;
        cin >> x;
        a[i][j] = (int)(x-'0');
    }
    for (int j = 1; j <= m; j++)
    {
        for (int i = n; i >= 1; i--)
            if (a[i][j] == 0 && dd[i][j] == 0)
        {
            int res = i;
            dd[res][j] = 1;
            while (a[res-1][j] == 0 && res>1)
                res --, dd[res][j] = 1;
            ans[i-res+1]++;
        }
    }
    for (map<int, int>::iterator it = ans.begin(); it != ans.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}
