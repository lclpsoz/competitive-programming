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

#define endl '\n'
string k = ";:-()\\PDC0|8E%X~[]";

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	string s; cin >> s;
	vi cnt(300, 0);
	for(char c : s) cnt[c]++;

	auto check = [&]()
	{
		for(char c : k) if(cnt[int(c)]) return true;
		return false;
	};

	while(check())
	{
		if(cnt[int('[')])
		{
			cout << "[:|||:]" << endl;
			cnt[int('[')] -= 1;
			cnt[int(']')] -= 1;
			cnt[int(':')] -= 2;
			cnt[int('|')] -= 3;
		}
		else if(cnt[int('8')])
		{
			cout << "8-0" << endl;
			cnt[int('8')] -= 1;
			cnt[int('-')] -= 1;
			cnt[int('0')] -= 1;
		}
		else if(cnt[int('~')])
		{
			cout << ":~(" << endl;
			cnt[int(':')] -= 1;
			cnt[int('~')] -= 1;
			cnt[int('(')] -= 1;
		}
		else if(cnt[int('X')])
		{
			cout << ":-X" << endl;
			cnt[int(':')] -= 1;
			cnt[int('-')] -= 1;
			cnt[int('X')] -= 1;
		}
		else if(cnt[int('%')])
		{
			cout << "%0" << endl;
			cnt[int('%')] -= 1;
			cnt[int('0')] -= 1;
		}
		else if(cnt[int('E')])
		{
			cout << ":-E" << endl;
			cnt[int(':')] -= 1;
			cnt[int('-')] -= 1;
			cnt[int('E')] -= 1;
		}
		else if(cnt[int('|')])
		{
			cout << ":-|" << endl;
			cnt[int(':')] -= 1;
			cnt[int('-')] -= 1;
			cnt[int('|')] -= 1;
		}
		else if(cnt[int('0')])
		{
			cout << ":-0" << endl;
			cnt[int(':')] -= 1;
			cnt[int('-')] -= 1;
			cnt[int('0')] -= 1;
		}
		else if(cnt[int('C')])
		{
			cout << ":C" << endl;
			cnt[int(':')] -= 1;
			cnt[int('C')] -= 1;
		}
		else if(cnt[int('D')])
		{
			cout << ":D" << endl;
			cnt[int(':')] -= 1;
			cnt[int('D')] -= 1;
		}
		else if(cnt[int('P')])
		{
			cout << ":-P" << endl;
			cnt[int(':')] -= 1;
			cnt[int('-')] -= 1;
			cnt[int('P')] -= 1;
		}
		else if(cnt[int('\\')])
		{
			cout << ":-\\" << endl;
			cnt[int(':')] -= 1;
			cnt[int('-')] -= 1;
			cnt[int('\\')] -= 1;
		}
		else if(cnt[int(';')])
		{
			cout << ";-";
			cnt[int(';')] -= 1;
			cnt[int('-')] -= 1;
			if(cnt[int('(')]) cnt[int('(')]--, cout << '(' << endl;
			else cnt[int(')')]--, cout << ')' << endl;
		}
		else
		{
			cout << ":";
			cnt[int(':')] -= 1;
			if(cnt[int('(')]) cnt[int('(')]--, cout << '(' << endl;
			else cnt[int(')')]--, cout << ')' << endl;
		}
	}

	cout << "LOL" << endl;

	return 0;
}
