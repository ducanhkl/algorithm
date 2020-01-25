#include <iostream>

using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    if (m == 0 || (m == 1 && n != 0))
        return cout << "NO", 0;
    if (n < m-1)
        return cout << "NO", 0;
    if ((n-m+1)%2 == 0)
        return cout << "YES", 0;
    cout << "NO";
    return 0;
}
