#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n, t;

using T = ld;

struct pt {
	T x, y;

	pt operator+ (pt p) {return {x+p.x, y+p.y};}
	pt operator- (pt p) {return {x-p.x, y-p.y};}
	pt operator* (T v) {return {x*v, y*v};}
	pt operator/ (T v) {return {x/v, y/v};}

	bool operator== (pt p) {return make_pair (x, y) == make_pair (p.x, p.y);}
	bool operator!= (pt p) {return !(operator==(p));}

};

T sq (pt p) {return p.x*p.x + p.y*p.y;}
ld abs (pt p) {return sqrt ((ld)sq (p));}

ostream& operator<< (ostream& os, pt p) {
	return os << "(" << p.x << ", " << p.y << ")";
}

T dot (pt a, pt b) { return a.x*b.x + a.y*b.y; }

ld angle(pt v, pt w) {
	ld cosTheta = dot(v,w) / abs(v) / abs(w);
	return acos(max(-1.0l, min(1.0l, cosTheta)));
}

int main () {
	// printf("%Lf\n", 360 - angle({1, 0}, {-1, -1})*(180/acos(-1.0l)));

	scanf("%d", &n);
	while(n--) {
		ld w, b, d, s;
		scanf("%Lf %Lf %Lf %Lf", &w, &b, &d, &s);
		scanf("%d", &t);
		ll sum = 0;
		while(t--) {
			ld x, y;
			scanf("%Lf %Lf", &x, &y);
			// bullseye
			if(x*x + y*y < b*b) {
				sum += 50;
			}
			else {
				ld ang = angle({1, 0}, {x, y})*(180/acos(-1.0l));
				// printf("%Lf\n", ang);
				if(cmp(y, 0) == -1) {
					ang = 360 - ang;
					// printf("    %Lf\n", ang);
				}
				int sector = floor(ang/(360/w)) + 1;

				// double ring
				if(x*x + y*y < d*d) {
					sum += sector*2;
				}
				// normal
				else if(x*x + y*y < s*s) {
					sum += sector;
				}
			}
		}
		printf("%lld\n", sum);
	}
	

	return 0;
}
