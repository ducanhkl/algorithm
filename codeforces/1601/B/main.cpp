#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100;

int trace[maxn], a[maxn], b[maxn];
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    int min_h = n-1;

    for (int i = n; i >= 1; i--)
    {
        int h_after_run = i+b[i];
        while (min_h >= h_after_run-a[h_after_run])
        {
            trace[min_h] = i;
            min_h--;
        }
        if (min_h == i-1)
        {
            cout << -1;
            return 0;
        }
    }

    vector<int> res;
    int root = 0;
    while(root != n)
    {
        res.push_back(root);
        root = trace[root];
    }

    cout << res.size() << endl;
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
