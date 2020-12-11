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

const int N = 5e6 + 10;

int int_pow(int b, int p) {
	int ret = 1;
	for(int i = 0; i < p; i++) ret *= b;
	return ret;
}

int dp[N];

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);

	int a, k;
	cin >> a >> k;
	string vec = "0";
	set<string> st;
	int qnt = 0;
	int qntAll = 0, qntExtra = 0, qntTrash = 0;
	int acuAll = 0, acuExtra = 0, acuTrash = 0;
	int ans = 0;
	while(LEN(vec) <= k) {
		// cout << LEN(st) << '\n';
		// cout << vec << ' ' << st.count(vec) << '\n';
		bool used = false;
		if(st.count(vec)) {
			// cout << '#';
			// cout << qnt << ' ';
			qnt = 0;
		} else {
			++qnt;
			++qntAll;
			// cout << "all:   " << vec << '\n';
			used = true;
			// cout << '-';
		}
		// cout << (st.count(vec) == 0 ? '-' : '#');
		// if(st.count(vec) == 0) {
		bool st_count = st.count(vec);
		st.insert(vec);
		string ax = vec;
		for(int i = 0; i < 3*k; i++)
			ax += vec;
		bool anew = false;
		for(int i = 0; i < 3*k; i++) {
			string str = ax.substr(0, i+1);
			if(st.count(str) == 0) anew = true;
			st.insert(str);
		}
		if(anew and st_count) {
			qntExtra++;
			// cout << "extra: " << vec << '\n';
			used = true;
		}
		if(!used) {
			// cout << "trash: " << vec << '\n';
			qntTrash++;
		}
		// }
		int p = LEN(vec)-1;
		vec[p]++;
		while(vec[p]-'0' == a) {
			vec[p] = '0';
			if(p--)
				vec[p]++;
			else {
				int n_ax = LEN(vec);
				vec = "0";
				ans += qntAll+qntExtra;
				acuAll += qntAll;
				acuExtra += qntExtra;
				acuTrash += qntTrash;
				cout << "sz = " << n_ax <<'\t'<< "qntAll = " << qntAll
						<< ", qntExtra = " << qntExtra
						<< ", qntTrash = " << qntTrash << '\n';//", ans = " << ans << '\n';
				cout << "\tacuAll = " << acuAll << ", acuExtra = " << acuExtra << ", acuTrash = " << acuTrash << "\n";
				// cout << "\tdp =     " << dp[n_ax] << '\n';
				if(n_ax > 2) {
					for(int i = 1; i*i <= n_ax; i++)
						if(n_ax%i == 0) {
							dp[n_ax]+=dp[i];
							if(i > 1 and n_ax/i != i)
								dp[n_ax] += dp[n_ax/i];
						}
					dp[n_ax] = int_pow(a, n_ax) - dp[n_ax];
					cout << "\tdp =     " << dp[n_ax] << '\n';
				}
					dp[n_ax] = qntExtra + qntAll;
				cout << '\n';
				while(n_ax--) vec += '0';
				// cout << qnt << '\n';
				// cout << qntAll << '\n';
				qnt = qntAll = qntExtra = qntTrash = 0;
				break;
			}
		}
	}

	return 0;
}
