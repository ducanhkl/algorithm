#include <bits/stdc++.h>

using namespace std;


const int maxc = 1e9;
const int maxn = 1e5+100;
int n, q;
int a[maxn];

int solve(int num)
{
    deque <int> q;
    int res = maxc;
    for (int i = 1; i <= n; i++)
    {
        while (q.size() && a[q.back()] < a[i])
            q.pop_back();
        while(q.size() && q.front() < i-num+1)
            q.pop_front();
        q.push_back(i);
        if (i >= num)
            res = min(res, a[q.front()]);
    }
    return res;
}


int main()
{
   // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        int d;
        cin >> d;
        cout << solve(d) << endl;
    }
    return 0;
}
