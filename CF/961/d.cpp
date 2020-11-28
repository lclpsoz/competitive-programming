#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

// Only save a line that
// vx and vy are coprimes
// and vx is positive!!!
typedef struct reg2 {
	int ox, oy;
	int vx, vy;
} line;

inline bool operator<(const reg2& lhs, const reg2& rhs)
{
	if (lhs.ox != rhs.ox)
		return lhs.ox < rhs.ox;

	else if (lhs.oy != rhs.oy)
		return lhs.oy < rhs.oy;

	else if (lhs.vx != rhs.vx)
		return lhs.vx < rhs.vx;

	else if (lhs.vy != rhs.vy)
		return lhs.vy < rhs.vy;

	return false;
}

int mdc(int a, int b) {
    if(b == 0) return a;
    return mdc(b, a%b);
}

bool isLine (line l) { return !(l.vx == 0 && l.vy == 0); }

bool in_line (line l, int x, int y);

line new_line (int ox, int oy, int x, int y);

// if line {0,0,0,0}, there's not
// a three point line in points.
line line_3_points (vector<pii> points)
{
	set<line> new_lines;
	int N = points.size();
	line l = {0,0,0,0};
	pii o, t;
	// Just need to test for three points, if none of them
	// are part of a line with three points then there's
	// not that type of line.
	for (int i = 0; !isLine(l) && i < 3; i++) {
		o = points[i];
		for (int j = i+1; j < N; j++) {
			t = points[j];
			line l_n = new_line(o.first, o.second, t.first, t.second);
			// printf ("(%d %d), (%d %d)\n", o.first, o.second, t.first, t.second);
			// printf ("%d %d\n", l_n.vx, l_n.vy);
			if (new_lines.insert (l_n).second == 0) {
				l = l_n;
				break;
			}
		}
	}
	/*for (line ll : new_lines)
		printf (">>%d %d %d %d\n", ll.ox, ll.oy, ll.vx, ll.vy);*/

	return l;
}

int main ()
{
	int n, x, y;
	scanf ("%d", &n);
	if (n < 5)
		printf ("YES\n");
	else {
		vector<pii> points;
		for (int i = 0; i < 5; i++) {
			scanf ("%d %d", &x, &y);
			points.push_back ({x, y});
		}

		line l1 = line_3_points (points);
		// printf ("%d %d\n", l1.vx, l1.vy);
		line l2 = {INT_MAX, INT_MAX, 0, 0};

		if (!isLine (l1))
			printf ("NO\n");
		else {
			bool ans = true;
			for (pii p : points) {
				if (!in_line (l1, p.first, p.second)) {
					if (!isLine (l2)) {
						if (l2.ox == INT_MAX) {
							l2.ox = p.first;
							l2.oy = p.second;
						}
						else
							l2 = new_line (l2.ox, l2.oy, p.first, p.second);
					}
				}
			}
			for (int i = 5; ans && i < n; i++) {
				scanf ("%d %d", &x, &y);
				pii p = {x, y};
				if (!in_line (l1, p.first, p.second)) {
					if (!isLine (l2)) {
						if (l2.ox == INT_MAX) {
							l2.ox = p.first;
							l2.oy = p.second;
						}
						else
							l2 = new_line (l2.ox, l2.oy, p.first, p.second);
					}
					else if (!in_line (l2, x, y))
						ans = false;
				}
			}
			ans ? printf ("YES\n") : printf ("NO\n");
		}
	}

	return 0;
}

bool in_line (line l, int x, int y)
{
	if (l.ox == x && l.oy == y) return true;
	line l2 = new_line (l.ox, l.oy, x, y);
	return (l2.vx == l.vx && l2.vy == l.vy);
}

line new_line (int ox, int oy, int x, int y)
{
	line l = {ox, oy, x-ox, y-oy};
	int d = mdc (abs(l.vx), abs(l.vy));
	l.vx /= d;
	l.vy /= d;
	if (l.vx < 0) {
		l.vx *= -1;
		l.vy *= -1;
	}
	else if (l.vx == 0)
		l.vy = abs(l.vy);
	if (l.vy == 0)
		l.vx = abs(l.vx);
	// printf ("%d %d %d %d\n", l.ox, l.oy, l.vx, l.vy);
	return l;
}
