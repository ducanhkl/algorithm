#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
typedef pair <long long, long long> pii;

int n, p;
int a[maxn];
deque <pii> q;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (p--)
    {
        int l, r;
        cin >> l >> r;
        long long ans = 0, sum = 0;
        for (l++; l <= r; l++)
        {
            int cnt = 1;
            long long val = abs(a[l] - a[l-1]);
            while (q.size() && q.back().first <= val)
            {
                cnt += q.back().second;
                sum -= q.back().first*q.back().second;
                q.pop_back();
            }
            q.push_back({val, cnt});
            sum += val*cnt;
            ans += sum;
        }
        cout << ans << endl;
        q.clear();
    }
    return 0;
}
