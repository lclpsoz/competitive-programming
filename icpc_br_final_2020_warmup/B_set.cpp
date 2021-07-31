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

// struct Node {
// 	struct Node *nodes[26];
// 	bool word;
// }

// Node *root_nome = new Node();
// Node *root_provider = new Node();

// bool insert(const string &nome, const string &provider) {
// 	Node *cur = root;
// 	for (int i = 0; i < word.size(); i++) {
// 		cur = cur->nodes[word[i] - 'a'];
// 		if (!cur) {
// 			cur = new Node();
// 		}
// 		if ()
// 	}
// }

long long fhash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;

    long long value = 0;
    long long p_pow = 1;
    for (char c : s) {
        value = (value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }

    return value;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	int ans = 0;
	set<string> st;
	for (int i = 0; i < n; i++) {
		string email;
		cin >> email;

		string nome;
		string provider;
		bool bnome = true;
		bool bprovider = false;
		for (int j = 0; j < email.size(); j++) {
			if (bnome) {
				if (email[j] == '+')
					bnome = false;
				else if (email[j] == '.')
					;
				else if (email[j] == '@') {
					bnome = false;
					bprovider = true;
				} else {
					nome.push_back(email[j]);
				}
			} else if (!bprovider) {
				if (email[j] == '@')
					bprovider = true;
			} else {
				provider.push_back(email[j]);
			}
		}

		
		string filtered_email = nome;
		filtered_email.push_back('@');
		for (char c : provider)
			filtered_email.push_back(c);
		st.insert(filtered_email);
	}
	cout << st.size() << endl;

	return 0;
}
