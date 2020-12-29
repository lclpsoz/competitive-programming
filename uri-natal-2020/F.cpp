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

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

/////////////////////////////////// Date/Time //////////////////////////////////

int mnt[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

struct Date {
	int d, m, y;
	Date () : d(1), m(1), y(1) {}
	Date (int _d, int _m, int _y) : d(_d), m(_m), y(_y) {}
	Date (int days) : d(1), m(1), y(1) { advance (days); }
	bool leap () { return (y%4 == 0 && y%100) || (y%400 == 0); }
	int mdays () { return mnt[m] - mnt[m-1] + (m == 2)*leap(); }
	int ydays () { return 365 + leap(); }
	int count () {
		return (d-1) + mnt[m-1] + (m > 2)*leap() +
			365*(y-1) + (y-1)/4 - (y-1)/100 + (y-1)/400;
	}
	int weekday () { return (count()+1) % 7; }
	void advance (int days) {
		days += count();
		d = m = 1, y = 1 + days/366;
		days -= count();
		while (days >= ydays()) days -= ydays(), y++;
		while (days >= mdays()) days -= mdays(), m++;
		d += days;
	}
};

struct DateTime {
	Date dt;
	ll hr, mi, sec;
	DateTime () : hr(0), mi(0), sec(0) {}
	DateTime (ll _hr, ll _mi, ll _sec) : hr(_hr), mi(_mi), sec(_sec) {}
	DateTime (ll secs) : hr(0), mi(0), sec(0) { advance (secs); }
	ll count () { return 1LL*dt.count()*86400 + hr*3600 + mi*60 + sec; }
	void advance (ll secs) {
		sec += secs;
		mi += sec/60; sec %= 60;
		hr += mi/60; mi %= 60;
		dt.advance (hr/24); hr %= 24;
	}
};

////////////////////////// End of Date/Time. //////////////////////////////

const ld days_in_year = 365.25;

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.precision(10);

	int n;
	cin >> n;
	Date dt(21, 12, 2020);

	int days_jup = n*days_in_year*11.9;
	int days_sat = n*days_in_year*29.6;

	cout << "Dias terrestres para Jupiter = " << days_jup << '\n';
	dt.advance(days_jup);
	cout << "Data terrestre para Jupiter: ";
	printf("%d-%02d-%02d\n", dt.y, dt.m, dt.d);

	cout << "Dias terrestres para Saturno = " << days_sat << '\n';
	dt = Date(21, 12, 2020);
	dt.advance(days_sat);
	cout << "Data terrestre para Saturno: ";
	printf("%d-%02d-%02d\n", dt.y, dt.m, dt.d);

	return 0;
}
