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
	int n, d, c;
	scanf ("%d", &n);

	int idx;
	double best = -1;
	double now;
	for (int i = 0; i < n; i++) {
		scanf ("%d %d", &d, &c);
		now = c * log (d);
		if (now > best) {
			idx = i;
			best = now;
		}
	}

	printf ("%d\n", idx);

	return 0;
}
