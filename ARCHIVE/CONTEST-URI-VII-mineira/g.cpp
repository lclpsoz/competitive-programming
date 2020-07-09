#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e4;

int n, x, y;
vector<pii> vec;

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d %d", &x, &y);
		vec.pb ({x, y});
	}

	int ans = true;
	sort (vec.begin(), vec.end());
	for (int i = 1; i < n; i++) {
		if (vec[i].y >  vec[i-1].y) {
			ans = false;
			break;
		}
	}

	printf ("%s\n", ans ? "S" : "N");

	return 0;
}
