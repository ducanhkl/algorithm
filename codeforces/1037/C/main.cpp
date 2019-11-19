#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

char a[maxn], b[maxn];
int n, ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
            ans ++;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == '0' && b[i] == '1' && a[i+1] == '1' && b[i+1] == '0')
        {
            ans --;
            i++;
            continue;
        }
        if (a[i] == '1' && b[i] == '0' && a[i+1] == '0' && b[i+1] == '1')
        {
            ans --;
            i ++;
            continue;
        }
    }
    cout << ans;
    return 0;
}

