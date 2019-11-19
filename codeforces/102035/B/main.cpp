#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+10;
map <int, int> dd;
int n, m;
int a[maxn], b[maxn], ans = 0;

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] %= m;
            dd[a[i]] ++;
        }
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        map<int, int>::iterator it;
        dd[a[b[i]]] --;
        if (dd[a[b[i]]] == 0)
        {
            it = dd.find(a[b[i]]);
            dd.erase(it);
        }
        ans++;
        it = dd.begin();
        cout << it->first << " " << it->second << " " << dd.size() << endl;
        if (dd.size() == it->second)
            break;
    }
    cout << ans;
    return 0;
}
