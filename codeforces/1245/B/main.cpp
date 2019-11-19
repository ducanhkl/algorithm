#include <iostream>

using namespace std;


const int maxn = 200;

int a, b, c, n, w;
char ans[maxn], ch[maxn], res[maxn];

void outyes()
{
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = 0;
        if (ch[i] == 'S')
        {
            if (a > 0)
                ans[i] = 'R', a--;
        }
        if (ch[i] == 'R')
        {
            if (b > 0)
                ans[i] = 'P', b--;
        }
        if (ch[i] == 'P')
        {
            if (c > 0)
                ans[i] = 'S', c--;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= a; i++)
        res[++cnt] = 'R';
    for (int i = 1; i <= b; i++)
        res[++cnt] = 'P';
    for (int i = 1; i <= c; i++)
        res[++cnt] = 'S';
    for (int i = 1; i <= n; i++)
        if (ans[i] == 0)
    {
        ans[i] = res[cnt--];
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i];
    cout << endl;
    return ;
}

void solve()
{
    int aa = a, bb = b, cc = c;
    for (int i = 1; i <= n; i++)
    {
        if (ch[i] == 'S')
        {
            if (aa > 0)
                w ++, aa--;
        }
        if (ch[i] == 'R')
        {
            if (bb > 0)
                w++, bb--;
        }
        if (ch[i] == 'P')
        {
            if (cc > 0)
                w++, cc--;
        }
    }
    if (w >= (n+1)/2)
    {
        outyes();
        return;
    }
    cout << "NO" << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test --)
    {
        w = 0;
        cin >> n;
        cin >> a >> b >> c;
        for (int i = 1; i <= n; i++)
        {
            cin >> ch[i];
        }
        solve();
    }
    return 0;
}
