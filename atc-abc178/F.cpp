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

const int N = 2e5 + 10;

int n;
pii a_range[N];
int a[N], b[N], b_shift[N];
int bit[N];

void add(int p, int v) {
	p++;
	while(p < N) {
		bit[p] += v;
		p += p&-p;
	}
}

int sum(int p) {
	p++;
	int sum = 0;
	while(p) {
		sum += bit[p];
		p -= p&-p;
	}
	return sum;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n;
	int lst_val = -1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(lst_val == -1) {
			lst_val = a[i];
			a_range[a[i]].x = i;
		} else if(lst_val != a[i]) {
			a_range[lst_val].y = i;
			lst_val = a[i];
			a_range[a[i]].x = i;
		}
	}
	a_range[a[n-1]].y = n;

	bool easy_ans = true;
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		easy_ans = easy_ans and b[i] != a[i];

		int pos = i;
		if(a_range[b[i]].y) {
			int l = a_range[b[i]].x;
			int r = a_range[b[i]].y-1;
			pii inter = {l-pos, r-pos};
			if(inter.x < 0) inter.x += n;
			if(inter.y < 0) inter.y += n;
			// cout << "i = " << i << ", inter = " << inter.x << ' ' << inter.y << '\n';
			if(inter.x > inter.y) {
				add(0, 1);
				add(inter.y+1, -1);

				add(inter.x, 1);
			} else {
				add(inter.x, 1);
				add(inter.y+1, -1);
			}
		}
	}
	if(easy_ans) {
		cout << "Yes\n";
		for(int i = 0; i < n; i++)
			cout << b[i] << " \n"[i==n-1];
		exit(0);
	}


	// cout << "b_here = ";
	// for(int i = 0; i < n; i++)
	// 	cout << b[i] << " \n"[i==n-1];

	int shift = -1;
	for(int i = 1; i < n; i++) {
		// cout << "i = " << i << ", sum(i) = " << sum(i) << '\n';
		if(sum(i) == 0) {
			shift = n-i;
			break;
		}
	}
	if(shift == -1) {
		cout << "No\n";
		exit(0);
	}
	for(int i = 0; i < n; i++)
		b_shift[i] = b[(i+shift)%n];

	cout << "Yes\n";
	for(int i = 0; i < n; i++)
		cout << b_shift[i] << " \n"[i==n-1];


	return 0;
}
