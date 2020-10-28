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



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	string name, st, en;
	getline(cin, name);
	cin >> en >> st;

	int p1 = st.find_first_of('/')+1;
	int p2 = st.find_last_of('/')+1;
	int s[] = {stoi(st.substr(0, 2)), stoi(st.substr(p1, 2)), stoi(st.substr(p2, 4))};

	p1 = en.find_first_of('/')+1;
	p2 = en.find_last_of('/')+1;
	int e[] = {stoi(en.substr(0, 2)), stoi(en.substr(p1, 2)), stoi(en.substr(p2, 4))};

	int age = e[2]-s[2];
	if(s[0] == e[0] and s[1] == e[1])
		cout << "Feliz aniversario!\n";
	else {
		if(e[1] < s[1])
			--age;
		else if(e[1] == s[1] and e[0] < s[0])
			--age;
	}
	cout << "Voce tem " << age << " anos " << name << ".\n";

	return 0;
}
