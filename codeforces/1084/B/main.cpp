#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
const long long mod = 1e9+7;
char s[maxn], a[maxn];
long long ans = 1, cnt = 0;
int dem = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(s, 0, sizeof(s));
    ios_base::sync_with_stdio(false);
    cin >> s+1;
    int n = strlen(s+1);
    for (int i = 1; i <= n; i++)
        if (s[i] == 'a' || s[i] == 'b')
            a[++dem] = s[i];
    for (int i = 1; i <= dem; i++)
        if (a[i] == 'a')
            cnt++;
        else
            ans = (ans*(cnt+1))%mod, cnt = 0;
    ans = (ans*(cnt+1))%mod;
    cout << (ans-1+mod)%mod;
    return 0;
}
