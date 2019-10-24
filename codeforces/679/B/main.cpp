#include <bits/stdc++.h>

using namespace std;


long long n;

long long num = 0, ans = 0;

void calc(long long val, int cnt, long long sum)
{
    if (val == 0)
    {
        if (cnt > num)
        {
            num = cnt;
            ans = sum;
        }
        if (cnt == num)
        {
            ans = max(ans, sum);
        }
        return ;
    }
    long long h = 1;
    while (h*h*h <= val)
    {
        h++;
    }
    h --;
    calc(val-h*h*h, cnt+1, sum + h*h*h);
    calc(h*h*h-1-(h-1)*(h-1)*(h-1), cnt+1, sum + (h-1)*(h-1)*(h-1));
    return ;
}

int main()
{
    cin >> n;
    calc(n, 0, 0);
    cout << num << " "<< ans;
    return 0;
}
