#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("inp.txt", "r", stdin);
    int n;
    set <int> s;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    while (true)
    {
        int x = *s.rbegin(), t = x;
        while (t != 0 && s.count(t))
            t >>= 1;
        if (t == 0)
            break;
        s.erase(x), s.insert(t);
    }
    for (set<int>::iterator it = s.begin(); it != s.end(); it ++)
        cout << *it << " ";
    return 0;
}
