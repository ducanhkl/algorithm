
#include <bits/stdc++.h>
#define maxn 100004

using namespace std;

int n, x, k, s;
set <int> e[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int t = 1; t <= n; t++)
    {
        int test;
        cin >> test;
        if (test == 1)
        {
            cin >> x;
            for (int i = 1; i <= sqrt(x); i++)
                if (x % i == 0)
                {
                    e[i].insert(x);
                    e[x/i].insert(x);
                }
            continue;
        }
        cin >> x >> k >> s;
        set<int>::iterator it = e[k].upper_bound(s-x);
        /*
        for (set<int>::iterator ii = e[k].begin(); ii != e[k].end(); ii++)
                cout << *ii << endl << " ";
        cout << *it;
        */
        if (x%k)
            {
                cout << -1 << endl;
                continue;
            }
        if (e[k].empty() || it == e[k].begin())
            {
                cout << -1 << endl;
                continue;
            }
        it --;
        int res = -1;
        for (; it != e[k].begin() && res <= *it^x; it --)
            res = max(res, *it^x);
        res = max(res, *it^x);
        cout << (res^x) << endl;
    }
}
