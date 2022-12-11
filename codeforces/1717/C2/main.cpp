#include <iostream>

using namespace std;

const int maxn = 3e5+100;

int a[maxn], b[maxn];
int n;

void check()
{

    a[n+1] = a[1];
    b[n+1] = b[1];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > b[i])
        {
            cout << "NO" << endl;
            return;
        }
        if (a[i] < b[i] && max(a[i+1]+1, b[i+1]+1) < b[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
             cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
             cin >> b[i];
        }
        check();
    }
    return 0;
}
