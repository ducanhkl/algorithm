#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

struct point
{
	long long x, y;
} p[maxn];

int n, m;

bool
cmp_by_x(point x, point y)
{
	return x.x < y.x;
}

int
ccw(point x, point y, point z)
{
	long long ans = (y.x - x.x) * (z.y - y.y) - (z.x - y.x) * (y.y - x.y);
	return ans > 0;
}

int
cw(point x, point y, point z)
{
	long long ans = (y.x - x.x) * (z.y - y.y) - (z.x - y.x) * (y.y - x.y);
	return ans < 0;
}

vector<point>
get_convex()
{
	sort(p + 1, p + n + 1, cmp_by_x);
	vector<point> result1;
	vector<point> result2;
	result1.push_back(p[1]);
	result2.push_back(p[1]);
	for (int i = 2; i <= n; i++)
	{
		if (i == n || cw(p[1], p[i], p[n]))
		{
			if (result1.size() == 1)
			{
				result1.push_back(p[i]);
			}
			else
			{
				while (result1.size() >= 2 && !cw(result1[result1.size() - 2], result1[result1.size() - 1], p[i]))
				{
					result1.pop_back();
				}
				result1.push_back(p[i]);
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (i == n || ccw(p[1], p[i], p[n]))
		{
			if (result2.size() == 1)
			{
				result2.push_back(p[i]);
			}
			else
			{
				while (result2.size() >= 2 && !ccw(result2[result2.size() - 2], result2[result2.size() - 1], p[i]))
				{
					result2.pop_back();
				}
				result2.push_back(p[i]);
			}
		}
	}

	vector<point> result = result1;
	for (int i = result2.size() - 2; i >= 0; i--)
	{
		result.push_back(result2[i]);
	}
	return result;
}

long long
get_area(vector<point>& vec)
{
	long long area = 0;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		area += vec[i].x * vec[i + 1].y - vec[i].y * vec[i + 1].x;
	}
	return abs(area);
}

long long
get_area(point x, vector<point> vec)
{
	long long area = 0;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		vector<point> tri = { x, vec[i], vec[i + 1], x };
		area += get_area(tri);
	}
	return area;
}

int
main()
{
	//freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	vector<point> convex_set = get_convex();
	long long area1 = get_area(convex_set);
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		point q;
		cin >> q.x >> q.y;
		long long area2 = get_area(q, convex_set);
		if (area2 == area1)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
		cout << endl;
	}
	return 0;
}
