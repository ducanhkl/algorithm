#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

map <long long, int> m, sl;
long long n, l[maxn], r[maxn], ans = 0, k;

void tt(int x)
{
    if (sl[x] <= 1)
        sl.erase(x);
    else
        sl[x]--;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    memset(l ,0, sizeof(r));
    memset(r, 0, sizeof(l));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        m[x] = i;
    }
    for (map<long long, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        int x = it->second;
        sl[l[x]+r[x]+1]++;
        l[x+r[x]+1] = r[x-l[x]-1] = l[x]+r[x]+1;
        tt(l[x]), tt[r[x]];
        if (sl.size() == 1 && sl.begin()->second > ans)
        {
            ans = sl.begin()->second;
            k = it->first + 1;
        }
    }
    cout << k;
}
