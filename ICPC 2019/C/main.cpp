#include <bits/stdc++.h>

using namespace std;


const int maxn = 20;

int s = -1, c, p1, p2, w = -1;
int n;
char a[maxn];
int dd[maxn];

bool nextper(int num)
{
    int pos = num;
    while (pos > 0 && dd[pos] == 1)
        pos --;
    if (pos == 0)
        return false;
    dd[pos] = 1;
    for (int i = pos+1; i <= num; i++)
        dd[i] = 0;
    return true;
}

void solve2()
{
    if (w != -1 && s > 0 && a[s] == 'E')
        s --;
    if (w != -1 && s > 0 && a[s] == 'N')
        s --;
    int p1 = 0, p2 = 0;
    for (int i = 1; i <= s; i++)
    {
        if (i%2)
        {
            if (a[i] == 'E')
                p1++;
        }
        else
        {
            if (a[i] == 'E')
                p2++;
        }
    }
    for (int i = 0; i <= s; i++)
    {
        int cnt = 0;
        int pp1 = 0, pp2 = 0;
        for (int j = 1; j <= i; j++)
        {
            if (j%2)
            {
                if (a[j] == 'E')
                    pp1++;
            }
            else
            {
                if (a[j] == 'E')
                    pp2++;
            }
        }
        for (int j = 1; j  <= s-i; j++)
            dd[j] = 0;
        do
        {
            int po1 = pp1, po2 = pp2;
            for (int j = 1; j <= s-i; j++)
            {
                if ((i+j)%2)
                {
                    if (dd[j] == 1)
                        po1++;
                } else
                {
                    if (dd[j] == 1)
                        po2++;
                }
            }
            if (po1 == p1 && po2 == p2)
            {
                cnt++;
            }
        } while(nextper(s-i));
        if (cnt == 1)
        {
            c = i;
            break;
        }
    }
    if (c == -1)
    {
        cout << n;
    }
    cout << c << endl;
}

void solve()
{
    s = -1, p1 = 0, p2 = 0, w = -1, c = 0;
    for (int i = 1; i <= 2*n; i++)
    {
        if (i%2)
        {
            if (a[i] == 'E')
                p1++;
        }
        else
        {
            if (a[i] == 'E')
                p2++;
        }
        if (p1 > p2+(2*n-i)/2+i%2)
        {
            w = 0;
            s = i;
            break;
        }
        if (p2 > p1+(2*n-i)/2)
        {
            w = 1;
            s = i;
            break;
        }
    }
    if (s == -1)
    {
        s = n*2;
    }
    cout << s << " ";
    solve2();
}

int main()
{
    freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= 2*n; i++)
            cin >> a[i];
        solve();
    }
    return 0;
}

