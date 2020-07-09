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

int n;
map<string, string> mp;
string arr1[] = {"Power", "Time", "Space","Soul", "Reality","Mind"};
string arr2[] = {"purple", "green", "blue", "orange", "red", "yellow"};

int main ()
{
	scanf ("%d", &n);
	string str;
	for (int i = 0; i < 6; i++) {
		mp[arr2[i]] = arr1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> str;
		mp[str] = "";
	}

	printf ("%d\n", 6-n);
	for (auto xx : mp) {
		if (xx.y != "")
			cout << xx.y << '\n';
	}



	return 0;
}
