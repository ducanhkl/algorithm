#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, ans = 0;
int a[maxn];
map <int, int> m1, m2;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            m1[a[i]] ++;
        }
    if (m1[0] > 1)
    {
        cout << "cslnb";
        exit(0);
    }
    int dem = 0;
    for (auto it : m1)
    {
        if (it.second > 1)
            dem++;
        if (it.second > 2)
        {
            cout << "cslnb";
            exit(0);
        }
    }
    if (dem > 1)
    {
        cout << "cslnb";
        exit(0);
    }
    for (int i = 1; i <= n; i++)
    {
        if (m1[a[i]] > 1 && m1[a[i]-1] > 0)
        {
            cout << "cslnb";
            exit(0);
        }
    }
    sort (a+1, a+n+1);
    for (int i = 1; i <= n; i++)
        ans = (ans + abs(a[i] - i + 1))%2;
    if (ans % 2)
        cout << "sjfnb";
    else
        cout << "cslnb";
    return 0;
}
