#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int n;
char a[maxn], b[maxn];
int ans = 0, dd[20];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n/2; i++)
    {
        dd[1] = a[i];
        dd[2] = a[n-i+1];
        dd[3] = b[i];
        dd[4] = b[n-i+1];
        sort(dd+1, dd+5);
        int t = 1;
        for (int j = 2; j <= 4; j++)
            if (dd[j] != dd[j-1])
                t++;
        if (dd[1] == dd[2] && dd[3] == dd[4])
            continue;
        if (b[i] != b[n-i+1])
        {
            if (t == 2)
                ans += 1;
            if (t == 4)
                ans += 2;
            if (t == 3)
                if (a[i] == b[i] || a[i] == b[n-i+1] || a[n-i+1] == b[i] || a[n-i+1] == b[n-i+1])
                    ans += 1;
                else ans += 2;
        }
        if (b[i] == b[n-i+1])
        {
            if (t >= 3)
                ans += 2;
            if (t == 2)
                ans += 1;
        }
    }
    if (n%2 && a[n/2+1] != b[n/2+1])
        ans++;
    cout << ans;
    return 0;
}
