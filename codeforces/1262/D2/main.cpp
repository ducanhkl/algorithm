#include <bits/stdc++.h>

using namespace std;


const int maxn = 3e5+100;

typedef pair <int, int> ii;

struct qr
{
    int k, p, pos;
} qe[maxn];

ii a[maxn];
int tree[maxn], ans[maxn], b[maxn];
int n, m;

void update(int x)
{
    for (; x < maxn; x += (x&(-x)))
        tree[x] ++;
    return ;
}

int get(int x)
{
    int res = 0;
    for (; x > 0; x -= (x&(-x)))
        res += tree[x];
    return res;
}

int numat(int pos)
{
    int l = 0, r = maxn;
    int res = 0;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (get(mid) >= pos)
            res = mid, r = mid -1;
        else
            l = mid + 1;
    }
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        b[i] = a[i].first;
        a[i].second = -i;
    }
    sort (a+1, a+n+1);
    cin >> m;;
    for (int i = 1; i <= m; i++)
    {
        cin >> qe[i].k >> qe[i].p;
        qe[i].pos = i;
    }
    sort(qe+1, qe+m+1, [] (qr x,qr y){
        return x.k < y.k;
    });
    int now = n+1;
    for (int i = 1; i <= m; i++)
    {
        while (now > n-qe[i].k + 1)
        {
            now --;
            update(-a[now].second);
        }
        ans[qe[i].pos] = numat(qe[i].p);
    }
    for (int i = 1; i <= m; i++)
        cout << b[ans[i]] << endl;
    return 0;
}