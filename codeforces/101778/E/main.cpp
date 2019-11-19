#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
typedef pair <int, int> pii;
pii a[maxn], ans;
int n, x, y;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        cin >> n >> x >> y;
        for (int i = 1; i <= n; i++)
            cin >> a[i].first >> a[i].second;
        pii ans = {INT_MAX, INT_MIN};
        for (int i = 1; i <= n; i++)
            if (a[i].second >= y)
                ans = min(ans, a[i]);
        for (int i = 1; i <= n; i++)
            if (ans.first == a[i].first)
                ans = max(ans, a[i]);
        if (ans.first > x || ans.second < y)
            cout << -1;
        else
        {
            for (int i = 1; i <= n; i++)
                if (ans == a[i])
                    {
                        cout << i;
                        break;
                    }
        }
        cout << endl;
    }
    return 0;
}
