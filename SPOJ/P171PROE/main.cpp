#include <bits/stdc++.h>
#define maxn 200001

using namespace std;

pair <int, int> a[maxn];
vector <int> t1, t2;
int n, dem = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    a[0].first = 0;
    for (int i = 0; i < n; i++)
    {
        dem += a[i].first;
        if (a[i+1].second == 1)
            t1.push_back(1899-dem);
        else t2.push_back(1899-dem);
    }
    sort(t1.begin(), t1.end(), greater<int>());
    sort(t2.begin(), t2.end());
    if (t2.size() == 0)
        return cout << "Infinity", 0;
    if (t1.size() != 0 && t1[0] >= t2[0])
        return cout << "Impossible", 0;
    cout << t2[0] + a[n].first + dem;
    return 0;
}
