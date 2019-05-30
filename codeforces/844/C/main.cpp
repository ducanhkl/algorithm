#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int a[maxn], b[maxn], dd[maxn];
int n, tmp = 0;
vector <int> d[maxn];

void dfs(int i)
{
    if (dd[i] == 1)
        return;
    d[tmp].push_back(i);
    dd[i] = true;
    dfs(a[i]);
}
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(b+1, b+n+1, a[i]) - b;
    memset(dd, 0, sizeof(dd));
    for (int i = 1; i <= n; i++)
        if (!dd[i])
            {
                tmp++;
                dfs(i);
            }
    cout << tmp << endl;
    for (int i = 1; i <= tmp; i++)
    {
        cout << d[i].size() << " ";
        for (int j = 0; j < d[i].size();j++)
            cout <<d[i][j] << " ";
        cout << endl;
    }
    return 0;
}
