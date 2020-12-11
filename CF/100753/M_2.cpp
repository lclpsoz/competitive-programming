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

const int N = 5e4 + 10, V = 1e6;

bitset<V> msk;
bitset<V> imp;
int a[N];

int mdc(int a, int b) {
	if(b == 0) return a;
	return mdc(b, a%b);
}

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

pii func(int n, bool &found, bool prt = 0) {
	found = 0;
	msk.reset();
	for(int i = 1; i <= n; i++) {
		// cin >> a[i];
		msk[a[i]] = 1;
	}
	int n_imp = min(V, a[1]*a[2]+200);
	// n_imp *= 10;
	for(int p = 0; p < n_imp; p++)
		imp[p] = 1;
	for(int i = 1; i <= n; i++) {
		if(prt)
			cout << "val = " << a[i] << '\n';
		for(int j = 1; j <= V/a[i]+10; j++) {
			if(prt)
				cout << msk << '\n';
			bitset<V> ax = (msk|(msk<<a[i]))&imp;
			if((ax^msk).count() == 0) break;
			msk = ax;
		}
	}
	// cout << msk << '\n';
	int lst = 0;
	for(int i = 0; i < n_imp; i++)
		if(msk[i] == 0)
			lst = i;
	pii ret = {lst, -1};
	int bef = -1;
	for(int i = n_imp-75;; i++) {
		// if(i >= V) {
		// 	cout << "pos = " << i << ": " << a[1] << ", " << a[2] << '\n';
		// }
		if(msk[i] == 1 and bef == -1) bef = i;
		else if(msk[i] == 1 and bef != -1) {
			ret.y = i-bef;
			break;
		}
	}
	bef = -1;
	for(int i = n_imp-1; i >= 1; i--) {
		if(bef == -1 and msk[i]) bef = i;
		else if(bef != -1 and msk[i]) {
			if(bef-i != ret.y) {
				ret.x = bef;
				// cout << "\nfound = " << bef-i << '\n';
				found = true;
				break;
			}
			bef = i;
		}
	}
	return ret;
}

bitset<V> not_prime;
vi primes;

void fat(int x) {
	vi factors, exp;
	for(int v : primes)
		while(x%v == 0) {
			// cout << x << '\n';
			if(LEN(factors) == 0 or factors.back() != v) {
				factors.push_back(v);
				exp.push_back(0);
			}
			exp.back()++;
			x/=v;
		}
	for(int i = 0; i < LEN(factors); i++)
		cout << factors[i] << "^" << exp[i] << " \n"[i==LEN(factors)-1];
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);

	for(int i = 2; i*i < V; i++)
		if(!not_prime[i])
			for(int j = i*i; j < V; j+=i)
				not_prime[j] = 1;
	for(int i = 2; i < V; i++)
		if(!not_prime[i])
			primes.push_back(i);

	// int n;
	// cin >> n;
	// for(int i = 1; i <= n; i++) {
	// 	cin >> a[i];
	// 	msk[a[i]] = 1;
	// }
	// cout << func(2, 1) << '\n';;
	// exit(0);


	// int mx = pow(V, 1/3.0)+1;
	// int mn = pow(mx, 1/3.0)-1;
	// cout << "mn, mx = " << mn << ", " << mx << '\n';
	// for(int i = mn; i < mx; i++) {
	// 	cout << "i = " << i << '\n';
	// 	for(int j = i+1; j < mx; j++) {
	// 		for(int k = j+1; k < mx; k++) {
	// 			if(j%i == 0 and k%i == 0) continue;
	// 			cout << ".";
	// 			// if(j%i == 0 or j-i > sqrt(sqrt(i)+10)) continue;
	// 			a[1] = i, a[2] = j, a[3] = k;
	// 			// cout << i << ", " << j << '\n';
	// 			// cout << i << " " << j << " " << k << ", " << (j-i) << "|" << (k-j) << ", func = " << func(3, 0) << ", mult = " << i*j*k << '\n';
	// 			if(func(3, 0) > i*j*k) {
	// 				cout << i << " " << j << " " << k << ", " << (j-i) << "|" << (k-j) << ", " << func(3, 0) << '\n';
	// 				for(int p = i*j; p < i*j + 20; p++)
	// 					cout << msk[p];
	// 				cout << '\n';
	// 				break;
	// 			}
	// 		}
	// 	}
	// 	cout << '\n';
	// }

	int mx = sqrt(sqrt(V)+10)+1;
	for(int i = 2; i <= sqrt(V); i++) {
		cout << "i = " << i << '\n';
		for(int j = i+1; j <= sqrt(V); j++) {
			if(j-i > mx) continue;
			int md = mdc(i, j);
			int big_val = 1;
			for(int p : primes)
				if(p > md) break;
				else if(md%p == 0) {
					big_val = p;
					break;
				}
			a[1] = i, a[2] = j;
			bool found;
			// auto [start_period, period] = func(2, found);

			int x, y, z;
			// cout << find_any_solution(3, 4, 5, x, y, z) << '\n';
			// cout << x << ", " << y << ", " << z << '\n';
			msk.reset();
			for(int c = 0; c < V; c++) {
				z = c;
				msk[c] = find_all_solutions(i, j, c, 0, 1000000, 0, 1000000) > 0;
				// cout << "c = " << c << ", x = " << x << ", " << y << ", " << z << '\n';
				// msk[c] = z==0;
				// cout << c << ": " << msk[c] << '\n';
			}
			int bef = -1;
			int period = -1, start_period = -1;
			for(int i = V-1; i >= 0;i--) {
				// cout << i << ": " << msk[i] << '\n';
				if(bef == -1 and msk[i]) bef = i;
				else if(bef != -1 and msk[i]) {
					period = bef-i;
					break;
				}
			}
			bef = -1;
			for(int i = V-1; i >= 0;i--)
				if(bef == -1 and msk[i]) bef = i;
				else if(bef != -1 and msk[i]) {
					if(bef-i != period) {
						start_period = bef;
						break;
					}	
					bef = i;
				}

			assert(period == md);
			if(start_period != -1 and md > 1) {
				cout << i << ", " << j << ", start_period = " << start_period << ", mult/md = " << (i*j)/md << ", mdc = " << md << '\n';
				fat(i);
				fat(j);
				fat(start_period+period);
				cout <<'\n';
			}
			if(start_period == -1 and (j-i)%md)
				exit(0);
			assert(start_period == -1 or (i*j)/md > start_period);
			// if(!found) {
			// if(md > 1 and (j-i)%md==0 and start_period < i*j+150)
			// 	exit(0);
			// }
			// if(md != period)
			// 	exit(0);
			// if(start_period > i*j and ((j-i)%big_val) or (start_period < i*j and big_val > 1 and ((j-i)%big_val == 0))) {
			// 	cout << i << ", " << j << ", diff = " << j-i << ", period = " << period << '\n';
			// 	for(int p = i*j; p < i*j + 20; p++)
			// 		cout << msk[p];
			// 	cout << '\n';
			// }
			// cout << i << ", " << j << '\n';
			// if(func(2, 0) > i*j) {
			// 	int dif = j-i;
			// 	bool check = (i%dif or (i/dif)%dif) and (j%dif or (j/dif)%dif);
			// 	cout << (check ? "\t" : "") << i << ' ' << j << ", " << (j-i) << ", " << func(2, 0) << '\n';
			// 	cout << (check ? "\t" : "");
			// 	fat(i);
			// 	cout << (check ? "\t" : "");
			// 	fat(j);
			// 	// dif*=dif;
			// 	cout << (check ? "\t" : "");
			// 	for(int p = i*j; p < i*j + 20; p++)
			// 		cout << msk[p];
			// 	cout << '\n';

			// 	break;
			// }
		}
		cout << '\n';
	}

	// cout << (msk|(msk << 1)) << '\n';

	return 0;
}
