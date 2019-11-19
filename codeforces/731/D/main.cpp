#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+100;

int n, k;
int l[maxn], t[10*maxn], res = 0;
vector <int> w[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i];
        for (int j = 1; j <= l[i]; j++)
        {
            int x;
            cin >> x;
            w[i].push_back(x);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        int check = 0;
        for (int j = 0; j < min(w[i].size(), w[i-1].size()); j++)
        {
            if (w[i][j] == w[i-1][j])
                continue;
            if (w[i][j] < w[i-1][j])
                res++;
            t[k-w[i][j]+1]--;
            t[k-w[i-1][j]+1]++;
            check = 1;
            break;
        }
        if (!check && l[i-1] > l[i])
            return cout << -1, 0;
    }
    int s = 0;
    for (int i = 0; i < k; i++)
    {
        s += t[i];
        if (s == res)
        {
            return cout << i, 0;
        }
    }
    cout << -1;
    return 0;
}
