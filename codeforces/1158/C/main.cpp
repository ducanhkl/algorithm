#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+100;
int nxt[maxn], a[maxn], cur = 0;
int n;

int solve(int pos)
{
    int pos1 = pos;
    while (pos1 > 1 && (nxt[pos1-1] == pos || nxt[pos1-1] == -1))
           pos1 = solve(pos1-1);
    a[pos] = ++cur;
    return pos1;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cur = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> nxt[i];
        if (solve(n+1) != 1)
            cout << -1;
        else
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
}
