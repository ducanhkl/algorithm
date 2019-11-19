#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
int cnt1 = 0, cnt2 = 0;
int n;
char a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i-1])
    {
        if (a[i-1] == 'S')
            cnt1 ++;
        else
            cnt2 ++;
    }
    if (cnt1 > cnt2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
