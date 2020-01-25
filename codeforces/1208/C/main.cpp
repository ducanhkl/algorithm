#include <bits/stdc++.h>

using namespace std;

int n;
int a[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n/2; i++)
        for (int j = 1; j <= n/2; j++)
    {
        a[i][j] = 4*cnt+1;
        a[i][j+n/2] = 4*cnt+2;
        a[i+n/2][j] = 4*cnt+3;
        a[i+n/2][j+n/2] = 4*cnt;
        cnt++;
    }
    for (int i = 1; i <= n; i++, cout << endl)
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
    return 0;
}
