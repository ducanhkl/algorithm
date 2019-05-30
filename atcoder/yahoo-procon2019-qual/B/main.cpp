#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, cnt[5];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= 6; i++)
    {
        cin >> x;
        cnt[x]++;
        if (cnt[x] > 2)
            return cout << "NO", 0;
    }
    cout << "YES";
    return 0;
}
