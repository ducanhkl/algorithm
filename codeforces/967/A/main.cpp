#include <bits/stdc++.h>

using namespace std;


int n, l;
int a[200], dd[10000], truoc[10000], sau[10000];
bool check(int x, int y)
{
    if (abs(x-y) > l)
        return true;
    return false;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    memset(truoc, 0, sizeof(truoc));
    memset(sau, 0, sizeof(sau));
    ios_base::sync_with_stdio(false);
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        int h, m;
        cin >> h >> m;
        dd[h*60+m] = 1;
        a[i] = h*60+m;
    }
    sort(a+1, a+n+1);
    int dem = 0;
    while (dem <= 1440 && dd[dem] == 0)
        truoc[dem] = -1440, dem ++;
    dem = 1440;
    while (dem >= 0 && dd[dem] == 0)
        sau[dem] = 1440, dem--;
    for (int i = 0; i <= 1440; i++)
        if (truoc[i] == 0)
            if (dd[i] == 1)
                truoc[i] = i;
            else truoc[i] = truoc[i-1];
    for (int i = 1440; i >= 0; i--)
        if (sau[i] == 0)
            if (dd[i] == 1)
                sau[i] = i;
            else sau[i] = sau[i+1];
    for (int i = 0; i <= 1440; i++)
        if (check(i, sau[i]) && check(i, truoc[i]))
            {
                cout << i/60 << " " << i%60;
                return 0;
            }
    cout << (a[n] + l +1)/60 << " " << (a[n] + l + 1)%60;
    return 0;
}
