#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    char x;
    int sl1 = 0, sl2 = 0;
    while (cin >> x)
    {
        if (x == 'o')
            sl1 ++;
        else sl2 ++;
    }
    if (sl1 == 0)
        return cout << "YES", 0;
    if (sl2 % sl1 == 0)
        cout << "YES";
    else cout << "NO";
    return 0;
}
