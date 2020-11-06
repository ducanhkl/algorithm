#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;

int n;
int a[maxn];

void solve2()
{
    int t = 0;
    sort(a+1, a+n+1, greater<int>());
    for (int i = 1; i <= n; i++)
    {
        if (t + a[i] == 0)
        {
            for (int j = i+1; j <= n; j++)
            {
                if (t+a[j] != 0)
                {
                    swap(a[i], a[j]);
                    break;
                }
            }
        }
        if (t + a[i] == 0)
        {
            cout << "NO" << endl;
            return ;
        }
        t += a[i];
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i]<< " ";
    cout << endl;
}

void solve1()
{
    int t = 0;
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    {
        if (t + a[i] == 0)
        {
            for (int j = i+1; j <= n; j++)
            {
                if (t+a[j] != 0)
                {
                    swap(a[i], a[j]);
                    break;
                }
            }
        }
        if (t + a[i] == 0)
        {
            solve2();
            return ;
        }
        t += a[i];
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i]<< " ";
    cout << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        solve1();
    }
    return 0;
}
