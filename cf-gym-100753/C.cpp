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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

using U = __int128_t;

U gcd(U a, U b)
{
	while(a)
	{
		swap(a, b);
		a %= b;
	}
	return b;
}

struct fraction
{
    U num, den;
	fraction()
	{
		num = 0;
		den = 1;
	}

    fraction(U x, U y)
    {
        U g = gcd(x, y);
        num = x / g;
        den = y / g;
        if(den < 0) den = -den, num = -num;
    }
    
	fraction(const fraction& o)
	{
		num = o.num;
		den = o.den;
	}
    
    fraction operator+ (const fraction& o)
    {
        U z = den*(o.den/gcd(den, o.den));
        return fraction(num*(z/den) + o.num*(z/o.den), z);
    }
    
    fraction operator- (const fraction& o)
    {
        U z = den*(o.den/gcd(den, o.den));
        return fraction(num*(z/den) - o.num*(z/o.den), z);
    }

    fraction operator* (const fraction& o)
    {
        return fraction(num*o.num, den*o.den);
    }

    fraction operator/ (const fraction& o)
    {
        return fraction(num*o.den, o.num*den);
    }

	bool operator <= (const fraction& o)
	{
		if(den == o.den) return num <= o.num;
        U z = den*(o.den/gcd(den, o.den));
        return num*(z/den) <= o.num*(z/o.den);
	}
};

ostream& operator<< (ostream& os, fraction p) {
	U a = p.num, b = p.den;
	if(p.num < 0) a = -a;
	string sa, sb;
	while(a) sa.push_back(char('0' + (a % 10))), a /= 10;
	while(b) sb.push_back(char('0' + (b % 10))), b /= 10;
	if(p.num < 0)
		sa.push_back('-');
	reverse(ALL(sa));
	reverse(ALL(sb));
	return os << sa << " / " << sb;
}

using T = fraction;

struct pt {
	T x, y;

	pt operator+ (pt p) {return {x+p.x, y+p.y};}
	pt operator- (pt p) {return {x-p.x, y-p.y};}
	pt operator* (T v) {return {x*v, y*v};}
	pt operator/ (T v) {return {x/v, y/v};}
};


T cross (pt a, pt b) { return a.x*b.y - a.y*b.x; }

ostream& operator<< (ostream& os, pt p) {
	return os << "(" << p.x << ", " << p.y << ")";
}

fraction a;
fraction area_old;
vector<pt> p;
int n;

bool check(fraction s)
{
	fraction area_new = area_old;
	// cout << area_new << endl;

	for(int i = 0; i < n; i++)
	{
		fraction dx = p[(i + 1) % n].x - p[i].x;
		fraction dy = p[(i + 1) % n].y - p[i].y;
		fraction ddx = p[(i - 1 + n) % n].x - p[i].x;
		fraction ddy = p[(i - 1 + n) % n].y - p[i].y;

		pt pt1 = {p[i].x + (dx / s), p[i].y + (dy / s)};
		pt pt2 = {p[i].x + (ddx / s), p[i].y + (ddy / s)};
		pt pt3 = {p[i].x, p[i].y};

		fraction a_now;
		a_now = a_now + cross(pt3, pt1);
		a_now = a_now + cross(pt1, pt2);
		a_now = a_now + cross(pt2, pt3);
		if(a_now.num < 0)
			a_now.num = -a_now.num;
		// a_now.num = abs(a_now.num);
		a_now = a_now * fraction(1, 2);
		area_new = area_new - a_now;
	}

	// cout << s << " -> " << area_new << endl;
	// cout << area_new << " <= " << area_old * a << endl;

	return area_new <= area_old * a;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int asd;
	char dsa;
	int num;
	cin >> asd >> dsa >> num >> n;

	int pot = 1;
	asd = num;
	while(asd) asd /= 10, pot *= 10;
	a = fraction(num, pot);

	// cout << num << " / " << pot << " == ";
	// cout << a << endl;

	for(int i = 0; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		fraction fx(x, 1); 
		fraction fy(y, 1); 
		p.push_back({fx, fy});
		// cout << p.back() << endl;
	}

	for(int i = 0; i < n; i++)
		area_old = area_old + cross(p[i], p[(i + 1) % n]);
	if(area_old.num < 0)
		area_old.num = -area_old.num;
	area_old = area_old * fraction(1, 2);
	// area_old.num = abs(area_old.num);

	// cout << area_old << endl;

	fraction l(2, 1), r(1000, 1);

	for(int i = 0; i < 50; i++)
	{
		fraction mid = (l + r) * fraction(1, 2);
		// cout << mid << " -> ";
		// cout << (ld)mid.num / (ld)mid.den << endl;
		if(check(mid)) l = mid;
		else r = mid;
	}

	cout << fixed << (ld)l.num / (ld)l.den << endl;

	return 0;
}
