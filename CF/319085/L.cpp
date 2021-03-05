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

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

struct elem {
	elem *n, *p;
	char v;
	bool inv;
	bool updated;
};

struct ls {
	elem *head, *tail;
};

elem *cell, *cur;
ls cells;

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, l, r;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		char v;
		cin >> v;

		elem *cell = (elem *)malloc(sizeof(elem));
		if (cells.head) {
			cell->n = cells.head;
			cell->p = cur;
			cur->n = cell;
		} else {
			cells.head = cell;
			cell->n = cell;
			cell->p = cell;
		}
		cell->v = v;
		cell->inv = false;
		cell->updated = false;

		cur = cell;
	}
	cells.tail = cur;

	elem *L, *R;
	L = R = cells.head;
	for (int i = 0; i < l - 1; i++)
		L = L->n;
	for (int i = 0; i < r - 1; i++)
		R = R->n;

	int m;
	cin >> m;
	cout << m << endl;
	for (int i = 0; i < m; i++) {
		char op;
		cin >> op;
		if (op == 'S') {
			char X, Y;
			cin >> X >> Y;
			if (X == 'L') {
				if (Y == 'L') {
					if (L->inv) {
						L = L->n;
						if (!L->updated) {
							L->updated = false;
						}
					} else {
						L = L->p;
					}
				}
				else
					L = L->n;
			} else if (X == 'R') {
				if (Y == 'L')
					R = R->p;
				else
					R = R->n;
			}
		}
		else if (op == 'R') {
			L->p->n = R;
			L->p = R->n;
			R->p = L->n;
			L->inv = !(R->inv);
			R->inv = !(R->inv);
		} else {
			char X;
			cin >> X;
			if (X == 'L')
				cout << L->v;
			else
				cout << R->v;
		}
	}
	cout << endl;

	return 0;
}
