#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 100005

using namespace std;

int a[maxn], n, max1 = 0, max2 = 0, dd[maxn];


int main()
{
    memset(dd, 0, sizeof(dd));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (a[i] > a[max1])
    {
        swap(max2, max1);
        max1 = i;
        dd[i] --;
    }else if (a[i] > a[max2])
    {
        max2 = i;
        dd[max1]++;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++)
        if (dd[ans] < dd[i])
            ans = i;
        else if (dd[ans] == dd[i] && a[ans] > a[i])
            ans = i;
    cout << a[ans];
}
