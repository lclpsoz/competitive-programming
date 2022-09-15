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



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		string input, order;
		cin >> input;
		map<char, int> count;

		string s = input;
		reverse(s.begin(), s.end());
		for (char c : s) {
			if (!count[c]) {
				order.push_back(c);
			}
			count[c]++;
		}
		reverse(order.begin(), order.end());

		map<char, int> count_per_section;
		bool has_ans = true;
		int length_original = 0;
		for (int i = LEN(order); has_ans && i >= 1; i--) {
			if (count[order[i-1]]%i != 0)
				has_ans = false;
			count_per_section[order[i-1]] = count[order[i-1]]/i;
			length_original += count_per_section[order[i-1]];
		}
		string original;
		if (has_ans) {
			original = input.substr(0, length_original);
			string generated = original;
			
			string before = original;
			for (char c : order) {
				string now = "";
				for (char c2 : before)
					if (c2 != c)
						now += c2;
				generated += now;
				before = now;
				// cout << generated << '\n';
			}
			has_ans = generated == input;
		}

		if (!has_ans)
			cout << "-1\n";
		else
			cout << original << ' ' << order << '\n';
	}

	return 0;
}
