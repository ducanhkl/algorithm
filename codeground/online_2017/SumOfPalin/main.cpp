#include <bits/stdc++.h>
#define maxn 10001


using namespace std;


struct res
{
    int first, second, three;
    res (int x, int y, int z)
    {
        first = x;
        second = y;
        three = z;
    }
    res ()
    {

    }
};

int dd[maxn], t;
vector <int> v;
vector <pair <int, int> > p;
res ans[maxn];


bool palin(int x)
{
    int _x = x, r = 0;
    while (x != 0)
        r = r*10 + x%10, x/= 10;
    return _x == r;
}
void gen()
{
    for (int i = 1; i <= 10000; i++)
        if (palin(i))
            dd[i] = 1;
    for (int i = 1; i <= 10000; i++)
        if (dd[i])
            {
                v.push_back(i);
                ans[i] = res(i, 0, 0);
            }
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v.size(); j++)
            if (v[i]+v[j] <= 10000 && ans[v[i]+v[j]].first == 0)
                {
                    p.push_back({v[i], v[j]});
                    ans[v[i] + v[j]] = res(v[i], v[j], 0);
                }
    //cout << v.size() << " " << p.size() << endl;
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < p.size(); j++)
            if (p[j].first + p[j].second + v[i] <= 10000 && ans[p[j].first + p[j].second + v[i]].first == 0 && ans[p[j].first + p[j].second + v[i]].second == 0)
                ans[p[j].first + p[j].second + v[i]] = res(p[j].first, p[j].second , v[i]);
    //cout << p.size();
    for (int i = 0; i <= 10000; i++)
    {
        if (ans[i].first < ans[i].second)
            swap(ans[i].first, ans[i].second);
        if (ans[i].second < ans[i].three)
            swap(ans[i].second, ans[i].three);
        if (ans[i].first < ans[i].second)
            swap(ans[i].first, ans[i].second);
    }
    return;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    gen();
    cin >> t;
    int C = 1;
    while (t--)
    {
        int n;
        cin >> n;
        cout << "Case #" << C++ << endl;
        cout << (ans[n].first != 0) + (ans[n].second != 0) + (ans[n].three != 0) << " ";
        if (ans[n].first)
            cout << ans[n].first << " ";
        if (ans[n].second)
            cout << ans[n].second << " ";
        if (ans[n].three)
            cout << ans[n].three << " ";
        cout << endl;
    }
    return 0;
}
