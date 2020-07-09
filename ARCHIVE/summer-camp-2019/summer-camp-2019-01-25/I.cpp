#include<bits/stdc++.h>
using namespace std;

// -----------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
    return (int)(((x%m) + m)%m);
}
// -----------

using pp = pair<pii, pii>;
const int ST = 0, EN = 1e6, INF = 1e9;

set<pair<pii, pii>> st;

int n, c;

bool comp (pair<pii, pii> &p1, pair<pii, pii> &p2) {
    int mx1 = max (p1.x.y, p1.y.y);
    int mx2 = max (p2.x.y, p2.y.y);
    int mn1 = min (p1.x.y, p1.y.y);
    int mn2 = min (p2.x.y, p2.y.y);
    if (mx1 != mx2)
        return mx1 > mx2;
    return mn1 > mn2;
}

pii qry (int x) {
    auto it = lower_bound (st.begin(), st.end(), make_pair (make_pair(x, 0), make_pair(0, 0)));
	
    if (it->x.x != x)
        --it;
    return it->y;
}

void upd (int l, int r, int x, int h) {
    vector<pair<pii, pii>> toRem;
    pp seg1, seg2;
    seg1 = seg2 = {{-1, -1}, {-1, -1}};
    auto it = lower_bound (st.begin(), st.end(), make_pair(make_pair(l, 0), make_pair(0, 0)));
	
    if (it == st.end() or (it->x.x > l))
        --it;
	
    if (it != st.end() and it->x.x < l and it->x.y >= l)
        seg1 = {{it->x.x, l-1}, it->y};
    while (it != st.end() and it->x.y <= r) {
        toRem.push_back (*it);
        ++it;
    }    
    if (it != st.end() and it->x.x <= r) {
        toRem.push_back (*it);
        if (it->x.y > r)
            seg2 = {{r+1, it->x.y}, it->y};
    }
    for (pp p : toRem)
        st.erase (p);
    st.insert ({{l, r}, {x, h}});
    if (seg1.x.x != -1)
        st.insert (seg1);
    if (seg2.x.x != -1)
        st.insert (seg2);
    
}

int main () {
    while (scanf ("%d %d", &n, &c) != EOF) {
		st.clear();
		st.insert ({{ST, EN}, {INF, INF}});
		vector<pair<pii, pii>> vec;
		for (int i = 0; i < n; i++) {
			int x1, y1, x2, y2;
			scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
			vec.push_back ({{x1, y1}, {x2, y2}});
			if (vec.back().y.x < vec.back().x.x)
				swap (vec.back().x, vec.back().y);
		}
		
		sort (vec.begin(), vec.end(), comp);
		for (auto p : vec) {
			pii p1 = p.x;
			pii p2 = p.y;
			int h;
			int x;
			// Horizontal
			if (p1.y == p2.y) {
				h = p1.y;
				x = INF;
			}
			else if (p1.y > p2.y) {// Desc.
				pii pNow = qry (p1.x);
				h = pNow.y;
				if (pNow.x == INF)
					x = p1.x;
				else
					x = pNow.x;
			}
			else {// Asc.
				pii pNow = qry (p2.x);
				h = pNow.y;
				if (pNow.x == INF)
					x = p2.x;
				else
					x = pNow.x;
			}
			
			upd (p1.x, p2.x, x, h);
		}
		for (int i = 0; i < c; i++) {
			int x;
			scanf ("%d", &x);
			pii p = qry (x);
			
			if (p.x == INF)
				printf ("%d", x);
			else
				printf ("%d", p.x);
			if (p.y != INF)
				printf (" %d", p.y);
			
			putchar ('\n');
		}
	}
    
    return 0;
}
