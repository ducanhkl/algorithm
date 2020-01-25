#include <bits/stdc++.h>
#define maxn 1000004

using namespace std;

int a[maxn], b[maxn], c[maxn];
int n, minans = 0, dem = 0, minb = INT_MAX;
map <int, int> m;
bool ck = true;

void add(int x)
{
    int t = sqrt(x);
    for (int i = 1; i < t; i++)
        if (x%i == 0)
            m[i] ++, m[x/i]++;
    if (x%t == 0)
        m[t] ++;
    return ;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i], minb = min(minb, b[i]);
    for (int i = 2; i <= n; i++)
        if (a[i] != b[i])
            ck = false;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b[i])
        {
            minans = max(minans, a[i]);
            continue;
        }
        if (b[i] > a[i]/2)
            return cout << -1, 0;
        c[++dem] = a[i] - b[i];
    }
    if (ck)
        return cout << minans+1, 0;
    for (int i = 1; i <= dem; i++)
        add(c[i]);
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        if (it->second >= dem && it->first >= minans && it->first >= minb)
    {
        cout << it->first;
        return 0;
    }
    cout << -1;
    return 0;
}
