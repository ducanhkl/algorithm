#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100;

int n;
int a[maxn], b[maxn], tree[maxn], pos[maxn];
deque <int> v[maxn];

int update (int x, int value)
{
    for (; x < n; x += x&(-x))
        tree[x] = max(tree[x], value);
}

int get (int x)
{
    int res = 0;
    for (; x; x -= (x&(-x)))
        res = max(res, tree[x]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        bool ans = 1;
        cin >> n;
        for (int i = 0; i  <= n; i++)
            tree[i] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], v[a[i]] = deque<int> ();
        for (int i = 1; i <= n; i++)
            cin >> b[i],
            v[b[i]].push_back(i);
        for (int i = 1; i <= n; i++)
        {
            if (v[a[i]].size() == 0)
                ans = 0;
            else
                pos[i] = v[a[i]].front(),
                v[a[i]].pop_front();
        }
        for (int i = 1; i <= n; i++)
        {
            int p = get(a[i]-1);
            if (p > pos[i])
                ans = 0;
            update(a[i], pos[i]);
        }
        if (ans)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}
