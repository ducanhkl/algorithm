#include <bits/stdc++.h>
#define maxn 200001

using namespace std;
char x;
int a[maxn];
int n = 0, k = 0;
int bb0[maxn], bb1[maxn], b1, b0;
vector <int> ans[maxn];
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    while(cin >> x)
        a[++n] = (int)(x-'0');
    for (int i = 1; i <= n; i++)
        if (a[i] == 1)
        {
            if (b0 == 0)
                return cout << -1, 0;
            bb1[++b1] = bb0[b0--];
            ans[bb1[b1]].push_back(i);
        }
        else {
            if (b1 == 0)
                bb0[++b0] = ++k;
            else bb0[++b0] = bb1[b1--];
            ans[bb0[b0]].push_back(i);
        }
    for (int i = 1; i <= k; i++)
        if (a[ans[i][ans[i].size()-1]] == 1)
            return cout << -1, 0;
    cout << k << endl;
    for (int i = 1; i <= k; i++)
    {
        cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
