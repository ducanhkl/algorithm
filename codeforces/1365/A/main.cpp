#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100][100];

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        int c[100], r[100];
        memset(c, 0, sizeof(c));
        memset(r, 0, sizeof(r));
        memset(a, 0, sizeof(a));
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 1)
                    c[i] = 1, r[j] = 1;
            }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 0 && c[i] == 0 && r[j] == 0)
            {
                ans++;
                a[i][j] = 1;
                c[i] = 1;
                r[j] = 1;
            }
        }
        if (ans % 2 == 0)
            cout << "Vivek";
        else
            cout << "Ashish";
        cout << endl;
    }
    return 0;
}
