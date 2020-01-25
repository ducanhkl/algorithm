#include <bits/stdc++.h>

using namespace std;

int p[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

void calc(int num, int len, int cnt[])
{s
    int n = num/p[len];
    if (num == 0)
    {
        cnt[n] += len+1;
        return;
    }
    for (int i = 0; i < n; i++)
        cnt[i] += p[len];
    cnt[n] += num%p[len] + 1;
    if (len == 0)
        return;
    for (int i = 0; i < 10; i++)
        cnt[i] += n*len*p[len-1];
    calc(num%p[len], len - 1, cnt);
}
int main()
{
    //freopen("inp.ttx", "r", stdin);
    int a, b;
    while(cin >> a >> b)
    {
        if (a > b)
            swap(a, b);
        if (a == 0 && b == 0)
            exit(0);
        a --;
        int cnt1[11] = {1}, cnt2[11] = {1};
        if (a)
        {
            int p1 = (int)floor(log10(a));
            calc(a, p1, cnt1);
            for (int i = 0; i <= p1; i++)
                cnt1[0] -= p[i];
        }
        int p2 = (int)floor(log10(b));
        calc(b, p2, cnt2);
        for (int i = 0; i <= p2; i++)
            cnt2[0] -= p[i];
        for (int i = 0; i < 10; i++)
            cout << cnt2[i] - cnt1[i] << " ";
        cout << endl;
    }
    return 0;
}
