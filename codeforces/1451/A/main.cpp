#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int solve(int n)
{
    priority_queue<pii> q;
    q.push({0, -n});
    while (q.size())
    {
        int u = -q.top().second;
        int w = -q.top().first;
        q.pop();
        if (u == 1)
            return w;
        for (int i = 2; i <= sqrt(u); i++)
        {
            if (u % i == 0)
            {
                q.push({-w-1, -u/i});
                q.push({-w-1, -i});
            }
        }
        q.push({ -w-1, -u+1});
    }
}


int solve1(int n)
{
    if (n == 1)
        return 0;
    int res = INT_MAX;
    for (int i = sqrt(n)+1; i >= 2; i--)
        if (n %i == 0)
    {
        res = min(res, solve(n/i) + 1);
        res = min(res, solve(i) + 1);
    }
    return min(res, solve(n-1)+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        int n;
        cin >> n;
        if (n < 4)
            cout << n-1;
        else
            if (n % 2 == 0)
        {
            cout << 2;
        } else
        {
            cout << 3;
        }
        cout << endl;
    }
    return 0;
}
