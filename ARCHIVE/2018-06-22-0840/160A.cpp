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

int n, x;

int main ()
{
	cin >> n;
	vector<int> v;
	int x;
	int sum = 0;
	while (n--) {
		cin >> x;
		v.pb (x);
		sum += x;
	}
	sort (v.begin(), v.end(), greater<int>());


	int aux = 0;
	int cnt = 0;
	sum/=2;
	for (int p : v) {
		if (aux <= sum) {
			cnt++;
			aux += p;
			if (aux > sum) {
				cout << cnt << '\n';
				return 0;
			}
		}
	}
	cout << cnt << '\n';

	return 0;
}
