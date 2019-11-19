#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[200], b[200], dd[1000];

int main()
{
    memset(dd, 0, sizeof(dd));
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            dd[a[i]] = 1;
        }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        dd[b[i]] = 1;
    }
    for (int i = 1; i <= n;  i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int c = a[i] + b[j];
            if (!dd[c])
            {
                cout << a[i] << " " << b[j];
                exit(0);
            }
        }
    }
    return 0;
}
