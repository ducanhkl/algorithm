#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

int a[maxn], d[maxn], sl[maxn], dem, n = 0;
char x;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    while (cin >> x)
        a[++n] = (int)(x-'a');
    sort(a+1, a+n+1);
    d[1] = a[1], sl[1] = 1, dem = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i-1])
            dem++, sl[dem] = 1, d[dem] = a[i];
        else sl[dem] ++;
    if (dem > 4)
        return cout << "NO", 0;
    if (dem == 4)
        return cout << "YES", 0;
    if (dem == 3)
    {
        if (sl[1] == 1 && sl[2] == 1 && sl[3] == 1)
            cout << "NO";
        else cout << "YES";
        return 0;
    }
    if (dem == 2)
    {
        if (sl[1] == 1 || sl[2] == 1)
            cout << "NO";
        else cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}
