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



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n; cin >> n;
	map<string, int> mp;
	mp["Algebra"] = 0;
	mp["Aritmetica"] = 0;
	mp["Backtracking"] = 0;
	mp["Bigint"] = 0;
	mp["Combinatoria"] = 0;
	mp["Estruturas de Dados"] = 0;
	mp["Geometria"] = 0;
	mp["Ordenacao"] = 0;
	mp["Programacao Dinamica"] = 0;
	mp["SegTrees"] = 0;
	mp["Teoria dos Numeros"] = 0;
	mp["Travessia em Grafos"] = 0;
	cin.ignore();
	while(n--)
	{
		string s;
		getline(cin, s);
		s.push_back(',');
		int t = 0;
		for(int i = 0; i < LEN(s); i++)
			if(s[i] == ',')
			{
				mp[s.substr(t, i - t)]++;
				t = i + 1;
			}
	}
	vector<pair<int, string>> v;
	for(auto [s, c] : mp)
		v.emplace_back(c, s);
	sort(ALL(v));

	int ans = 0;
	for(int i = 0; i < LEN(v); i++)
		if(v[i].first * 4 < 3 * v.back().first) ans++;

	if(!ans) cout << "Tudo em Ribas!" << endl;
	else for(int i = 0; i < ans; i++) cout << "Falta " << v[i].second << "!\n";

	return 0;
}
