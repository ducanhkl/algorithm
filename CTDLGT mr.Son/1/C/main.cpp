#include <bits/stdc++.h>

using namespace std;

int t;
int n, k;
int a[100];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
            cin >> a[i];
        int check = false;
        for (int i = 1; i <= k; i++)
            if (a[i] != n-(k-i))
                check = true;
        if (!check)
        {
            cout << k << endl;
            continue;
        }
        int pos = k;
        while (a[pos] == n-(k-pos))
            pos--;
        int b[100], dd[100] = {0}, ans = 0;
        for (int i = 1;i <= k; i++)
            b[i] = a[i];
        a[pos]++;
        for (int i = pos+1; i <= n; i++)
            a[i] = a[i-1]+1;
        for (int i = 1; i <= k; i++)
            dd[a[i]] = 1;
        for (int i = 1; i <= k; i++)
            if (dd[b[i]] == 0)
                ans ++;
        cout << ans << endl;
    }
    return 0;
}
