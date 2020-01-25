#include <iostream>

using namespace std;


int n;
int a[2000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (a[i]%2==0)
            a[i]--;
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
