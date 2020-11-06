#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;
int cnt[maxn], a[maxn];
int cnt2 = 0, cnt4 = 0, cnt6 = 0, cnt8 = 0;
int n;


void inc(int x)
{
    cnt[x] ++;
    if (cnt[x] == 2)
        cnt2++;
    if (cnt[x] == 4)
        cnt4++;
    if (cnt[x] == 6)
        cnt6++;
    if (cnt[x] == 8)
        cnt8++;

}

void dec(int x)
{
    if (cnt[x] == 2)
        cnt2--;
    if (cnt[x] == 4)
        cnt4--;
    if (cnt[x] == 6)
        cnt6--;
    if (cnt[x] == 8)
        cnt8--;
    cnt[x] --;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        inc(a[i]);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
        {
            inc(x);
        } else
        {
            dec(x);
        }
        if (cnt4 >= 1 && cnt2 >= 3)
        {
            cout << "YES" << endl;
            continue;
        }
        if (cnt6 >= 1 && cnt2 >= 2)
        {
            cout << "YES" << endl;
            continue;
        }
        if (cnt4 >= 2)
        {
            cout << "YES" << endl;
            continue;
        }
        if (cnt8 >= 1)
        {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}
