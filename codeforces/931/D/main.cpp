#include <bits/stdc++.h>

using namespace std;


int n, a[100001];
vector <int> e[100001];

int dfs(int x)
{
    int res = 0;
    if (e[x].size() == 0)
        return 1;
    for (int i  = 0; i < e[x].size(); i++)
        res += dfs(e[x][i]);
    return res%2;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; i++)
        {
            cin >> a[i];
            e[a[i]].push_back(i);
        }
    cout << dfs(1);
    return 0;
}
