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

const int N = 7e7, M = 1010;

int t, n, k;
unordered_map<int, int> ans[10];
int bt[10][M];
int pre[N];

void prt(int ax) {
	if(ax <= 9)
		cout << ax << '\n';
	else if(k == 0) {
		if(ax%9) cout << ax%9;
		while(ax >= 9) {
			cout << 9;
			ax-=9;
		}
		cout << '\n';	
	}
	else {
		vector<int> vec;
		vec.push_back(9-k);
		ax -= vec.back();
		while(ax >= 9) {
			vec.push_back(9);
			ax-=9;
		}
		if(ax)
			vec.push_back(ax);
		reverse(vec.begin(), vec.end());
		for(int v : vec)
			cout << v;
		cout << '\n';
	}
}

int sumDig(int x) {
	int ret = 0;
	while(x) {
		ret += x%10;
		x/=10;
	}
	return ret;
}

void brute() {
	memset(bt, -1, sizeof bt);
	for(int i = 0; i < N-10; i++) {
		int acu = pre[i];
		if(bt[0][acu] == -1) bt[0][acu] = i;
		for(int j = 1; j <= 9; j++) {
			acu += pre[i+j];
			if(bt[j][acu] == -1) bt[j][acu] = i;
		}
	}
	for(int i = 0; i < M; i++)
		for(int j = 0; j <= 9; j++)
			if(bt[j][i] != -1)
				ans[j][i] = bt[j][i];
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	for(int i = 0; i < N; i++) pre[i] = sumDig(i);
	brute();
	for(int i = 1; i <= 150; i++)
		for(int j = 1; j <= 9; j++) {
			// cout << "k = " << j << '\n';
			// for(auto p : ans[j])
			// 	cout << p.x << ' ' << p.y << '\n';
			if(ans[j].count(i) == 0) {
				// cout << "n = " << i << ", k = " << j << '\n';
			}
			else {
				cout << "n = " << i << ", k = " << j << ", val = " << ans[j][i] << '\n';
			}
		}
	// cout << LEN(ans) << '\n';
	cin >> t;
	while(t--) {
		cin >> n >> k;
		cout << "n = " << n << ", k = " << k << '\t';
		if(k == 0)
			prt(n);
		else if(ans[k].count(n))
			cout << ans[k][n] << '\n';
		else {
			int pa = (k*(k+1))/2;
			if(pa > n) {
				cout << "-1\n";
			} else if((n-pa)%(k+1) == 0) {
				int ax = (n-pa)/(k+1);
				prt(ax);
			} else if(n-pa >= 100) {
				// cout << "n, pa = " << n << ' ' << pa << '\n';
				int nn = n-pa;
				bool ok = false;
				for(int neg = 1; neg <= k; neg++) {
					if(nn+neg*9 >= 0 and (nn+neg*9)%(k+1)==0) {
						// cout << "h = " << (nn+neg*9) << '\n';
						// cout << "here!\n";
						vector<int> vec;
						vec.push_back(9-(neg-1));
						int ax = (nn+neg*9)/(k+1) - vec.back();
						vec.push_back(ax%9);
						while(ax >= 9) {
							vec.push_back(9);
							ax-=9;
						}
						reverse(vec.begin(), vec.end());
						for(int v : vec)
							cout << v;
						cout << '\n';
						ok = true;
					}
				}
				if(!ok)
					cout << "-1\n";
			} else
				cout << "-1\n";
		}
	}

	return 0;
}
