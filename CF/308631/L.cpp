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

	int n;
	cin >> n;
	vector<vector<string>> commands;
	for (int i = 0; i < n; i++) {
		string op;
		cin >> op;
		// cerr << "op = " << op << '\n';
		string a, b, c;
		a = b = c = '-';
		if (op == "JMP" or op == "PRINT")
			cin >> a;
		else if (op == "MOV")
			cin >> a >> b;
		else
			cin >> a >> b >> c;

		vector<string> now;
		now.push_back(op);
		// cerr << "now[0] = " << now[0] << '\n';
		if (a != "-")
			now.push_back(a);
		if (b != "-")
			now.push_back(b);
		if (c != "-")
			now.push_back(c);
		commands.push_back(now);
	}

	vector<ll> r(10);
	int pos = 0;
	// bool test = ((commands[4] == vector<string>({"ADD", "R0", "R0", "R2"}) or
	// 		(commands[2] == vector<string>({"ADD", "R0", "R1", "R1"})) or
	// 		(commands[2] == vector<string>({"BLT", "R0", "R1", "5"}))));
	// assert (test);
	for (int i = 1; i <= 100000; i++, pos++) {
		// if (commands[4] == vector<string>({"ADD", "R0", "R0", "R2"}))
		// 	break;
		// assert(i < 100000-10);
		// cerr << i << ": " << pos << '\n';
		vector<string> &now = commands[pos];
		string &op = now[0];
		// cerr << "|op = " << op << '\n';
		if (op == "EXIT") {
			assert(LEN(now) == 1);
			exit(0);
		}
		else if (op == "JMP") {
			assert(LEN(now) == 2);
			pos = stoi(now[1])-1;
		}
		else {
			int x = now[1][1]-'0';
			if (op == "PRINT") {
				assert(LEN(now) == 2);
				cout << r[x] << '\n';
			}
			else if (now[2][0] == 'R') {
				int y = now[2][1]-'0';
				if (op == "MOV") {
					assert(LEN(now) == 3);
					r[x] = r[y];
				}
				else if (now[3][0] != 'R') {
					assert(op[0] == 'B');
					assert(LEN(now) == 4);
					int val = stoi(now[3]);
					if (op[1] == 'E') {
						if (r[x] == r[y])
							pos = val-1;
					}
					else if (op[1] == 'L') {
						if (r[x] < r[y])
							pos = val-1;
					}
					else
						assert(false);
				}
				else {
					assert(LEN(now) == 4);
					int z = now[3][1]-'0';
					if (op == "ADD")
						r[x] = r[y] + r[z];
					else if (op == "SUB")
						r[x] = r[y] - r[z];
					else if (op == "MUL")
						r[x] = r[y] * r[z];
					else if (op == "DIV")
						r[x] = r[y] / r[z];
					else if (op == "MOD") {
						r[x] = (((r[y]) % r[z]) + r[z])%r[z];
					}
					else {
						assert(false);
					}
				}
			}
			else {
				// cerr << "MOV VALUE!\n";
				assert(op == "MOV");
				assert(LEN(now) == 3);
				int val = stoi(now[2]);
				r[x] = val;
			}
		}
	}
	cout << "laco infinito!\n";

	return 0;
}
