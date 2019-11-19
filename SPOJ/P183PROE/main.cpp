#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int n, m;
long long sl1[maxn], sl2[maxn], sl3[maxn], sl4[maxn],
            tl1[maxn], tl2[maxn], tl3[maxn], tl4[maxn];
long long res1[maxn], res2[maxn];
int a[maxn];
pair <int, int> b[maxn];

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i].first, b[i].second = i;
}

void reset()
{
    memset(res1, 0, sizeof(res1));
    memset(res2, 0, sizeof(res2));
    memset(sl1, 0, sizeof(sl1));
    memset(sl2, 0, sizeof(sl2));
    memset(sl3, 0, sizeof(sl3));
    memset(sl4, 0, sizeof(sl4));
    memset(tl1, 0, sizeof(tl1));
    memset(tl2, 0, sizeof(tl2));
    memset(tl3, 0, sizeof(tl3));
    memset(tl4, 0, sizeof(tl4));
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        input();
        sort(b+1, b+m+1);
        if (t == 0)
            n = n;
        for (int i = 1; i <= n; i++)
        {
            int pos = lower_bound(b+1, b+m+1, (pair<int, int>){a[i], 0}) - b;
            tl1[pos] = tl1[pos] + i;
            tl2[pos] --;
            tl3[pos] = tl3[pos]-i*a[i];
            tl4[pos] = tl4[pos]+a[i];
            pos--;
            sl1[pos] = sl1[pos] + i*a[i];
            sl2[pos] = sl2[pos] - a[i];
            sl3[pos] = sl3[pos] - i;
            sl4[pos] ++;
        }

        for (int i = m; i >= 1; i--)
        {
            int j = b[i].second;
            sl1[i] += sl1[i+1];
            sl2[i] += sl2[i+1];
            sl3[i] += sl3[i+1];
            sl4[i] += sl4[i+1];
            res1[i] = res1[i+1] + sl1[i] + sl2[i]*j + sl3[i]*b[i].first + sl4[i]*b[i].first*j;
        }
        for (int i = 1; i <= m; i++)
        {
            int j = b[i].second;
            tl1[i] += tl1[i-1];
            tl2[i] += tl2[i-1];
            tl3[i] += tl3[i-1];
            tl4[i] += tl4[i-1];
            res2[i] = res2[i-1] + tl1[i]*b[i].first + tl2[i]*b[i].first*j + tl3[i] + tl4[i]*j;
        }
        cout <<res1[1] + res2[m] << endl;
    }
    return 0;
}
