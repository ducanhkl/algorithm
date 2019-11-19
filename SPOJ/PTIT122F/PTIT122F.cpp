#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

string s, k;
int dem = 0, ans = 0;
ll c, m;
int a[11];
void kt()
{
    int x = 1;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '?')
            k[i] = a[x++]+'0';
        else k[i] = s[i];
    c = 0;
    for (int i = 0; i <s.length(); i++)
        c = c*10 + (k[i]-'0');
    //cout << c << endl;
    if (c > m)
        ans ++;
}
void check(int x)
{
    if (x > dem)
        {
            kt();
            return;
        }
    for (int i = 0; i <= 9; i++)
    {
        a[x] = i;
        check(x+1);
    }
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
    while (cin >> s)
    {
        k = s;
        cin >> m;
        ans = 0;
        dem = 0;
        memset(a, 0, sizeof(a));
        if (s == "#")
            return 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '?')
                dem ++;
        check(1);
        cout << ans << endl;
    }
	return 0;
}
