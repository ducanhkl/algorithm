#include <iostream>

using namespace std;

const int maxn = 1e5+100;
int b, k, p[maxn];
int an1s = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> b >> k;
    p[0] = 1;
    for (int i = 1; i <= k; i++)
        p[i] = (p[i-1]*b)%2;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        an1s = (an1s + x*p[k-i])%2;
    }
    if (an1s)
        cout << "odd";
    else
        cout << "even";
    return 0;
}
