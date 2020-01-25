#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
pair <int, int> a[2*maxn];
int n, m;
set < pair <int, int> > s;

bool check(int val)
{
    for (int i = 1; i <= m; i++)
    {
        int x = (a[i].first+val)%n;
        int y = (a[i].second+val)%n;
        if (x > y)
            swap(x, y);
        if (s.find((pair<int, int>){x, y}) == s.end())
            return false;
    }
    return true;
}

int main()
{
    //freopen("inp.txt", "r", stdin

    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].first >> a[i].second;
        a[i].first --; a[i].second --;
        if (a[i].first > a[i].second)
            swap(a[i].first, a[i].second);
        s.insert(a[i]);
    }
    for (int i = 1; i < n; i++)
        if (n%i == 0)
    {
        if (check(i))
            return cout << "Yes", 0;
    }
    cout << "No";
    return 0;
}
