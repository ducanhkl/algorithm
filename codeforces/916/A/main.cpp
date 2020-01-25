#include <bits/stdc++.h>

using namespace std;

int x, hh, mm;
vector <pair<int, int> > v;
int res = INT_MAX;
int calc(int h, int m)
{
    return h*60+m;
}
bool check(int x)
{
    while (x != 0)
    {
        if (x%10 == 7)
            return true;
        x /= 10;
    }
    return false;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> x;
    cin >> hh >> mm;
    for (int i = 0; i < 24; i++)
        for (int j = 0; j <= 59; j++)
            v.push_back({i, j});
    for (int i = 0; i < 24; i++)
        for (int j = 0; j <= 59; j++)
            v.push_back({i, j});
    for (int i = 0; i < (24+1)*(59+1)*2; i++)
        {
            int t = calc(v[i].first, v[i].second);
            int f = v[i].first;
            int s = v[i].second;
            if (abs(t - calc(hh, mm))%x == 0 || abs(calc(hh, mm) + 24*60- t)%x == 0)
                if (check(f) || check(s))
                    {
                        if (calc(hh, mm) - t < 0)
                        {
                            if (abs(calc(hh, mm) + 24*60- t)%x == 0)
                                res = min(res,(calc(hh, mm) + 24*60- t)/x);
                        }
                        else
                            if (abs(t - calc(hh, mm))%x == 0)
                                res = min(res, (calc(hh, mm)-t)/x);
                        if (res == 2)
                            x = x;
                    }

        }
    cout << res;
    return 0;
}
