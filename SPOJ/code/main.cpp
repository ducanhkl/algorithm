#include <iostream>
#include <stdio.h>

using namespace std;

int n;
int a[1000];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        cout << a[i];
}
