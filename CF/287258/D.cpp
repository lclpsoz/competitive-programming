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

string alpha = "AHIMOTUVWXY";
int val[400];
ll sz[20];

ll get_pos (string s) {
	// if ()
	ll ret = 0;
	reverse(ALL(s));
	int lst = 0;
	for (char c : s) {
		ret += val[c]*(sz[lst]);
		++lst;
	}
	return ret;
}

string solve (int k, string &s) {
	cerr << "k = " << k << ", s = " << s << '\n';
	k += get_pos(s);
	cerr << "k = " << k << '\n';
	string ret = "";
	while (true) {
		string nxt = "A" + ret;
		cerr << "nxt = " << nxt << '\n';
		if (get_pos(nxt) > k) break;
		ret = nxt;
	}
	for (int i = 0; i < LEN(ret); i++) {
		for (int j = 1; j < LEN(alpha); j++) {
			ret[i] = alpha[j];
			if (get_pos(ret) > k) {
				ret[i] = alpha[j-1];
				break;
			}
		}
	}
	return ret;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	// sz[0] = 1;
	// for (int i = 1; i <= 12; i++)
	// 	sz[i] = sz[i-1]*11;

	for (int i = 0; i < LEN(alpha); i++)
		val[alpha[i]] = i+1;

	// cerr << "HERE!!!\n";

	// cerr << "A:" << get_pos("A") << '\n';
	// cerr << get_pos("Y") << '\n';
	// cerr << get_pos("AA") << '\n';
	// cerr << get_pos("YY") << '\n';
	// cerr << "AAA: " << get_pos("AAA") << '\n';
	// cerr << get_pos("YYY") << '\n';
	// cerr << get_pos("AAAA") << '\n';
	// cerr << get_pos("M") << '\n';
	// cerr << get_pos("AI") << '\n';
	// cerr << get_pos("ATM") << '\n';


	int t;
	cin >> t;
	while (t--) {
		int k;
		string s;
		cin >> k >> s;
		vi num(LEN(s)+15);
		for (int i = LEN(s)-1, j = LEN(num)-1; i >= 0; i--, j--)
			num[j] = val[s[i]];
		// for (int i = 0; i < LEN(num); i++)
		// 	cerr << num[i] << " \n"[i==LEN(num)-1];
		num.back() += k;
		for (int i = LEN(num)-1; i >= 1; i--) {
			if (num[i]) {
				int rest = (num[i])%11;
				if (rest == 0)
					rest = 11;
				num[i-1] += (num[i]-rest)/11;
				num[i] = rest;
			}
		}
		
		// for (int i = 0; i < LEN(num); i++)
		// 	cerr << num[i] << " \n"[i==LEN(num)-1];
		for (int i = 0; i < LEN(num); i++)
			if (num[i])
				cout << alpha[num[i]-1];
		cout << '\n';
	}

	return 0;
}
