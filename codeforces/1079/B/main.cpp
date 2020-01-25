#include <bits/stdc++.h>

using namespace std;

string s;
int n;
int cnt = 0, sl[50];
pair <int, int> ans = {1000, 1000}, res;
int a[50], p;

bool check()
{
    if (a[1] > 20)
        return false;
    for (int i = 2; i <= p; i++)
        if (abs(a[i] - a[i-1]) > 1 || a[i] > 20)
            return false;
    if (ans < res)
        return false;
    return true;
}

void sinh(int x, int sum)
{
    if (sum == 0)
        return ;
    if (x == p)
    {
        a[p] = sum;
        res.second = *max_element(a+1, a+p+1);
        res.first = p;
        if (!check())
            return;
        for (int i = 1; i <= p; i++)
            sl[i] = a[i];
        ans = res;
        return ;
    }
    for (int i = 1; i <= sum; i++)
    {
        a[x] = i;
        sinh(x+1, sum-i);
    }
    return;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    for (int i = 1; i <= 5; i++)
        {
            p = i;
            sinh(1, n);
        }
    cout << ans.first << " " << ans.second << endl;
    for (int i = 1; i <= ans.first; i++)
        for (int j = 1; j <= ans.second; j++)
    {
        if (j > sl[i])
        {
            cout << "";
            continue;
        }
        cout << s[cnt++];
    }
    return 0;
}
