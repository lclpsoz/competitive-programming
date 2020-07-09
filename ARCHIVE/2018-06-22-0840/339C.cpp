#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

string str;
int n;
vector<int> adj;
vector<int> ans;

bool dfs (int v, int bef, int l, int r) {
	if (v == n) return true;
	for (int x : adj)
		if (x != bef)
			if (v%2 == 0 && l+x > r) {
				ans.pb(x);
				if (dfs (v+1, x, l+x, r))
					return true;
				ans.pop_back();
			} else if (v%2 == 1 && r+x > l) {
				ans.pb(x);
				if (dfs (v+1, x, l, r+x))
					return true;
				ans.pop_back();
			}
	return false;
}

int main ()
{
	cin >> str >> n;
	for (int i = 1; i <= 10; i++)
		if (str[i-1] == '1')
			adj.pb (i);

	dfs (0, -1, 0, 0);
	if (ans.size() == n) {
		cout << "YES\n";
		for (int i = 0; i < n; i++)
			cout << ans[i] << ' ';
	}
	else
		cout << "NO";
	putchar ('\n');

	return 0;
}
