#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

int n, t;
vector<pii> vec;

bool func (const pii &p1, const pii &p2) {
	if (p1.x > p2.x)
		return true;
	return false;
}

int main ()
{
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		int x;
		vec.clear();
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			vec.pb ({x, i});
		}
		sort (vec.begin(), vec.end(), func);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			// printf ("  %d\n", vec[i].x);
			if (vec[i].y == i)
				ans++;
		}
		printf ("%d\n", ans);
	}


	return 0;
}
