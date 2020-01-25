#include <bits/stdc++.h>

using namespace std;

int n, cnt[1000005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x] ++;
    }
    int i;
    for (i = 0; i <= 100000; i++)
        if (cnt[i] % 2)
            break;
    if (i > 100000)
        cout << "Agasa";
    else cout << "Conan";
    return 0;
}
