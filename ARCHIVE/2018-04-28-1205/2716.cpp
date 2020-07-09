#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

bool verif[MAXN];

int knap (vector<int> values, int n, int m) {
	verif[0] = true;
	int ans = 1e9;
	for (int k : values)
		for (int i = m; i >= 0; i--)
			if (verif[i])
				verif[i+k] = true;

	for (int i = 0; i <= m; i++)
		if (verif[i])
			ans = min (ans, max (abs(i-(m/2)), abs(i-m+(m/2))));

	return ans;
}

int main ()
{
	vector<int> values;
	int n, m, x;
	while (scanf ("%d", &n) != EOF) {
		m = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			values.push_back (x);
			m += x;
		}
		for (int i = 0; i <= m; i++) verif[i] = false;

		printf ("%d\n", knap (values, values.size(), m));
		/*for (int i = 0; i <= m; i++)
			printf ("%02d ", i);
		putchar ('\n');
		for (int i = 0; i <= m; i++)
			printf ("%2d ", verif[i]);
		putchar ('\n');*/

		values.clear ();
	}

	return 0;
}
