#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int main ()
{
	int x = 5;
	vector<int> vec;
	while (x <= 1e9) {
		vec.pb (x);
		x *= 5;
	}

	int t, n;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		int ans = 0;
		for (int i = 0; i < vec.size(); i++)
			if (vec[i] > n) break;
			else ans += n/vec[i];

		printf ("%d\n", ans);
	}

	return 0;
}
