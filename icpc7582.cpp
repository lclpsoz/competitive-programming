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

using pp = pair<pii, int>;

int n;
vector<int> segs;
vector<pp> segsFixed;

bool operator== (const pii &lhs, const pii &rhs) {
	return lhs.x == rhs.x and lhs.y == rhs.y;
}

pii operator- (const pii &lhs, const pii &rhs) {
	return {lhs.x - rhs.x, lhs.y - rhs.y};
}

int cross (pii a, pii b) {
	return a.x*b.y - a.y*b.x;
}

int getQ (pii a) {
	if (a.x > 0 and a.y >= 0) return 0;
	if (a.x <= 0 and a.y > 0) return 1;
	if (a.x < 0 and a.y <= 0) return 2;
	if (a.x >= 0 and a.y < 0) return 3;
}

int solve (pii ref, int id) {
	sort (segs.begin(), segs.end(), [&] (int lhs, int rhs) {
		pii lv = (lhs < 0 ? make_pair(segsFixed[-lhs].x.x, segsFixed[-lhs].y) : make_pair(segsFixed[lhs].x.y, segsFixed[lhs].y));
		pii rv = (rhs < 0 ? make_pair(segsFixed[-rhs].x.x, segsFixed[-rhs].y) : make_pair(segsFixed[rhs].x.y, segsFixed[rhs].y));

		if (lv == ref) return true;
		if (rv == ref) return false;

		// printf ("lv: %3d %3d | rv: %3d %3d\n", lv.x, lv.y, rv.x, rv.y);

		lv = lv - ref;
		rv = rv - ref;

		int crossV = cross (lv, rv);
		// printf ("%d %d\n", lhs, rhs);
		// printf ("lv: %3d %3d | rv: %3d %3d | cross: %d\n", lv.x, lv.y, rv.x, rv.y, crossV);
		if (crossV < 0) return false;
		else if (crossV > 0) return true;
		else if (crossV == 0) {
			if (getQ (lv) == getQ (rv)) // PARA DESENPATAR É MELHOR PRIMEIRO EU PASSAR PELOS SEGMENTOS
										// COLOCANDO PRIMEIRO O PONTO DE ENTRADA E DEPOIS O PONTO DE SAÍDA,
										// DEPOIS PASSO STABLE_SORT PARA MANTER QUE VOU PROCESSAR PRIMEIRO
										// OS PONTOS DE ENTRADA EM CASO DE EMPATE!!!
				return 
			return getQ (lv) < getQ (rv);
		}
	}	);

	set<int> st;
	int maxi = -1;
	st.insert (id);
	int now = segsFixed[id].x.y - segsFixed[id].x.x;
	// cout << segsFixed[id].x.y << "  " << segsFixed[id].x.x << '\n';
	// cout << "start now: " << now << '\n';
	for (int v : segs) {
		v = abs(v);
		if (v == id or segsFixed[v].y == segsFixed[id].y) continue;
		if (st.count (v)) st.erase (v), now -= (segsFixed[v].x.y - segsFixed[v].x.x);
		else st.insert (v), now += (segsFixed[v].x.y - segsFixed[v].x.x);
		// printf ("%2d -> %d\n", v, now);
		maxi = max (now, maxi);
	}
	// putchar ('\n');

	return maxi;
}

int main () {
	while (scanf ("%d", &n) != EOF) {
		segs.clear();
		segsFixed.clear();
			segsFixed.push_back ({{0, 0}, 0});
		for (int i = 1; i <= n; i++) {
			int x0, x1, y;
			scanf ("%d %d %d", &x0, &x1, &y);
			if (x0 > x1) swap (x0, x1);
			segsFixed.push_back ({{x0, x1}, y});
			segs.push_back (i);	// right point
			segs.push_back (-i); // left point
		}
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			auto p = segsFixed[i];
			int v = solve ({p.x.x, p.y}, i);
			// cout << "i: " << -i << '\t' << v << '\n';
			ans = max (ans, v);

			v = solve ({p.x.y, p.y}, i);
			// cout << "i: " << i << '\t' << v << '\n';
			ans = max (ans, v);
		}
		printf ("%d\n", ans);
	}

	return 0;
}
