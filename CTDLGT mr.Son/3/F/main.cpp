#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+100;
int n, k;
int a[maxn], last[maxn][15];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        x -= '0';
        a[i] = x;
    }
    for (int i = 0; i <= 9; i++)
        last[n+1][i] = n+1;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= 9; j++)
            last[i][j] = last[i+1][j];
        last[i][a[i]] = i;
    }
    int pos = 1;
    for (int i = n-k; i >= 1; i--)
    {
        for (int j = 9; j >= 0; j--)
            if (n-last[pos][j]+1 >= i)
            {
                cout << j;
                pos = last[pos][j]+1;
                break;
            }
    }
    return 0;
}
