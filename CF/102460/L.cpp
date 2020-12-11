#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

template <typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp(ld x, ld y = 0, ld tol = EPS)
{
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD)
{
	return (int)(((x % m) + m) % m);
}

template <typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

using T = ll;

struct pt
{
	T x, y;

	pt operator+(pt p) { return {x + p.x, y + p.y}; }
	pt operator-(pt p) { return {x - p.x, y - p.y}; }
	pt operator*(T v) { return {x * v, y * v}; }
	pt operator/(T v) { return {x / v, y / v}; }

	bool operator==(pt p) { return make_pair(x, y) == make_pair(p.x, p.y); }
	bool operator!=(pt p) { return !(operator==(p)); }
};

T sq(pt p) { return p.x * p.x + p.y * p.y; }
ld abs(pt p) { return sqrt((ld)sq(p)); }

ostream &operator<<(ostream &os, pt p)
{
	return os << "(" << p.x << ", " << p.y << ")";
}

T dot(pt a, pt b) { return a.x * b.x + a.y * b.y; }

ld angle(pt a, pt b)
{
	ld cosTheta = dot(a, b) / (abs(a) * abs(b));
	return acos(max((ld)-1.0, min((ld)1.0, cosTheta)));
}

T cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }

// (+, 0, -) -> (left turn, collinear, right turn)
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); }

pt perp(pt a) { return {-a.y, a.x}; }

struct line
{
	pt v;
	T c;
	pt inc;
	pt p, q;

	line(pt _v, T _c) : v(_v), c(_c) {}
	// From a*x + b*y = c
	line(T a, T b, T _c) : v({b, -a}), c(_c) {}
	// Line from point p to q ("line orientation")
	line(pt p, pt q) : v(q - p), c(cross(v, p)), p(p), q(q), inc(bld_inc(p, q)) {}

	pt bld_inc(pt a, pt b)
	{
		if (a.x == b.x)
			return {0, abs(a.y - b.y)};
		if (a.x < b.x)
			swap(a, b);
		return {a.x - b.x, a.y - b.y};
	}

	// T as ll
	T side(pt p) { return cross(v, p) - c; }
	ld dist(pt p) { return abs(side(p)) / abs(v); }
	ld sqDist(pt p) { return (side(p) * side(p)) / (ld)sq(v); }
	line perpThrough(pt p) { return {p, p + perp(v)}; }
	// Compare points by projection on the line:
	bool cmpProj(pt p, pt q) { return dot(v, p) < dot(v, q); }
	line translate(pt t) { return {v, c + cross(v, t)}; }
	// T as ld
	line shiftLeft(ld dist) { return {v, c + dist * abs(v)}; }
	pt proj(pt p) { return p - ((perp(v) * side(v)) / sq(v)); }
	pt refl(pt p) { return p - ((perp(v) * 2 * side(v)) / sq(v)); }
};

bool cmp(pt a, pt b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c)
{
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(pt a, pt b, pt c)
{
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void convex_hull(vector<pt> &a)
{
	if (a.size() == 1)
		return;

	sort(a.begin(), a.end(), &cmp);
	pt p1 = a[0], p2 = a.back();
	vector<pt> up, down;
	up.push_back(p1);
	down.push_back(p1);
	for (int i = 1; i < (int)a.size(); i++)
	{
		if (i == a.size() - 1 || cw(p1, a[i], p2))
		{
			while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
				up.pop_back();
			up.push_back(a[i]);
		}
		if (i == a.size() - 1 || ccw(p1, a[i], p2))
		{
			while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
				down.pop_back();
			down.push_back(a[i]);
		}
	}

	a.clear();
	for (int i = 0; i < (int)up.size(); i++)
		a.push_back(up[i]);
	for (int i = down.size() - 2; i > 0; i--)
		a.push_back(down[i]);
}

int quarter(pt a)
{
	if (a.x >= 0 and a.y >= 0)
		return 1;
	else if (a.x < 0 and a.y >= 0)
		return 2;
	else if (a.x < 0 and a.y < 0)
		return 3;
	return 4;
}
bool cmp_radial(const pt &lhs, const pt &rhs)
{
	if (quarter(lhs) == quarter(rhs))
		return cross(lhs, rhs) > 0;
	return quarter(lhs) < quarter(rhs);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<pt> points;
		while (n--)
		{
			int x, y;
			cin >> x >> y;
			points.push_back({x, y});
		}
		sort(ALL(points), [](const pt &lhs, const pt &rhs) {
			return (lhs.x < rhs.x or (lhs.x == rhs.x and lhs.y < rhs.y));
		});
		points.resize(unique(ALL(points)) - points.begin());

		convex_hull(points);
		n = LEN(points);

		vector<line> lines;
		for (int i = 0; i < n; i++) {
			cout << "  i = " << i << " -> " << points[i].x << ' ' << points[i].y << '\n';
			cout.flush();
			pt back = points[i]-points[(i-1+n)%n];
			pt forw = points[i]-points[(i+1)%n];
			for (int j = i + 2; j < n; j++)
				if(cross(back, points[j]-points[i]) and cross(forw, points[j]-points[i]))
					lines.push_back(line({points[i], points[j]}));
			cout << "aft\n";
			cout.flush();
		}
		if(LEN(lines) == 0) {
			bool same_line = true;
			line line_start = line(points[0], points[1]);
			for (int i = 0; i < n; i++)
				same_line = same_line and (line_start.side(points[i]) == 0);
			if (same_line)
				cout << "0\n";
			else {
				pt a = {-1, -1}, b = {-1, -1}, c;
				for(int i = 0; i < n; i++) {
					cout << "  i = " << i << " -> " << points[i].x << ' ' << points[i].y << '\n';

					pt bef = points[(i-1+n)%n]-points[i];
					pt aft = points[i]-points[(i+1)%n];
					if(cross(bef, aft))
						if(a.x == -1)
							a = points[i];
						else if(b.x == -1)
							b = points[i];
						else {
							c = points[i];
							break;
						}
				}
				// TODO: When a point is inside the convex hull, it may be used as part of a different rectangle (in case n == 3)
				cout << "abs = " << abs(a-b) << '\n';
				cout << "d = " << line(a, b).dist({4, 0}) << '\n';
				ld area = (abs(a-b)*line(a, b).dist(c))/2;
				cout << "n = " << n << '\n';
				cout << fixed << area << '\n';
			}

		} else {
			sort(ALL(lines), [](const line &lhs, const line &rhs) {
				return cmp_radial(lhs.v, rhs.v);
			});
			reverse(ALL(lines));
			int p_pos = 0, p_neg = 0;
			ld v_pos = -1e25, v_neg = -1e25;
			line line_start = lines[0];
			bool same_line = true;
			for (int i = 0; i < n; i++)
			{
				ld d = line_start.dist(points[i]);
				same_line = same_line and (line_start.side(points[i]) == 0);
				if (line_start.side(points[i]) > 0 and fcmp(d, v_pos) >= 0)
				{
					v_pos = d;
					p_pos = i;
				}
				if (line_start.side(points[i]) < 0 and fcmp(d, v_neg) >= 0)
				{
					v_neg = d;
					p_neg = i;
				}
			}
			if (same_line)
				cout << "0\n";
			else
			{
				ld ans = 0;
				for (line l : lines)
				{
					cout << "line: (" << l.p.x << ", " << l.p.y << ") -> (" << l.q.x << ", " << l.q.y << ")\n";
					cout.flush();
					while(l.side(points[p_pos]) <= 0)
						p_pos = (p_pos+1)%n;
					v_pos = l.dist(points[p_pos]);
					pt nxt_pt = points[(p_pos + 1) % n];
					ld d = l.dist(nxt_pt);
					while (l.side(nxt_pt) > 0 and fcmp(d, v_pos) >= 0)
					{
						v_pos = d;
						p_pos = (p_pos + 1) % n;
						nxt_pt = points[(p_pos + 1) % n];
						d = l.dist(nxt_pt);
					}
					cout << "  p_pos = " << p_pos << '\n';
					cout << "  p_neg = " << p_neg << '\n';
					// cout << "  t1 = " << points[p_neg+1].x << points[p_neg+1].y << '\n';
					// cout << "  tt = " << l.side({1, 0}) << '\n';
					cout.flush();

					while(l.side(points[p_neg]) >= 0)
						p_neg = (p_neg+1)%n;
					cout << "  p_neg = " << p_neg << '\n';
					cout.flush();
					v_neg = l.dist(points[p_neg]);
					nxt_pt = points[(p_neg + 1) % n];
					d = l.dist(nxt_pt);
					while (l.side(nxt_pt) < 0 and fcmp(d, v_neg) >= 0)
					{
						v_neg = d;
						p_neg = (p_neg + 1) % n;
						nxt_pt = points[(p_neg + 1) % n];
						d = l.dist(nxt_pt);
					}
					d = abs(l.q - l.p);
					ld area = d * (v_pos + v_neg) / 2;
					cout << "      v_pos = " << v_pos << ", v_neg = " << v_neg << '\n';
					cout << "      p_pos = " << p_pos << ", p_neg = " << p_neg << '\n';
					cout << "      area = " << area << '\n';
					cout.flush();
					ans = max(ans, area);
				}
				cout << "out?\n";
				cout.flush();
				cout << fixed << ans << '\n';
				cout.flush();
			}
		}
	}

	return 0;
}
