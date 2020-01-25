#include <bits/stdc++.h>

using namespace std;

struct dt
{
    long long x, y;
    int id;
};

const int maxn = 1e4+100;

vector <dt> v1, v2, res;
int n;
dt a[maxn];



bool cmp(const dt &a, const dt &b)
{
    return min(a.x, b.y) < min(a.x, b.y);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x, a[i].id = i;
    for (int i = 1; i <= n; i++)
        cin >> a[i].y;
    for (int i = 1; i <= n; i++)
        if (a[i].x <= a[i].y)
            v1.push_back(a[i]);
        else
            v2.push_back(a[i]);
    sort(v1.begin(), v1.end(), [] (dt x, dt y) {
            return x.x < y.x;
          });
    sort (v2.begin(), v2.end(), [] (dt x,dt y) {
            return x.y > y.y;
          });
    for (auto v : v1)
        res.push_back(v);
    for (auto v : v2)
        res.push_back(v);
    long long bA = 0, bB = 0, fA = 0, fB = 0;
    for (auto v : res)
    {
        bA = fA;
        fA = bA+v.x;
        bB = max(fB, fA);
        fB = bB + v.y;
    }
    cout << fB << endl;
    for (auto v : res)
        cout << v.id << " ";
    return 0;
}
